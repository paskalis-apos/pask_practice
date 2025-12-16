#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string w;
    cin >> w;
    int s1 = w.size();
    w[s1 - 1] = ' ';
    w[s1 - 2] = 'i';
    cout << w << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}