#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        int mid = -1;
        if(n == 0 || (mid = findTargetAtMiddle(nums, target, 0, n - 1)) < 0)  {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(findTargetWithDirection(nums, target, 0, mid, true));
        result.push_back(findTargetWithDirection(nums, target, mid, n-1, false));
        return result;
    }
    
    int findTargetWithDirection(vector<int>& nums, int target, int left, int right, bool smallIndex){
        if(left > right) return -1;
        if(nums[left] > target || nums[right] < target) return -1;
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            if(left == right) return left;
            if(smallIndex) return findTargetWithDirection(nums, target, left, mid, smallIndex); 
            else if(left + 1 == right && nums[right] == target) return right;
            else if(left + 1 == right && nums[right] != target) return left;
            return findTargetWithDirection(nums, target, mid, right, smallIndex);            
        }
        if(nums[mid] < target) return findTargetWithDirection(nums, target, mid + 1, right, smallIndex);
        else return findTargetWithDirection(nums, target, left, mid - 1, smallIndex);
    }
    
    int findTargetAtMiddle(vector<int>& nums, int target, int left, int right){
        if(left > right) return -1;
        if(nums[left] > target || nums[right] < target) return -1;
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) return findTargetAtMiddle(nums, target, mid + 1, right);
        else return findTargetAtMiddle(nums, target, left, mid - 1);
    }
    
};