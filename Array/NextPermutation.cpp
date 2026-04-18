class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() , brkPt = -1 ; 

        for(int i = n-1 ; i > 0 ; i--) {

            if(nums[i] > nums[i-1]) {
                
                brkPt = i-1;
                break;
            }
        }

        if(brkPt == -1) {
            reverse(nums.begin() , nums.end());
            return;
        }
       
       for(int i=n-1 ; i > brkPt ; i--) {

          if(nums[i] > nums[brkPt])  {

            swap(nums[i] , nums[brkPt]);
            break;

          }
       }

       reverse(nums.begin()+brkPt+1 , nums.end());

        
    }
};