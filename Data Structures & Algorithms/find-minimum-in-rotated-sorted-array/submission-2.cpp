class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;

        for(int n = 0; n < nums.size(); n++)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
            {
                left = mid;
            }
            else if(nums[mid] < nums[right])
            {
                right = mid;
            }
            if(left == (right - 1))
            {
                n = nums.size();
            }
        }
        if(nums[left] < nums[right])
        {
            return nums[left];
        }
        else
        {
            return nums[right];
        }
        
    }
};
