class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> a;
        for(int i = 0; i <nums.size(); i++)
        {
            a.push_back({nums[i],i});
        }

        sort(a.begin(), a.end());

        int j = nums.size()-1;
        int i = 0;

        for(int n = 0; n < nums.size(); n++)
        {
            if(a[i].first + a[j].first == target)
            {
                if(a[i].second < a[j].second)
                {
                    return {a[i].second, a[j].second};
                }
                else
                {
                    return {a[j].second, a[i].second};
                }
            }
            else if(a[i].first + a[j].first > target)
            {
                j--;
            }
            else if(a[i].first + a[j].first < target)
            {
                i++;
            }
        }
        return{};
    }
};
