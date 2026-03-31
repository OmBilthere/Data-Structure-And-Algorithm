class Solution {
    
  public:
  
    void merge(vector<int>& arr , int l , int mid , int r ) {
        
        int i = l ,j = mid + 1;
        
        vector<int>temp;
        
        while(i<=mid && j<=r) {
          
            if(arr[i] < arr[j]) 
                
            temp.push_back(arr[i++]);
                
            else 
                
            temp.push_back(arr[j++]);
         
         }
         
         
          while(i <= mid) 
              
          temp.push_back(arr[i++]);
        
          while(j <= r) 
              
          temp.push_back(arr[j++]);
         
          for(int k=l; k<=r; k++) 
          
          arr[k]=temp[k-l];
          
        
        
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        
        
       if(l == r) return;    
       
       int mid = l + (r - l) /2 ;
       
       mergeSort(arr , l , mid);
       
       mergeSort(arr , mid+1 , r);
       
       merge(arr , l , mid , r );
        
    }
};