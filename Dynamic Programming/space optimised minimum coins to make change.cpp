const int maxS = 1e2 + 5;
const int maxT = 1e5 + 5;
const int inf = 1LL << 32;

int coins[maxS];
int dp[maxT]; // dp(i) -> minimum coins needed to make change i

// Time Complexity : O(target * totalCoins)
// Space Complexity : O(target)
int totalWays(int target, int totalCoins) {
    
    fill(dp, dp + maxT, inf);  
    dp[0] = 0; 
    for(int i = 0 ; i < totalCoins ; ++i) {
        for(int t = coins[i] ; t <= target ; ++t) {
            dp[t] = min(dp[t], 1 + dp[t - coins[i]]);
        } 
    }
    
    if(dp[target] >= inf) dp[target] = -1;
  
    return dp[target];
}
