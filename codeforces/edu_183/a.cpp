#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if(n % 3 == 0){
        cout << 0 << endl;
        return;
    }
    if(n % 3 == 1) {
        cout << 2 << endl;
    }
    else {
        cout << 1 << endl;
    }
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}