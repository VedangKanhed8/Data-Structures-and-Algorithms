const int maxS = 1e5 + 7;
vector<int> gr[maxS];
bool done[maxS];
bool stk[maxS];

// returns false if topo sort not possible
// works in O(V + E)
bool scheduler(int cur_course,stack<int>& schedule) {
    done[cur_course] = true;
    stk[cur_course] = true;
    
    for(int nbr : gr[cur_course]) {
        if(stk[nbr]) return false;
        else if(!done[nbr] and !scheduler(nbr,schedule)) return false;    
    }

    stk[cur_course] = false;
    schedule.push(cur_course);
    return true;
}

void print_topo_sort(stack<int> schedule) {
    while(!schedule.empty()) {
        cout << schedule.top() << ' ';
        schedule.pop();
    } 
}

void ordering() {
    bool possible = true;
    stack<int> schedule;
    for(int course = 1 ; course <= n ; course++) {
        if(!done[course]) {
            possible &= scheduler(course,schedule);
        }
    }
    
   if(!possible) {
        cout << "CYCLE FOUND : ORDERING NOT POSSIBLE";
        return;
   }
  
    print_topo_sort();
}
