#include<bits/stdc++.h>
using namespace std;

// Function return map which stores index of next smaller element for current index
// This works in O(size of Input)
unordered_map<int,int> Next_Smaller_Elements(vector<int>& input) { 
    // monotonically increasing stack
    // push the element in stack if its greater than current top
    // pop until we find its correct position
    stack<int> st;
    unordered_map<int,int> next_smaller_idx;
    for(int idx = 0 ; idx < input.size() ; ++idx) {
        while(!st.empty() and input[st.top()] >= input[idx]) {
            next_smaller_idx[st.top()] = idx;
            st.pop();
        }
        st.push(idx);    
    }   
    return next_smaller_idx;
}
