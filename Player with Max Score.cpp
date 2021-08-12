
const int maxN = 1e3 + 5;
dp[maxN][maxN][2];

int find_max_score_for_player1(int* piles , int first_index , int last_index , bool player1_will_move) {
    // Base Case
    if(first_index > last_index) return 0; 
  
    // Check up if state already calculated
    if(dp[first_index][last_index][player1_will_move] != -1) return dp[first_index][last_index][player1_will_move];
  
    if(player1_will_move) {
        int take_first_pile = piles[first] + find_max_score_for_player1(piles , first_index + 1 , last_index , !player1_will_move);
        int take_last_pile = piles[last] + find_max_score_for_player1(piles , first_index , last_index - 1, !player1_will_move);
        dp[first][last][player1_will_move] = max(take_first_pile,take_last_pile);
    }
  
    else {
        int take_first_pile = find_max_score_for_player1(piles , first_index + 1 , last_index , !player1_will_move);
        int take_last_pile = find_max_score_for_player1(piles , first_index , last_index - 1, !player1_will_move);
        dp[first][last][player1_will_move] = min(take_first_pile,take_last_pile);
    }
  
    return dp[first][last][player1_will_move];
}
