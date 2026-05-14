class Solution {
public:

    void reverse(int start , int end , string & s) {
          while(start < end) {
            swap(s[start] , s[end]);
            start++ , end--;
          }
    }

    string reverseWords(string s) {
        
        int n = s.size();

        reverse(0 , n-1 , s); 

        int start = 0;

        for(int i=0 ; i<=n ; i++) {

            if( i==n || s[i] == ' ') {

                reverse(start , i-1 , s );
                start = i+1;

            }
        }

        string ans = "" , temp ="";
        
        for(int i=0 ; i<=n ; i++) {

          if(i != n && s[i] != ' ') 
           
          temp += s[i];    

          else  {

            if(temp.size()) { 
                
                ans += temp + ' ';
                temp ="";

              }

          }
          
       }
        
       if(ans.back() == ' ') ans.pop_back();
        
        return ans;
    }
}; 