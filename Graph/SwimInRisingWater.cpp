class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        
        priority_queue< tuple<int,int,int> , vector<tuple<int,int,int>> , greater<>> pq;

        pq.push({grid[0][0] , 0 , 0});

        vector<vector<int>> vis (n , vector<int>(n , 0 ));

        vector<int>dx = { 0 , 0 , 1 , -1 };

        vector<int>dy = { 1 , -1 , 0 , 0 };

        while(!pq.empty()) {
           
           auto [ time , row , col ] = pq.top();

           pq.pop();
          
           if( row == n-1 && col == n-1) return time;

           if(vis[row][col]) continue;

           vis[row][col] = 1;

          

           for(int i = 0 ; i < 4 ; i++ ) {
              
              int x = row+dx[i];

              int y = col + dy[i];

              if( x>=0 && y>=0 && x<n && y<n && !vis[x][y] ) {
                
                int maxHeight = max( time , grid[x][y]);

                pq.push({maxHeight ,  x , y});

              }

           }
        }

        return -1;
    }
};