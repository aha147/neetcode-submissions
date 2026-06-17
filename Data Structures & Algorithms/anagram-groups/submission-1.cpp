class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> temp;
        for(int i = 0; i < strs.size(); i++)
        {
            string a = strs[i];
            sort(a.begin(), a.end());
            temp[a].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for(const pair<const string, vector<string>> s : temp)
        {
            result.push_back(s.second);
        }
        return result;

    }
};
