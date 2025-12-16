#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n , d;
    cin >> n >> d;

    cout << 1 << " ";
    if(d % 3 == 0 || n >= 3) {
        cout << 3 << " ";
    }
    if(d % 5 == 0 ) {
        cout << 5 << " ";
    }
    if(d % 7 == 0 || n >= 3) {
        cout << 7 << " ";
    }
    if(d % 9 == 0 || n >= 6 || (d % 3 == 0 && n >= 3)) {
        cout << 9 << " ";
    }
    cout << endl;
}

int main(){ 
    int t;
    cin >> t;
    for(int i = 0; i < t ;i++) {
        solve();
    }
}