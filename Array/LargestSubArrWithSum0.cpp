class Solution {
  public:
    int maxLength(vector<int>& arr) {
      
      map<int , int> mpp;
      
      int sum = 0;
      
      int ans = 0;
      
      for(int i= 0 ; i < arr.size(); i++) {
          
          sum += arr[i];
          
          if(sum == 0 ) ans = i+1;
          
          
          if(mpp.find(sum) != mpp.end()) {
              
              ans = max(ans , i-mpp[sum]);
              
          }
          
          if(mpp.find(sum) == mpp.end()) 
             
          mpp[sum] = i;
      }
        
        
        return ans;
    }
};