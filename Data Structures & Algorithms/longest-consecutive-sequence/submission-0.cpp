class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int totalLength = 0;

        for (int num : numset)
        {
            if(numset.find(num - 1) == numset.end())
            {
                int curlength = 1;
                while(numset.find(num + curlength) != numset.end())
                {
                    curlength++;
                }
                if(curlength > totalLength)
                {
                    totalLength = curlength;
                }
            }
        }
        return totalLength;
        
    }
};
