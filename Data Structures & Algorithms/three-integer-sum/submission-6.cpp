class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1] && i>0 )
            {
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            int target = nums[i]*(-1);
            while(left < right)
            {
                if((nums[left] + nums[right]) < target)
                {
                    left++;
                }
                else if((nums[left] + nums[right]) > target)
                {
                    right--;
                }
                else if((nums[left]+nums[right]) == target)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1])
                    {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right+1])
                    {
                        right++;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
