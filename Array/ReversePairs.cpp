class Solution {
public:
    
    int countPairs(vector<int>& arr , int start , int mid , int end ) {
        
        int right = mid+1 , cnt = 0;

        for(int left=start ; left <= mid ; left++) {
             
             while(right <=end && arr[left] > (long long)2 * arr[right]) 
             right++;

             cnt+= right-(mid+1);

       } 

        return cnt;
    }

    void merge( vector<int>& arr , int start , int mid , int end ) {
         
         int left = start , right = mid+1 ;

         vector<int>temp;

         while(left <= mid && right <= end ) {
              
              if(arr[left] <= arr[right]) {
                 temp.push_back(arr[left]);
                 left++;
              }

              else {
                temp.push_back(arr[right]);
                right++;
              }
         }

         while(left <= mid ) {
            temp.push_back(arr[left]);
            left++;
         }

         while(right <= end) {
            temp.push_back(arr[right]);
            right++;
         }

         for(int i=start ; i <= end ; i++) 
         arr[i] = temp[i-start];
           

    } 

    int mergeSort(vector<int>& arr , int start , int end) {

        if( start >= end) return 0;

        int mid = start + (end - start) / 2 , cnt = 0;

        cnt += mergeSort(arr , start , mid );
        cnt += mergeSort(arr , mid+1, end );
        cnt += countPairs(arr , start , mid , end );
        merge(arr , start , mid , end);

        return cnt;

    }

    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();

        return mergeSort(nums , 0 , n-1);
    }
};