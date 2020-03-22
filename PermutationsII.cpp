#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        permutation(result, nums, 0);
        return result;
    }
    void permutation(vector<vector<int>> &result, vector<int> nums, int start)
    {
        if(start == nums.size()){ result.push_back(nums); return;}
        for(int i = start; i < nums.size(); ++i)
        {
            if(i > start && nums[i] == nums[start])continue;
            swap(nums[i],nums[start]);
            permutation(result, nums, start+1);
        }
    }
};