#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        size_t n = nums.size();
        vector<pair<int, size_t>> pairs;
        for(int i = 0; i < n; ++i)
            pairs.push_back(make_pair(nums[i],i));
        sort(pairs.begin(), pairs.end());
        
        for(int i = 0; i < n; ++i)
        {
            bool flag = false;
            int k = pairs[i].first;            
            for(int j = i+1; j < n; ++j)
            {
                int sum = pairs[j].first + k;
                if(sum > target) break;
                if(sum == target)   
                {
                    flag = true;
                    result.push_back(pairs[i].second);
                    result.push_back(pairs[j].second);
                    break;
                }
            }
            if(flag) break;
        }
        return result;
    }
};