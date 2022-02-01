const int maxS = 1e2 + 5;
const int maxT = 1e5 + 5;

int coins[maxS];
int64_t dp[maxT]; // dp(i) -> no of ways to make change i

// Time Complexity : O(target * totalCoins)
// Space Complexity : O(target)
int totalWays(int target,int totalCoins) {
    dp[0] = 1LL // no of ways to make change of 0 is 1 (empty subset)
    for(int i = 0 ; i < totalCoins ; ++i) {
        for(int t = coins[i] ; t <= target ; ++t) {
            dp[t] += dp[t - coins[i]];  
        } 
    }
    return dp[target];
}
