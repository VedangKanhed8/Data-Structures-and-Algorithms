const int maxN = 2e5 + 7;
int seg_tree[maxN << 2LL];
int arr[maxN];

void build(int ss,int ee,int idx) {
    if(ss == ee) {
        seg_tree[idx] = arr[ss];
        return;
    }

    int mid = (ss + ee) >> 1LL;
    build(ss,mid,2 * idx + 1);
    build(mid+1,ee,2 * idx + 2);
    seg_tree[idx] = seg_tree[2 * idx + 1] + seg_tree[2 * idx + 2];
}

int query(int s,int e,int qs,int qe,int idx) {
    if(qs > e or qe < s) return 0;

    if(qs <= s and e <= qe) return seg_tree[idx];

    int mid = (s + e) >> 1LL;
    int left_sum = query(s,mid,qs,qe,2 * idx + 1);
    int right_sum = query(mid+1,e,qs,qe,2 * idx + 2);
    return left_sum + right_sum;
}

void update(int s,int e,int qind,int new_val,int idx) {
    if(qind > e or qind < s) return;

    if(s == e and s == qind) {
        seg_tree[idx] = new_val;
        return;
    }

    int mid = (s + e) >> 1LL;
    update(s,mid,qind,new_val,2 * idx + 1);
    update(mid+1,e,qind,new_val,2 * idx + 2);
    seg_tree[idx] = seg_tree[2 * idx + 1] + seg_tree[2 * idx + 2];
}
