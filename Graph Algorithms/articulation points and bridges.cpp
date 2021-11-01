const int maxS = 2e5 + 7;

vector<int> gr[maxS];
int depth[maxS];
int lowest_depth[maxS];
bool vis[maxS];
set<int> art;
set<pii> bridges;

void dfs(int cur,int par) {
    
    vis[cur] = true;
    depth[cur] = lowest_depth[cur] = depth[par] + 1;

    for(int nbr : gr[cur]) {
        if(nbr == par) continue;
        
        if(!vis[nbr]) {
            dfs(nbr,cur);
            lowest_depth[cur] = min(lowest_depth[cur],lowest_depth[nbr]);
        } else {
            lowest_depth[cur] = min(lowest_depth[cur],depth[nbr]);
        }

        if(lowest_depth[nbr] > depth[cur]) bridges.insert({min(cur,nbr),max(cur,nbr)});
        if(cur == 0 and gr[cur].size() > 1) art.insert(cur);
        else if(cur != 0 and lowest_depth[nbr] >= depth[cur]) art.insert(cur);
    }
}
