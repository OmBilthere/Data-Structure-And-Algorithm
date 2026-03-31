class Solution {
    
  public:
  
    void quickSort(vector<int>& arr, int low, int high) {
        
        if(low<high) {
            
            int p = partition(arr , low , high);
            
            quickSort(arr , low , p-1);
            
            quickSort(arr , p+1 , high);
        }
        
    }
  
    int partition(vector<int>& arr, int low, int high) {
        
        int pivot = arr[high];
        
        // int i = low;
        
        // int j = high-1;
        
        // while( i <= j ) {
            
        //     while(i<= high-1 && arr[i] <= pivot)
        //     i++;
            
        //     while(j >= low && arr[j] > pivot)
        //     j--;
            
        //     if( i < j) {
            
        //     swap(arr[i], arr[j]);
            
        //     i++ , j--;
                
        //     }
            
        // }
        
        // swap(arr[i] , arr[high] );
        
        int i = low-1;
        
        for(int k = low ; k < high ; k++ ) {
            
            if(arr[k] <= pivot) {
                
                i++;
                
                swap(arr[i] , arr[k]);
            }
            
        }
        
        swap(arr[i+1] , arr[high]);
        
        return i+1;
    }
}; 