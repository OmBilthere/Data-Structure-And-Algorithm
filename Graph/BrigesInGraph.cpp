class Solution {
public:
    
    void dfs( int node , int parent , int & timer , vector<vector<int>>& adj , vector<int> & tin , vector<int>& tmin ,vector<int>& vis, vector<vector<int>> & bridges ) {
       
     vis[node] = 1;

     tin[node] = tmin[node] =  timer++;

     for( auto it: adj[node]) {

        if(it == parent) continue;

        if( !vis[it] ) {

           dfs(it , node , timer , adj , tin , tmin , vis , bridges);

           tmin[node] = min (tmin[node] , tmin[it]);
         
           if(tmin[it]  > tin[node] )

           bridges.push_back({node , it});
        }


        else
        
        tmin[node] = min (tin[it] , tmin[node]);

     }

    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>>adj(n);

        vector<int>tin(n), tmin(n) , vis(n , 0);
        
        vector<vector<int>> bridges;

        for(int i=0 ; i<connections.size() ; i++) {
            
            int u = connections[i][0];

            int v = connections[i][1];

            adj[u].push_back(v);

            adj[v].push_back(u);

        }
        
        int timer = 0; 

        for(int i=0; i<n ; i++) {

            if(!vis[i])

            dfs(i , -1, timer , adj , tin , tmin , vis , bridges);

        }

        return bridges;
    }


};