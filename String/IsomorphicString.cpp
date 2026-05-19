class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int n = s.size() , m = t.size();

        if( n != m ) return false;

        unordered_map< char , char > mpp1, mpp2;

        for(int i=0 ; i<n ; i++) {

          if((mpp1.find(s[i]) != mpp1.end() && mpp1[s[i]] != t[i] ) || 
          (mpp2.find(t[i]) != mpp2.end() && mpp2[t[i]] != s[i]))

          return false;

           

          mpp1[s[i]] = t[i];
          mpp2[t[i]] = s[i];

        }

         return true;
    }
};