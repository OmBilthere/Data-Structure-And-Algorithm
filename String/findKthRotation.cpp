class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        
        int n = arr.size() , low = 0 , high = n-1;
        
        while(low < high) {
            
            int mid = low + (high - low) / 2;
            
            if(arr[mid] <= arr[high])   high= mid;
                
            else  low = mid+1;
                
            
        }
        
        
        return high;
    }
};
