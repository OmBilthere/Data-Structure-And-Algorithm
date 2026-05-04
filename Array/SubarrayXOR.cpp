class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
       
        unordered_map< long , long > mpp;
        
        long xorr = 0 , cnt = 0;
       
        for(int i=0; i< arr.size() ; i++) { 
            
            xorr ^= arr[i];
            
            if(xorr == k ) cnt++ ;
            
            int rem = xorr^k;
            
            cnt += mpp[rem];
            
            mpp[xorr]++;
           
            
         }
         
         
         return cnt ;
        
        
    }
}; 