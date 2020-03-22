#include<vector>

using namespace std;

class Solution {
public:
    int n = 0;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        n = nums.size();
        permutation(result, nums, 0);
        return result;
    }
    void permutation(vector<vector<int>> &result, vector<int>& nums, int start)
    {
        if(start == nums.size()){ result.push_back(nums); return;}
        for(int i = start; i < n; ++i)
        {
            swap(nums[i],nums[start]);
            permutation(result, nums, start+1);
            swap(nums[i],nums[start]);
        }
    }
};