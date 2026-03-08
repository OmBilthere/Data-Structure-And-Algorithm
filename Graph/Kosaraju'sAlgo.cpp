class Solution {
  public:
    
    void toposort (int node , vector<vector<int>>& adj , vector<int>& vis , stack<int>& st) {
        
        vis[node] =1;
        
        for(auto it : adj[node]) {
            
            if(!vis[it]) 
                
            toposort (it , adj , vis , st);
                
         
        }  
        
        st.push(node);
    }
    
    void dfs(int node , vector<int> & vis , vector<vector<int>>& rev) {
        
        vis[node] = 1;
        
        for(auto it: rev[node]) {
            
            if(!vis[it])
            
            dfs(it, vis , rev);
        }
    } 
    
    int kosaraju(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>>adj(V);
        
        for(auto it: edges) {
            
            adj[it[0]].push_back(it[1]);
           
        }
        
        vector<int>vis(V , 0);
        
        stack<int>st;
        
        for(int i=0 ; i<V ; i++) {
            
        if(!vis[i])
        
        toposort( i , adj , vis, st);
        
        }
        
        
        vis.assign(V , 0); 
        
        vector<vector<int>>rev(V);
        
        for(int i=0 ; i<V ; i++) {
            
            for(int j=0 ; j< adj[i].size() ; j++) {
                
                int neighbour = adj[i][j];
                
                rev[neighbour].push_back(i);
            }
        }
        
        int cnt = 0;
        
        while(!st.empty()) {
            
            int node = st.top();
            
            st.pop();
            
            if(!vis[node]) {
            
             dfs(node , vis , rev);
            
             cnt++;
            
            }
        
        }
        
        return cnt;
    }
};