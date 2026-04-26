class Solution {
public:

    vector<int> genRow(int rows) {
       
       vector<int> temp;
       
       int val = 1;

       temp.push_back(val);

       for(int i= 1 ; i <= rows ; i++  ) {
           
           val = (rows+1-i)*val;

           val = val/i;

           temp.push_back(val);
       }

       return temp;

    }

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;

        for(int row = 0 ; row < numRows ; row++) 
       
        ans.push_back(genRow(row));
        
        return ans;
    }
};