#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n , k;
    cin >> n >> k;

    vector<int> v(n);
    int maxmiddle = 0;
    int maxedge = 0;
    for(int i = 0 ;i < n ;i++) {
        cin >> v[i];
        if(i > 0 && i < n - 1) {
            maxmiddle = max(maxmiddle, v[i]);
        }
        else {
            maxedge = max(maxedge, v[i]);
        }

    }
    ll sum = 0;
    if(k == 1) {
        sum = max(maxmiddle + maxedge, v[0] + v[n - 1]);
        cout << sum << endl;
        return;
    }

    vector<int> sortedv = v;
    sort(sortedv.rbegin(), sortedv.rend());
    

    int mintake = sortedv[k -1];
    bool rest = false;;
    for(int i = 0 ;i <= k ;i++) {
        sum += sortedv[i];
    }
    cout << sum << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
         solve();
    }
}