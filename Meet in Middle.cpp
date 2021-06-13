#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
	    
    int n , target;
    cin >> n >> target;
    int val,total = 0;
    vector<int> arr1;
    vector<int> arr2;
    
    for(int i=0;i<n/2;i++) {
        cin >> val;
        arr1.push_back(val);
    }

    for(int i=n/2;i<n;i++) {
        cin >> val;
        arr2.push_back(val);
    }
	
    int size1 = arr1.size();
    int size2 = arr2.size();	    
    vector<int> v,s;

    for(int j = 1 ; j <= 1LL << size1 ; j++) {
        int sum = 0;
        for(int i = 0 ; i < min(size1,32 * 1LL) ; i++) {
            if((j & (1LL << i)) != 0) {
                sum += arr1[i];
            }
        }
        v.push_back(sum);
    }

    for(int j = 1 ; j <= 1LL << size2 ; j++) {
        int sum = 0;
        for(int i = 0 ; i < min(size2,32 * 1LL) ; i++) {
            if((j & (1LL << i)) != 0) {
                sum += arr2[i];
            }
        }
	s.push_back(sum);	    
    }
	
    sort(s.begin(),s.end());
    for(int& sum : v) {
        total += (upper_bound(s.begin(),s.end(),target - sum) - lower_bound(s.begin(),s.end(),target - sum));
    }

    cout << total;
    
    return 0;
}
