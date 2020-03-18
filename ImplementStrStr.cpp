#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n == 0) return 0;
        vector<int> lps = buildLpsArray(needle, n);
        for(int i=0,j=0; i<m;) 
        {
            if(haystack[i] == needle[j])
            {
                ++i;
                ++j;                
            }
            if(j == n) return i-j;
            if(i<m && haystack[i] != needle[j]) j ? j = lps[j-1] : ++i;
        }
        return -1;
    }
    
    vector<int> buildLpsArray(string& needle, int n)
    {
        vector<int> lps(n, 0);
        for(int i=1, len=0; i<n;)
        {
            if(needle[i] == needle[len]) lps[i++] = ++len;
            else if(len) len = lps[len-1];
            else ++i;
        }
        return lps;
    }
    
};