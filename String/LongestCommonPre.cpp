class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();

        string s = strs[0];

        for(int i=1 ; i<n ; i++) {

           string temp = ""; 
           
           for(int j=0 ; j < min(s.size(),strs[i].size()) ; j++) {

              if(strs[i][j] == s[j]) temp += s[j];

              else break;

           }

           s = temp;

           if(s == "") return s;
           
        }

        return s;
    }
};