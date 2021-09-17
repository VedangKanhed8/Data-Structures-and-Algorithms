
const int maxN = 2e5 + 7;
vector<int> tr[maxN];
int value[maxN];
int sub_size[maxN];
int ft[maxN],t_in[maxN];
int seg_tree[4 * maxN];
int timer = 0;

int dfs(int cur,int par) {

    t_in[cur] = ++timer;

    ft[timer] = value[cur];

    for(int nbr : tr[cur]) {
        if(nbr == par) continue;
        sub_size[cur] += dfs(nbr,cur);
    }
    return ++sub_size[cur];
}

void build_segment_tree(int start,int end,int ind) {
    if(start == end) {
        seg_tree[ind] = ft[start];
        return;
    }

    int mid = (start + end) >> 1LL;
    
    build_segment_tree(start,mid,2 * ind);
    build_segment_tree(mid+1,end,2 * ind + 1);

    seg_tree[ind] = seg_tree[2 * ind] + seg_tree[2 * ind + 1];
}

int query(int start,int end,int qs,int qe,int ind) {
    if(qe < start or qs > end) return 0;

    if(qs <= start and end <= qe) return seg_tree[ind];

    int mid = (start + end) >> 1LL;
    int left_sum = query(start,mid,qs,qe,2*ind);
    int right_sum = query(mid+1,end,qs,qe,2*ind+1);

    return left_sum + right_sum;
}

void update(int s,int e,int up_ind,int new_val,int ind) {
    if(up_ind < s or up_ind > e) return;

    if(s == e) {
        seg_tree[ind] = new_val;
        return;
    }

    int mid = (s + e) >> 1LL;
    update(s,mid,up_ind,new_val,2*ind);
    update(mid+1,e,up_ind,new_val,2*ind+1);
    
    seg_tree[ind] = seg_tree[2*ind] + seg_tree[2*ind+1]; 
}
