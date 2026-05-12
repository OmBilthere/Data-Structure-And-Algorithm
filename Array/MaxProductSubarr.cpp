class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // int n = nums.size() , result = -1e9 , pre = 1 , suff = 1;

        // for(int i=0 ; i < n ; i++) {

        //   if(nums[i] ==0) pre = 1;
        //   if(nums[n-i-1] == 0 ) suff = 1;  
           
        //    pre *= nums[i];

        //    suff *= nums[n-i-1];

        //    result = max({result , pre , suff});
          
        // }
        
        int n = nums.size() , prod1 = 1 , prod2 = 1 , result = -1e9;

        for(int i = 0 ; i< n ; i++) {

            int temp = max({nums[i] , prod1 * nums[i] , prod2 * nums[i]});
            
            prod2 = min({nums[i] , prod1 * nums[i] , prod2 * nums[i]});

            prod1 = temp;

            result = max(result , prod1);
        }

        return result;
    }
};