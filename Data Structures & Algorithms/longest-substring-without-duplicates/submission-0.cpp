class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longest = 0;

        unordered_set<char> seen;

        for(int right = 0; right < s.size(); right++)
        {
            while(seen.count(s[right]))
            {
                seen.erase(s[left]);
                left++;
            }
            int current = right-left+1;
            if(current > longest)
            {
                longest = current;
            }
            seen.insert(s[right]);
        }
        return longest;
    }
};
