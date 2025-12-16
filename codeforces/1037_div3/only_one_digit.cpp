#include<bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    cin >> s;

    int mindig = 10;

    for(auto &x : s) {
        mindig = min(mindig, x - '0');
    }

    cout << mindig << endl;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ; i++) {
        solve();
    }
}