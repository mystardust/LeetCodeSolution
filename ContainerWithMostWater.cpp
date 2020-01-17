#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {        
        int i=0, j = height.size()-1;        
        int tempLength = height[i]>height[j]?height[j]:height[i];
        int temp=(j-i)*tempLength;
        int result = temp;
        while(i<j)
        {
            if(height[i]>height[j])            
            {
                if(height[j]<=tempLength)
                {
                    --j;
                    continue;
                }
                temp = (j-i)*height[j];
                tempLength = height[j];
                --j;
            }
            else
            {
                if(height[i]<=tempLength)
                {
                    ++i;
                    continue;
                }
                tempLength=height[i];
                temp = (j-i)*height[i];
                ++i;
            }
            if(temp > result) result = temp;            
        }
        return result;
    }
};