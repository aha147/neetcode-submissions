class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int length = 0;
        int left = 0;
        int current = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(st.count(s[i]))
            {
                while(st.count(s[i]))
                {
                    st.erase(s[left]);
                    left++;
                }
                st.insert(s[i]);
                current = i - left + 1;
            }
            else
            {
                st.insert(s[i]);
                current++;
                if(current > length)
                {
                    length = current;
                }
            }
        }

        return length;
    }
};
