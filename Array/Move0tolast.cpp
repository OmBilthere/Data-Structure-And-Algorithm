class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();

        int pt = -1;

        for(int i= 0 ; i < n ; i++ ) {
            
            if(nums[i] !=  0) {

                pt++;

                swap(nums[i] , nums[pt]);

            }
        }
    }
};