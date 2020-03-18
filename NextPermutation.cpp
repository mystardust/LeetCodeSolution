#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto front = nums.end()-1;
        for(; front != nums.begin(); --front)
        {
            auto back = front-1;
            if(*front > *back) break;
        }
        if(front == nums.begin()) sort(nums.begin(), nums.end());
        else
        {
            auto back = front-1;
            sort(front,nums.end());
            for(; front!=nums.end(); ++front) if(*front > *back){swap(*front,*back);break;}
        }
    }
};