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
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();

        int row = 0;

        int col = 0;

        for(auto it: stones) {
            
            row = max(row , it[0]);

            col = max(col , it[1]);

        }

        DisjointSet ds(row+col+2);

        unordered_map<int,int>mpp;

        for(int i=0 ; i< n ; i++) {

            int x = stones[i][0];

            int y = stones[i][1] + row + 1;

            ds.unionBySize(x ,y);
            
            mpp[x] = 1;

            mpp[y] = 1;
             
        }
      
       int cnt = 0;
     
       for(auto it: mpp) {

         if(ds.findParent(it.first)== it.first)
        
         cnt++;

       }

       
       return n-cnt;
    }
};