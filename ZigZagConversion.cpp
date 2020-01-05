#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if(s.empty()) return result;
        if(numRows == 1) return s;
        int x = 2 * numRows - 2;
        for(int i = 0; i < numRows; ++i)
        {
            int k = i;
            int kk = x - i;
            while(k <= s.size()-1)
            {
                result.push_back(s[k]);
                k += x;
                if(i != 0 && i != numRows-1 && kk <= s.size()-1)
                {
                    result.push_back(s[kk]);
                    kk += x;
                }
            }
        }
        return result;
    }
};