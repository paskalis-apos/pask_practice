#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k , n;
    cin >> n >> k;
    string s;
    cin >> s;
    int ups = 0, downs = 0;
    for(auto &x : s) {
        if(x == '0') {
            ups++;
        }
        else if(x == '1') {
            downs++;
        }
    }

    for(int i = 1;i <= n;i++) {
        if(k== n || i <= ups || (n - i) < downs) {
            cout << '-';
        }
        else if(k  - downs < i && k - ups <= n - i) {
            cout << "+";
        }
        else {
            cout << "?";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}