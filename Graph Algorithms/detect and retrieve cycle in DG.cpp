const int maxS = 2e5 + 7;

vector<int> gr[maxS];
bool vis[maxS];
bool cur_route[maxS];
int parent[maxS];
int src = -1;
int dest = -1;

// O(V + E)
bool dfs(int cur,int par) {
    vis[cur] = true;
    parent[cur] = par;
    cur_route[cur] = true;

    for(int nbr : gr[cur]) {
        if(cur_route[nbr]) {
            src = cur;
            dest = nbr;
            return true;
        }
        else if(!vis[nbr] and dfs(nbr,cur)) {
            return true;
        }
    }

    cur_route[cur] = false;
    return false;
}

stack<int> get_cycle() {
    stack<int> cycle;

    cycle.push(dest);
    while(src != dest) {
        cycle.push(src);
        src = parent[src];
    }
    cycle.push(dest);

    return cycle;
}

bool detect() {
    bool cycle_found = false;
    for(int i = 1 ; i <= n ; i++) {
        if(!vis[i] and dfs(i,0)) {
            cycle_found = true;
            break;
        }
    }
  
    return cycle_found;
}
