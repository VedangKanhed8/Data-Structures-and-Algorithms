const int maxS = 3e5 + 7;
int dis[maxS];
int relaxent[maxS];
vector<tuple<int,int,int>> edges;
int x;

bool negative_cycle_detection(int n) {
  for(int i = 0 ; i < n ; i++) {
        x = -1;
        for(auto e : edges) {
            int u = get<0>(e);
            int v = get<1>(e);
            int w = get<2>(e);
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                relaxent[v] = u;
                x = v;
            }
        }
    }
    return (x != -1);
}

stack<int> retrieve_cycle() {
    for(int i = 0 ; i < n ; i++) {
        x = relaxent[x];
    }
    
    stack<int> cycle;
    int cur = x;
    do {
        cycle.push(cur);
        cur = relaxent[cur];
    } while(cur != x);

    cycle.push(cur);
  
    return cycle;
}
