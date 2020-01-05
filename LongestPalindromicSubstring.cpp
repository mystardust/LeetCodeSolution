#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        if(n <= 1) return s;
        int l=0,r=0;
        for(int i=1; i<n && (r-l) < 2*(n-i); ++i){
            int ll ,rr;
            if(s[i-1] == s[i+1])
            {
                ll = i-1;
                rr = i+1;
                while((ll-1)>=0 && (rr+1)<n && s[ll-1] == s[rr+1] )
                {
                    --ll;
                    ++rr;
                }
                if(rr-ll > r-l){
                    l=ll;
                    r=rr;
                }
            }
            if(s[i-1] == s[i])
            {
                ll = i-1;
                rr = i;
                while((ll-1)>=0 && (rr+1)<n && s[ll-1] == s[rr+1] )
                {
                    --ll;
                    ++rr;
                }
                if(rr-ll > r-l)
                {
                    l=ll;
                    r=rr;
                }
            }       
            
        }
        return s.substr(l, r-l+1);
    }
};