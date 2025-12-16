#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k , x;
    cin >> k >> x;

    for(int i = 0;i < k; i++) {
        x *= 2;
    }

    cout << x << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i< t; i++) {
        solve();
    }
}