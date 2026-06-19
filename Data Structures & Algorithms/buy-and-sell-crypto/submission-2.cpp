class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int maxProfit = 0;

        for(int right = 1; right < prices.size(); right++)
        {
            int profit  = 0;
            if(prices[right] > prices[left])
            {
                profit = prices[right] - prices[left];
                if(profit > maxProfit)
                {
                    maxProfit = profit;
                }
            }
            else
            {
                left = right;
            }
        }
        return maxProfit;
    }
};
