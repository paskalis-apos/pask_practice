#include<bits/stdc++.h>
using namespace std;

struct cas{
    int l, r , real;
    bool operator<(cas &b) {
        return  real < b.real;
    }
};

void solve() {
    int n , k;
    cin >> n >> k;

    vector<cas> info(n);
    for(auto &x : info) {
        cin >> x.l >> x.r >> x.real;
    }

    sort(info.begin(), info.end());
    int ind = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(info[i].l <= k && info[i].r >= k) {
            if(info[i].real < k) {
                break;
            }
            k = info[i].real;
            ind = i + 1;
            break;
        }
    }
    while(ind != -1 && ind < n) {
        if(k >= info[ind].l && k <= info[ind].r) {
            k = info[ind].real;
        }
        ind++;
    }

    cout << k << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i =0; i < t; i++) {
        solve();
    }
}