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

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	
   int indexes = n*m;

	DisjointSet ds(indexes);

   vector<int>answers;

   vector<int>dx = { 0 , -1 , 1 , 0};

   vector<int>dy = { 1 , 0  , 0 ,-1};

   vector<vector<int>>mat(n , vector<int>(m , 0));

   int cnt = 0;

   for(int i=0 ; i<q.size() ; i++ ) {

      int row = q[i][0];

      int col = q[i][1];

      if(mat[row][col]) {

         answers.push_back(cnt);
         
         continue;
      } 

      mat[row][col] = 1;

      cnt++;

      int index1 = (row * m) + col;

      for(int k=0 ; k<4 ; k++) {
        
        int x = row + dx[k];

        int y = col + dy[k];

        if(x>=0 && y>=0 && x<n && y<m ) {

           if(mat[x][y]==1) {
              
              int index2 = (x*m)+y;

              if(ds.findParent(index1) != ds.findParent(index2)) {

              ds.unionBySize(index1 , index2);

              cnt--;

              }


           }

        }

      }
     
     answers.push_back(cnt);
   }
   return answers;
}