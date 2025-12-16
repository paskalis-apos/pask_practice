#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string a;
    string b;
    cin >> a >> b;
    vector<int> apref(n);
    vector<int> bpref(n);
    if(a[0] == '0') {
        apref[0] = -1;
    }
    else {
        apref[0] = 1;
    }
    if(b[0] == '0') {
        bpref[0] = -1;
    }
    else {
        bpref[0] = 1;
    }
    for(int i = 1 ;i < n;i++) {
        apref[i] = apref[i - 1];
        if(a[i] == '0') {
            apref[i]--;
        }
        else {
            apref[i]++;
        }
        bpref[i] = bpref[i - 1];
        if(b[i] == '0') {
            bpref[i]--;
        }
        else {
            bpref[i]++;
        }
    }

    sort(apref.begin(), apref.end());
    sort(bpref.begin(), bpref.end());

    ll ans = 0;
    int ones = 0, zeros = 0;
        for(int i = 0;i < n;i++) {
        if(a[i] == '0') {
            zeros++;
        }
        else {
            ones++;
        }   
        int score = ones - zeros; 
        ll add = bpref.end() - lower_bound(bpref.begin(), bpref.end(), -score);
        ans += zeros * add;
        add = lower_bound(bpref.begin(), bpref.end(), -score) - bpref.begin();
        ans += ones * add;
    }
    ones = 0;
    zeros = 0;
    for(int i = 0;i < n;i++) {
        if(b[i] == '0') {
            zeros++;
        }
        else {
            ones++;
        }   
        int score = ones - zeros; 
        ll add = apref.end() - lower_bound(apref.begin(), apref.end(), -score);
        ans += zeros * add;
        add = lower_bound(apref.begin(), apref.end(), -score) - apref.begin();
        ans += ones * add;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i =0 ;i < t ;i++) {
        solve();
    }
}