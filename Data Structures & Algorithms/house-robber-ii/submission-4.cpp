class Solution {
public:
    int rob(vector<int>& nums) {
        int exclude_first = 0;
        int exclude_last = 0;

        if(nums.size() == 1)
        {
            return nums[0];
        }

        if(nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(nums.size());

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for( int i = 2; i < nums.size()-1; i++)
        {
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }

        exclude_last = dp[nums.size()-2];

        if(nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> dp2(nums.size());

        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);

        for( int i = 3; i < nums.size(); i++)
        {
            dp2[i] = max(dp2[i-1], nums[i]+dp2[i-2]);
        }

        exclude_first = dp2[nums.size()-1];

        return max(exclude_first, exclude_last);


    }
};
