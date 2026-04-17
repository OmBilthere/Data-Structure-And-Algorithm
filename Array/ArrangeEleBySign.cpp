class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     
        int plus = 0 , minus = 1 , n= nums.size();

        vector<int>ans(n);

        for(int i=0 ; i<n ; i++) {

            if( nums[i] > 0 && plus < n ) {
                ans[plus] = nums[i];
                plus += 2;
            }

            else if ( nums[i] < 0 && minus < n ) {
                ans[minus] = nums[i];
                minus += 2;
            }
        }
         return ans;
    }
};