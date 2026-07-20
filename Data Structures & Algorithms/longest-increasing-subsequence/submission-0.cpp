class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());

        int result = 1;

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            dp[i] = 1;
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] > nums[i])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }

                result = max(result, dp[i]);
            }
        }

        return result;
    }
};
