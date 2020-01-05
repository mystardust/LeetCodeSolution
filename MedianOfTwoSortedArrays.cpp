#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() >= nums2.size()) return binarySearch(nums2, nums1);
        return binarySearch(nums1, nums2);
    }
    
    double binarySearch(vector<int>& nums1, vector<int>& nums2){
        int leftMax, rightMin;
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;  
        int half =(n+m+1)>>1;
        int i = 0, j = 0;
        while(left <= right)
        {
            i = (left + right) >> 1;
            j = half-i;
            if(  i<m &&nums1[i] < nums2[j-1]) left = i+1;
            else if(i>0 && nums1[i-1] > nums2[j]) right = i-1;
            else
            {
                if(i == 0)leftMax = nums2[j-1];
                else if(j == 0)leftMax = nums1[i-1];
                else leftMax=max(nums1[i-1],nums2[j-1]);
                if((m+n)&1) return leftMax;
                break;
            }
        }
        if(i == m) rightMin = nums2[j];
        else if(j == n)rightMin = nums1[i];
        else rightMin = min(nums1[i], nums2[j]);
        return (leftMax+rightMin)/2.0;
    }
};