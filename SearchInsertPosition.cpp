#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;
        return binarySearch(nums, target, 0, n-1);
    }
    
    int binarySearch(vector<int>& nums, int target, int left, int right){
        if(nums[left] > target) return left;
        if(nums[right] < target) return right+1;
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) return binarySearch(nums, target, left, mid-1);
        else return binarySearch(nums, target, mid+1, right);
    }
};