class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;

        for(int i=0; i< nums.size(); i++) {

            mpp[nums[i]]++;

        }

        int maxi = INT_MIN;

        int majority;

        for(int i=0 ; i<nums.size() ; i++) {

            if( mpp[nums[i]] > maxi) {
              
              maxi = mpp[nums[i]];

              majority =nums[i];

            }
        }

       return majority;
    }
};