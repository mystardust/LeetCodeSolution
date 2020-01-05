#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 3) return result;
        sort(nums.begin(), nums.end());        
        for(int i=0; i<n; ++i)
        {
            int target = -nums[i];
            if(target<0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left < right)
            {
                int sum = nums[left]+nums[right];
                if( sum > target)
                {
                    --right;
                }
                else if(sum < target)
                {
                    ++left;
                }
                if(sum == target)
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(nums[left+1] == nums[left] && left+1<right) ++left;
                    while(nums[right-1] == nums[right] && left <right-1) --right;
                    ++left;
                    --right;
                }
            }
        }
        return result;
    }
};