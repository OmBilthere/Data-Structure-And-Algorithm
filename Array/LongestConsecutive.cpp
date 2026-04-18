class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        unordered_set<int>st(nums.begin() , nums.end());

        int n = nums.size();

        int maxi = 0;

        for(auto it : st) {
 
            if(st.find(it-1) == st.end()) {
               
              int cnt = 1;

              int temp = it;

              while(st.find(temp+1) != st.end()) {
                
                   temp++ ;
                   cnt++;
              }

              maxi = max(maxi , cnt);
          

         }

     }

        return maxi;
    }
};