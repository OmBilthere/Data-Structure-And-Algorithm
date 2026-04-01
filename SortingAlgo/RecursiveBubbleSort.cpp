class Solution {
public:
    
    vector<int> rec( vector<int>&nums , int end ) {

       if (end == 1 ) return nums;

           for(int j = 0; j < end  ; j++ ) {
               
               if(nums[j] > nums[j+1] )
             
               swap(nums[j] , nums[j+1]);
             
           }

     return rec(nums , end-1); 
           
       
    }
   
    vector<int> bubbleSort(vector<int>& nums) {

         int n = nums.size();

         if(n <= 1) return nums;
          
         return rec(nums , n-1);
    }
};
