const int maxS = 505;
const int maxW = 1e5 + 5;

int dp[maxW]; // dp(i) -> max profit we can get with capacity of sack upto i
int profit[maxS],weight[maxS];

// Time Complexity = O(capacity * totalItems)
// Space Complexity = O(capacity)
int max_profit(int capacity,int totalItems) {
  for(int i = 0 ; i < totalItems ; ++i) {
      for(int w = capacity ; w >= weight[i] ; --w) {
          dp[w] = max(dp[w], profit[i] + dp[w - weight[i]]);  
      }
  }
  return dp[capacity];
}
