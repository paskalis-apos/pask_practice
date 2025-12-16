#include<bits/stdc++.h>
using namespace std;

void solve() {
    int lilnum , a , b;
    cin >> lilnum >> a >> b;

    if(abs(a - b) % 2 == 0){
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