#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a/gcd(a,b)*b 
#define setbits(n) __builtin_popcountll(n)                  
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
#define endl '\n'
#define roundof(n,x) cout << fixed << setprecision(x) << n << endl
 
#define int int64_t
#define pb push_back
#define ff first
#define ss second 
#define mkp make_pair
#define mkt make_tuple
#define pii pair<int,int>
#define vpii vector<pii>
#define ppiii pair<pii,int>
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)

const int maxS = 2e5 + 5;
const int maxN = 1e3 + 5;
const int maxM = 20;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const double PI = acos(-1);
 
int di[8] = {-1,-1,-1,0,0,1,1,1};
int dj[8] = {-1,0,1,-1,1,-1,0,1};

// U , L , D , R
int dx[4] = { 0 , 1 , 0 , -1};
int dy[4] = { 1 ,0 , -1 , 0};
    
template<typename T>
using index_set = tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;
    //find_by_order(k) --> returns pointer to Kth smallest element or pointer to kth index
    //order_of_key(k) --> returns index of element K

template <typename T>
using minHeap = priority_queue<T,vector<T>,greater<T>>;

template <typename T>
using maxHeap = priority_queue<T>;
 
template <typename T> ostream& operator<<(ostream& cout,vector<T> res) {
    for(T& ele : res) {  
        cout << ele << endl;
    }
    return cout;
}
 
template<typename T> istream& operator>>(istream& cin,vector<T>& input) {
    for(T& ele : input) {
        cin >> ele;
    }
    return cin;
}

void solve() {  
    
}

void inline read_file() {
    #ifndef ONLINE_JUDGE 
        //for reading input from input1.txt 
        freopen("input.txt", "r" ,stdin);
        //for writing output to output1.txt
        freopen("output.txt", "w" ,stdout);
    #endif
}   
 
int32_t main() {
         
    read_file();
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
        
    int tests = 1;
    cin >> tests;

    while(tests-- > 0) {
        //cout << "Case #" << cnt++ << ": ";
        solve();
    } 
 
    return 0; 
}