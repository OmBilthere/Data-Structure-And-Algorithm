class Solution {
public:

    void remove(int ind , int bracket , string & s , string & ans , int n) {
       
       if(ind == n) return ;

       if(s[ind] == '(') {
             
            if(bracket > 0 ) ans.push_back(s[ind]);
            bracket++;
       }

       else {
         
         bracket --;
         if(bracket > 0 ) ans.push_back(s[ind]);
       }
      
      remove(ind+1 , bracket , s , ans , n );
       
    }
    string removeOuterParentheses(string s) {
        
         string ans = "";
         int n = s.size() , bracket = 0;
         remove(0 ,bracket, s , ans , n);
         return ans;
    }
};