class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        Permutation("",n,n);
        return result;
    }
    void Permutation(string s, int l, int r)
    {
        if(l == r && r == 0) result.push_back(s);
        else
        {
            if(l == r)
                Permutation(s+"(",l-1,r);
            if(l < r)
            {
                if(l >= 1)Permutation(s+"(",l-1,r);
                Permutation(s+")",l,r-1);
            }
        }
    }
};