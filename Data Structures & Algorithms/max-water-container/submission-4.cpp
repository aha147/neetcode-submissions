class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int max = 0;

        while(left<right)
        {
            int area = min(heights[left], heights[right]) * (right-left);
            if(area > max)
            {
                max = area;
            }
            if(heights[left] <= heights[right])
            {
                left++;
            }
            else if(heights[left] > heights[right])
            {
                right--;
            }
        }
        return max;
    }
};
