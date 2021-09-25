const int maxN = 2e5 + 7;
vector<int> gr[maxN];
int parent[maxN];
bool visited[maxN];
int src = -1;
int dest = -1;

bool cycle_detection(int cur,int par) {

    parent[cur] = par;
    visited[cur] = true;

    for(int nbr : gr[cur]) {
        if(!visited[nbr]) {
            if(cycle_detection(nbr,cur)) return true;
        }
        else if(nbr != par) {
            src = cur;
            dest = nbr;
            return true;
        }
    }
    return false;
}

vector<int> retrieve_cycle() {
    vector<int> cycle;
    for(int node = src ; node ; node = parent[node]) {
        cycle.pb(node);
        if(node == dest) break;
    } 
    cycle.pb(src);
    return cycle;
}
