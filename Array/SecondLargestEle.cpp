
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        if(arr.size()<2)
        return -1;
        int maxi=arr[0];
        int ans=-1;
       for(int i=1;i<arr.size();i++)
       {
           if(maxi<arr[i])
           {
               ans=maxi;
               maxi=arr[i];
           }
           else if(arr[i]<maxi && arr[i]>ans)
           ans=arr[i];
       }
       
     return ans;
          
          
    }
};