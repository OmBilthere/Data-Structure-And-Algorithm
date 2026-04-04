class Solution {
public:
    bool check(vector<int>& nums) {

        int cnt = 0;

        int n = nums.size();
        
        for(int ind = 1 ; ind < n ; ind++) 
           
        if(nums[ind-1] > nums[ind]) 
          
        cnt++;
        
        if( nums[n-1] > nums[0])
            
        cnt++;

        return cnt <=1;
    }
};