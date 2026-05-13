class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int max = 0;

        for (int right = 1; right < prices.size(); right++)
        {
            if(prices[left] > prices[right])
            {
                left = right;
            }
            else if(prices[left] <= prices[right])
            {
                int current = prices[right] - prices[left];
                if(current > max)
                {
                    max = current;
                }
            }
        }
        return max;
    }
};
