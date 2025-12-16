#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , x;
    cin >> n >> x;
    int wallbefore = -1;
    int wallafter = -1;
    for(int i = 1 ;i <= n ;i++) {
        char c;
        cin >> c;
        if(c == '#') {
            if(i > x ) {
                if(wallafter == -1) {

                    wallafter = i;
                }
            }
            else {
                wallbefore = i;
            }
        }
    }
    int ans = 0;
    if(wallafter == -1 && wallbefore == -1) {
        cout << 1 << endl;
        return;
    }
    else if(wallafter != -1 && wallbefore != -1) {
        int ans1 = min(n - wallafter + 2, x);
        int ans2 = min(n - x + 1, wallbefore + 1);
        ans = max(ans1, ans2);
    }
    else if(wallafter != -1) {
        ans = min(n - wallafter + 2, x );
    }
    else {
        ans = min(n - x + 1, wallbefore + 1);
    }
    
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ; i< t ;i++) {
        solve();
    }
}