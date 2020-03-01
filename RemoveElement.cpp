#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result = nums.size();
        for(int i = result - 1; i >= 0; --i)
        {
            if(val == nums[i]) 
            {
                --result;
                nums[i] = nums[result];
                nums[result] = val;
            }
        }
        return result;
    }
};