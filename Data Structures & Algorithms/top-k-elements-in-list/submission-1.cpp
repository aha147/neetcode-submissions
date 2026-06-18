class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(const auto& i : nums)
        {
            mp[i]++;
        }

        vector<pair<int, int>> freq;

        for(const auto& pair : mp)
        {
            freq.push_back({pair.second, pair.first});
        }

        sort(freq.begin(), freq.end(), greater<pair<int, int>>());

        vector<int> result;

        for(int i = 0; i<k && i<freq.size(); i++)
        {
            result.push_back(freq[i].second);
        }

        return result;
    }
};
