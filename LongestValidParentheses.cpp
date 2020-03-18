#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> si;
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(') si.push(i);
            else if(!si.empty() && s[si.top()] == '(') si.pop();
            else si.push(i);
        }
        if(si.empty()) return n;
        int longest = 0;
        int a = n, b = 0;
        while(!si.empty())
        {
            b = si.top();
            si.pop();
            longest = (a-b-1 > longest)?(a-b-1):longest;
            a = b;
        }
        return longest>a?longest:a;
    }
};