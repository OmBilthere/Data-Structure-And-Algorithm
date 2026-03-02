class DisjointSet {
   vector<int> parent , size;

   public:
   
   DisjointSet(int n ) {
     
     parent.resize( n );
     size.resize( n , 1);

     for(int i=0 ; i< n ; i++ ) 

     parent[i]=i;
    
   }

   int findParent(int node) {


        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);

    }

  void unionBySize(int u , int v) {
     int ul_u = findParent(u);
     int ul_v = findParent(v);

     if(ul_u == ul_v) return;

     else if( size[ul_u] < size[ul_v]) {

        size[ul_v]+=size[ul_u];

        parent[ul_u]= ul_v;
     }

     else {
        size[ul_u] += size[ul_v];

        parent[ul_v] = ul_u;
     }
  }

    
};


class Solution {

public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();

        map<string , int >mpp;

        DisjointSet ds(n);

       for(int i=0 ; i<n; i++) {
          
          for( int j=1; j<accounts[i].size() ; j++)  {

            if(mpp.find(accounts[i][j]) != mpp.end()) {

                int ind = mpp[accounts[i][j]];

                ds.unionBySize(ind , i);
            }
             
             else 

             mpp[accounts[i][j]]= i;

          }
       }
       
       vector<vector<string>>merged(n);

       for(auto it: mpp) {

         int ult_par = ds.findParent(it.second);

         merged[ult_par].push_back(it.first); 

       }

       vector<vector<string>>answer;
       
       for(int i=0; i<n; i++) {
           
           if(merged[i].size()== 0 ) continue;
           
           sort(merged[i].begin() , merged[i].end());

           vector<string>temp;

           temp.push_back(accounts[i][0]);

           for(auto it: merged[i]) 
             
            temp.push_back(it);
           
           answer.push_back(temp);
       }

       return answer;

    }
};