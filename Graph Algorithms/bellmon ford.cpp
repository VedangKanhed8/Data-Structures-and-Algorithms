const int maxS = 2e3 + 7;
const int inf = 1LL << 50;

vector<tuple<int,int,int>> edges;
int relaxant[maxS];
int dis[maxS]; // fill(dis,dis+maxS,inf)
bool negavtive_cycle = false;

void shortest_path(int src,int n) {
    dis[src] = 0;
    for(int i = 1 ; i < n ; i++) {
         for(auto e : edges) {
            int u,v,cost; 
            tie(u,v,cost) = e;
            if(dis[u] + cost < dis[v]) {
                dis[v] = dis[u] + cost;
                relaxant[v] = u; 
            }
         }
    }
  
    for(auto e : edges) {
        int u,v,cost; 
        tie(u,v,cost) = e;
        if(dis[u] + cost < dis[v]) {
           negative_cycle = true; 
        }
    }
}
