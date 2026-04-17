class Solution {
public:
    int maxProfit(vector<int>& prices) {

       int mini = 1e9;

       int maxProfit = -1e9;

       for(int i=0 ; i<prices.size(); i++) {
           
           mini = min (mini , prices[i]);
           
           maxProfit= max (maxProfit , prices[i]-mini);

       } 

       return maxProfit;
    }
};