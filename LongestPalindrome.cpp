class Solution {
public:
    int longestPalindrome(string s) {
        set<char> m ;
        bool flag = false;
        int result = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(m.find(s[i]) == m.end())
            {
                m.insert(s[i]);
                int c = count(s.begin(), s.end(), s[i]);
                switch(c % 2)
                {
                    case 0: result += c; break;
                    case 1: if(flag) result += c-1; else {result += c; flag = true;} break;
                    default: break;
                }
            }
        }
        return result;
    }
};