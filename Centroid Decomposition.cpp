const int maxN = 2e5 + 7;

set<int> copied_tr[maxN];
int sub_size[maxN];
int centroid_parent[maxN];

int find_subtree_size(int cur,int par) {
    for(int nbr : copied_tr[cur]) {
        if(nbr == par) continue;
        sub_size[cur] += find_subtree_size(nbr,cur);
    }
    return ++sub_size[cur];
}

int locate_centroid(int cur,int par,int total_nodes) {
    for(int nbr : copied_tr[cur]) {
        if(nbr != par and sub_size[nbr] > (total_nodes >> 1LL)) {
            return locate_centroid(nbr,cur,total_nodes);
        }
    }
    return cur;
}

void decompose(int cur,int par) {
    memset(sub_size,0,sizeof sub_size);
    
    int total_nodes = find_subtree_size(cur,par);

    int centroid = locate_centroid(cur,par,total_nodes);

    centroid_parent[centroid] = par;

    for(int nbr : copied_tr[centroid]) {
        copied_tr[nbr].erase(centroid);
        decompose(nbr,centroid);
    }
}
