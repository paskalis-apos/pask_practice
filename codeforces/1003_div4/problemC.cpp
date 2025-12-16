#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n  , m;
    cin >> n >> m;
    vector<int> a1(n);
    vector<int> a2(m);
    cin >> a1[0];
    bool bigger = false;
    bool smaller = false;
    for(int i = 1; i < n; i++) {
        cin >> a1[i];
    }
    for(auto &x : a2) {
        cin >> x;
    }
    a1[0] = min(a1[0], a2[0] - a1[0]);
    for(int i = 1; i < n ;i++) {
        if(a2[0] - a1[i] >= a1[i - 1]) {
            if(a1[i] >= a1[i - 1]) {
                a1[i] = min(a1[i], a2[0] - a1[i]);
            }
            else {
                a1[i] = a2[0] - a1[i];
            }
        }
    }
    bool valid = true;
    for(int i = 1 ;i < n; i++) {
        if(a1[i] < a1[i - 1]) {
            valid = false;
            break;
        }
    }
    if(valid) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << endl;


    


}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}