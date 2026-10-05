class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit=0;
        int mn=prices[0];
        for(int i=1;i<prices.size();i++){
            mn=min(mn,prices[i]);
            int diff=prices[i]-mn;
            profit=max(profit,diff);
        }
        return profit;
    }
};
