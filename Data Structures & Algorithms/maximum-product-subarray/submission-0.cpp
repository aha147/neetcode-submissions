class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxDP(nums.size());
        vector<int> minDP(nums.size());

        maxDP[0] = nums[0];
        minDP[0] = nums[0];

        if(nums.size() == 1)
        {
            return nums[0];
        }

        int result = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            maxDP[i] = max({nums[i], nums[i]*maxDP[i-1], nums[i]*minDP[i-1]});
            minDP[i] = min({nums[i], nums[i]*maxDP[i-1], nums[i]*minDP[i-1]});

            result = max(result, maxDP[i]);
        }

        return result;
    }
};
