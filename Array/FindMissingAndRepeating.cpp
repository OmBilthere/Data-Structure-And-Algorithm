
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        //  BETTER
        int n=arr.size();
        
        // int hash[n+1]={0};
        // int repeating=-1;
        // int missing =-1;
        // for(int i=0;i<n;i++)
        // hash[arr[i]]++;
        
        // for(int i=1;i<n+1;i++)
        // {
        //     if(hash[i]==2)
        //     repeating =i;
        //     else if(hash[i]==0)
        //     missing = i;
        //     if(missing!=-1 && repeating !=-1)
        //     break;
            
        // }
        //optimal 1(maths)
        //   long long n= arr.size();
        //   long long SN = (n * (n + 1)) / 2;
        //   long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
        //   long long S=0;
        //   long long S2=0;
        // for(int i=0;i<n;i++)
        // {
        //     S+=arr[i];
        //     S2+= (long long)arr[i]*(long long)arr[i];
        // }
        // long long val1 = S-SN;
        // long long val2 = S2-S2N;
        // val2=val2/val1;
        
        // long long repeating = (val2+val1)/2;
        // long long missing =   repeating - val1;
        
        // return {int (repeating),int (missing)};
        
        
        // optimal2(xor method)
        //step 1(take xor we will have missing^repeating in variable xorr)
        int xorr=0;
        for(int i=0;i<n;i++)
        {
            xorr=xorr^arr[i];
            xorr=xorr^(i+1);
        }
        //step 2 (the number variable will store the rightmost bit that is set(1))
        int number = (xorr & ~(xorr-1));
        // step 3 do grouping of array element on the basis of number variable bit
        int zero=0;
        int one =0;
        for(int i=0;i<n;i++)
        {
            if((arr[i] & number) !=0)
            one=one^arr[i];
            else
            zero=zero^arr[i];
            
        }
        // step 4 in grouping counting is also there so take them in group
        for(int i=1;i<=n;i++)
        {
            if((i & number) !=0)
            one=one^i;
            else
            zero=zero^i;
        }
        // identify numbers
           int cnt = 0;
        for (int i = 0; i < n; i++)
        if (arr[i] == zero) 
          cnt++; 
        
        // retrun ans
        if (cnt == 2) return {zero, one};
        
        return {one, zero};
       
        
    }
};