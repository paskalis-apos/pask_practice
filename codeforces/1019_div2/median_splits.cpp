#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , k;
    cin >> n >> k;
    vector<int >v(n);
    for(auto &x : v){ 
        cin >> x;
    }
    vector<int> pref(n);
    int minpref = INT_MAX;
    vector<int> suff(n);
    int maxsuf = -1;
    if(v[0] <= k) {
        pref[0] = 1;
        minpref = 0;
    }
    else {
        pref[0] = -1;
    }
    for(int i = 1;i < n; i++) {
        pref[i] = pref[i -1];
        if(v[i] <= k) {
            pref[i]++;
        }
        else {
            pref[i]--;
        }
        if(pref[i] >= 0 && pref[i] > pref[i - 1]) {
            if(minpref < i) {
                cout << "YES" << endl;
                return;
            }
            else {
                minpref = i;
            }
        }
    }
    if(v[n - 1] <= k) {
        suff[n - 1] = 1;
        maxsuf = n -1;
    }
    else {
        suff[n - 1] = -1;
    }
    for(int i = n -2 ; i>= 0; i--) {
        suff[i] = suff[i + 1];
        if(v[i] <= k) {
            suff[i]++;
        }
        else {
            suff[i]--;
        }
        if(suff[i] >=0 && suff[i] > suff[i + 1]) {
            if(maxsuf > i) {
                cout << "YES" << endl;
                return;
            }
            else {
                maxsuf = i;
            }
        }
    }

    if(minpref < maxsuf) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}