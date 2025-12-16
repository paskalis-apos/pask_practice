#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int dist = 1;
    while(dist <= n) {
        for(int i = 1;i <= n - dist;i++) {
            cout << i << " " << i + dist << endl;
            cout.flush();
            int x;
            cin >> x;
            if(x == -1) {
                exit;
            }
            if(x == 1){
                return;
            }
        } 
        dist++;
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}