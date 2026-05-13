class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> temp;
        for(const string s : strs)
        {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            temp[sorted].push_back(s);
        }

        vector<vector<string>> result;
        for(const pair<const string, vector<string>> s : temp)
        {
            result.push_back(s.second);
        }
        return result;
    }
};
