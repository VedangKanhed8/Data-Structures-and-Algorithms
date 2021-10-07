#include<bits/stdc++.h>
using namespace std;

/*
  Time Complexity =  O ( Number_of_Coins * Sum *  log (Number_of_Coins))    
  Space Complexity = O ( Number_of_Coins * Sum ) 
*/

int NumberOfCoins;
vector<int> coins(NumberOfCoins);

set<int> All_Possible_Subset_Sums() {
    
    int total = 0;
    for(int i = 0 ; i < NumberOfCoins ; i++) {
        cin >> coins[i];
        total += coins[i];
    }

    /*dp(sum,i) -> 1. Take ith coin = dp(sum - coins[i] , i-1)
                 2. Dont take ith coin = dp(sum , i-1)
                 = Take BITWISE OR of this two states */
    
    vector<vector<bool>> dp(n+1,vector<bool>(total+1,false));
    
    set<int> possSums;

    for(int i = 0 ; i <= n ; i++) {
        for(int s = 0 ; s <= total ; s++) {
            if(s == 0) dp[i][s] = true;
            else if(i == 0) dp[i][s] = false;
            else if(coins[i-1] <= s) {
                dp[i][s] = (dp[i-1][s - coins[i-1]] or dp[i-1][s]);
            }
            else dp[i][s] = dp[i-1][s];
            
            if(dp[i][s] and s != 0) possSums.insert(s); 
        }
    }
    return possSums;
}
 
