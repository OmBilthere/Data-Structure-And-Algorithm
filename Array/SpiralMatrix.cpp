class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

         int row = matrix.size() , col = matrix[0].size();
        
         int top = 0 , bottom = row-1 , left = 0 , right = col-1; 
          
         vector<int>ans;

          while( top <= bottom && left <= right) {

            for(int k = left ; k <=right ; k++ ) 
             ans.push_back(matrix[top][k]);
    
            top++;

            for(int k= top ; k<= bottom ; k++) 
            ans.push_back(matrix[k][right]);
           
            right--;
            
            if(top <= bottom) {
                
            for(int k = right; k>= left ; k--) 
            ans.push_back(matrix[bottom][k]);
            
            bottom--;
            
            }

            if (left <= right) {

            for(int k = bottom ; k>= top ; k--) 
            ans.push_back(matrix[k][left]);

            left++;
            }
        

          }

          return ans;
         
    }
};