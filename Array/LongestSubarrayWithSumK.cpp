class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        unordered_map<long long, int> mpp;
        
        long long sum = 0;
        int maxi = 0;

        mpp[0] = -1;

        for (int i = 0; i < arr.size(); i++) {
            
            sum += arr[i];

            long long rem = sum - k;

            if (mpp.find(rem) != mpp.end()) {
                maxi = max(maxi, i - mpp[rem]);
            }

            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }

        return maxi;
    }
};