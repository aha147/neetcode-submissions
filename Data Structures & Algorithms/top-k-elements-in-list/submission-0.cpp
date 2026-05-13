class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> temp;

        for(const auto& i : nums)
        {
            temp[i]++;
        }

        vector<pair<int, int>> freq;

        for (const auto& pair : temp) 
        {
            freq.push_back({pair.second, pair.first});
        }

        sort(freq.begin(), freq.end(), greater<pair<int, int>>());

        vector<int> result;

        for (int i = 0; i < k && i < freq.size(); i++) {
            result.push_back(freq[i].second);
        }

        return result;
        
    }
};
