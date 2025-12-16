#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve_case() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    int xmin = 0;
    int xmax = 1e9;
    for(int i = 0 ;i < n - 1; i++) {
        if(v[i] == v[i + 1]) {
            continue;
        }
        else if(v[i] < v[i + 1]) {
            xmax = min(xmax,(v[i] + v[i + 1]) / 2);
        }
        else {
            xmin = max(xmin,(v[i] + v[i + 1] + 1) / 2);
            
        }
    }

    if(xmin > xmax) {
        cout << -1 << endl;
        return;
    }
    cout << xmin << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve_case();
    }
}