const int maxS = 1e2 + 5;
const int maxN = 1e5 + 7;
int dp[maxS][maxN];
pii arr[maxS]; // first-> weight of item 
               // second -> profit of item

int max_profit(int n,int w) {
    // base case
    if(n == 0 or w == 0) return 0;
  
    // look up
    if(dp[n][w] != -1) return dp[n][w];

    int exclude = max_profit(n-1,w);
    int include = 0;
    if(arr[n].ff <= w) {
        include = arr[n].ss + max_profit(n-1,w-arr[n].ff);
    } 

    return dp[n][w] = max(exclude,include);
}
