#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    stack<int> s;   
    vector<int> prevind(n + 1, -1);
    vector<int> nextind(n + 1, -1);
    for(int i = 0;i < n;i++) {
        while(!s.empty() && v[s.top()] < v[i]) {
            s.pop();
        }
        if(!s.empty()) {
            prevind[i] = s.top();
        }
        s.push(i);
    }
    while(!s.empty()){
        s.pop();
    }
    for(int i = n - 1;i >= 0;i--) {
        while(!s.empty() && v[s.top()] > v[i]) {
            s.pop();
        }
        if(!s.empty()) {
            nextind[i] = s.top();
        }
        s.push(i);
    }

    vector<int> minr(n, INT_MAX);
    for(int i = 0;i < n; i++) {
        if(prevind[i] != -1 && nextind[i] != -1) {
            minr[prevind[i]] = min(minr[prevind[i]], nextind[i]);
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        minr[i] = min(minr[i], minr[i + 1]);
    }

    for(int i = 0;i < q; i++) {
        int l , r;
        cin >> l >> r;
        l--;
        r--;
        if(minr[l] <= r) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}