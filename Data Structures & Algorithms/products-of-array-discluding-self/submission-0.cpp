class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());

        left[0] = nums[0];
        right[nums.size()-1] = nums[nums.size()-1];

        //left to right prefix
        for(int i = 0; i < nums.size()-1; i++)
        {
            left[i+1] = left[i] * nums[i+1];
        }
        //right to left prefix
        for(int i = nums.size()-1; i > 0; i--)
        {
            right[i-1] = right[i] * nums[i-1];
        }

        vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int product = 0;
            if( i == 0)
            {
                product = right[1];
                result[i] = product;
            }

            else if(i == nums.size()-1)
            {
                product = left[nums.size()-2];
                result[i] = product;
            }
            else
            {
                product = left[i-1] * right[i+1];
                result[i] = product;
            }
        }

        return result;
    }
};
