const int total_days = 1e5 + 5;

int dp[2][3][total_days];

int find_max_profit(vector<int>& prices,bool bought,int tp,int cur_day) {
        
     // Base Case -> out of bounds 
     if(cur_day >= prices.size() or !tp) return 0;
        
     // Look up
     if(dp[bought][tp][cur_day] != -1) return dp[bought][tp][cur_day];
        
     // Skip
     int res = find_max_profit(prices,bought,tp,cur_day+1);
     // Sell
     if(bought) res = max(res,find_max_profit(prices,false,tp-1,cur_day+1) + prices[cur_day]);
     // Bought
     else res = max(res,find_max_profit(prices,true,tp,cur_day+1) - prices[cur_day]);
        
     return dp[bought][tp][cur_day] = res;
}
    
