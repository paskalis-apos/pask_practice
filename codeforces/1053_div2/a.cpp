#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    bool stopped = false;
    for(int i = 0;i < m ;i++) {
        cin >> v[i];
        if(stopped) {
            continue;
        }
        if(i == 0){
            continue;
        }
        if(v[i] <= v[i - 1]) {
            cout << 1 << endl;
            stopped = true;
        }
    }
    if(stopped) {
        return;
    }
    cout << n - v[m - 1] + 1 << endl;
     
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}