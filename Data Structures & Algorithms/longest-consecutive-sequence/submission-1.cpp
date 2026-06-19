class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        int longest = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int length = 0;
            int num = nums[i];
            if(st.count(num-1) == 0)
            {
                int k = 0;
                int current = 0;
                while(st.count(num+k))
                {
                    current++;
                    k++;
                    if(current > longest)
                    {
                        longest++;
                    }
                }
            }
        }
        return longest;
    }
};
