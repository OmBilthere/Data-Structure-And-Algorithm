class Solution {
public:

    vector<int> rec(vector<int>& nums , int index) {
        
        if(index == nums.size() ) return nums;

           int j = index;
           
           while( j>0 && nums[j-1] > nums[j]) {
               
               swap(nums[j-1] , nums[j]);
               
               j--;
           }
          
           return rec(nums , index+1);
    }
    vector<int> insertionSort(vector<int>& nums) {
         
         return rec(nums , 0);
    }
};
