#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        traceback(result,candidates,combination,target,0);
        return result;
    }
    void traceback(vector<vector<int>> &result, vector<int>& candidates, vector<int>& combination, int target, int start)
    {
        if(target == 0){result.push_back(combination); return;}
        for(int i=start; i < candidates.size() && target >= candidates[i]; ++i)
        {
            combination.push_back(candidates[i]);
            traceback(result, candidates, combination, target-candidates[i] , i);
            combination.pop_back();
        }
    }
};