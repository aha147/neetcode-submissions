class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int n=0; n<nums.size(); n++)
        {
            if(nums[n] == nums[n+1])
            {
                return true;
            };
        }
        return false;
    }
};