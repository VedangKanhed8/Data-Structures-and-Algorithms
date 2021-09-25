const int maxN = 2e5 + 7;

vector<int> gr[maxN];
int shortest_distance[maxN];
map<pii,int> length;

void find_shortest_route(int cur,int tot) {
    
    set<pii> st;
    st.insert(mkp(0,cur));
    
    while(!st.empty()) {
        auto ptr = st.begin();
        int len = ptr->ff;
        int par_node = ptr->ss;
    
        for(int nbr : gr[par_node]) {
            if(len + length[mkp(par_node,nbr)] < shortest_distance[nbr]) {
                auto is_nbr = st.find(mkp(shortest_distance[nbr],nbr));
                
                if(is_nbr != st.end()) st.erase(is_nbr);
                
                shortest_distance[nbr] = len + length[mkp(par_node,nbr)];
                st.insert(mkp(shortest_distance[nbr],nbr));
            }
        }

        st.erase(ptr);
    }
}
