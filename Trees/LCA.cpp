const int maxN = 2e5 + 7;
const int maxM = 20;

vector<int> tr[maxN];
int depth[maxN];
int parent[maxN][maxM];

void dfs(int cur,int par) {

    parent[cur][0] = par;
    for(int p = 1 ; p < maxM; p++) {
        parent[cur][p] = parent[parent[cur][p-1]][p-1];
    }

    for(int nbr : tr[cur]) {
        if(nbr == par) continue;
        depth[nbr] = depth[cur] + 1;
        dfs(nbr,cur);
    }
}

int lca(int u,int v) {
    
    if(depth[u] < depth[v]) swap(u,v);
    
    int diff = depth[u] - depth[v];
    for(int bit = 0 ; bit < maxM ; bit++) {
        if(diff & (1LL << bit)) {
            u = parent[u][bit];
        }
    }

    if(u == v) return u;

    for(int bit = maxM - 1 ; bit >= 0 ; bit--) {
        if(parent[u][bit] != parent[v][bit]) {
            u = parent[u][bit];
            v = parent[v][bit];
        }
    }

    return parent[u][0];
}
