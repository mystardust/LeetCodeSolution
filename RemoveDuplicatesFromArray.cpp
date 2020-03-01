#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        int n = nums.size();
        if(n < 2) return n;
        int k= nums[0];
        int result = 1;
        for(int i = 1; i < n; ++i)
        {
            if(k != nums[i])
            {                
                nums[result++] = nums[i];
                k = nums[i];                
            }
        }
        return result;
    }
};