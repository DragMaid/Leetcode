class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m_p = 0;
        int min_buy = prices[0];
        for (int i=1; i<prices.size(); i++) {
            m_p = max(prices[i] - min_buy, m_p);
            min_buy = min(min_buy, prices[i]);
        }
        return m_p;
    }
};

// what if I do it like dp
// Where in an array
// for example
// before the ith day then the best time to buy would be (given that you are selling ithd day stock)
// // 7,1,5,3,6,4
// // i would start from 1 to n-1
// // or it would be the smallest till ith day
