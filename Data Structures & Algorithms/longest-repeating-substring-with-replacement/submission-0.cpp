class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;
        unordered_set<char> charSet(s.begin(), s.end());

        for(char c : charSet)
        {
            int current = 0;
            int left = 0;

            for (int right = 0; right < s.size(); right++)
            {
                if(s[right] == c)
                {
                    current++;
                }
                
                while((right - left +1) - current > k)
                {
                    if(s[left] == c)
                    {
                        current--;
                    }
                    left++;
                }
                
                if((right - left+1) > longest)
                {
                    longest = (right - left +1);
                }
            }

            
        }
        return longest;
    }
};
