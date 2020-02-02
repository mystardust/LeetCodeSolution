#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        stack<char> ss;
        for(int i = 0; i < length; ++i)
        {
            switch(s[i])
            {
                case '{': ss.push('{'); break;
                case '[': ss.push('['); break;
                case '(': ss.push('('); break;
                case '}': if(!ss.empty() && ss.top() == '{') ss.pop(); else return false; break;
                case ']': if(!ss.empty() && ss.top() == '[') ss.pop(); else return false; break;
                case ')': if(!ss.empty() && ss.top() == '(') ss.pop(); else return false; break;
            }
        }
        return ss.empty();
    }
};