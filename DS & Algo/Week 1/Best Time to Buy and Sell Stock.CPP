class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), i, max_from[100000], max = 0;
        for(i = size-1 ; i >= 0 ; i--)
        {
            if(prices[i] > max) max = prices[i];
            max_from[i] = max;
        }
        
        max = 0;
        for(i = 0 ; i < size; i++)
            if(max_from[i] - prices[i] > max)   max = max_from[i] - prices[i];
        
        return max;
    }
};
