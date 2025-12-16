#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll curup, curdown;
    if(s[0] == '0') {
        curup = 0;
        curdown = n - 1;
    }
    else {
        curup = 1;
        curdown = 0;
    }
    ll ans = 0;
    for(int i = 1;i < n; i++) {
        if(s[i - 1] == '1') {
            if(s[i] == '1') {
                ans = max(ans , curup);
                curup = 1;
                curdown = 0;
            }
            else {
                curup = curup + i;
                curdown = n - i - 1;
            }
        }
        else {
            if(s[i] == '1') {
                ans = max(ans, curup);
                curup = curdown + 1;
            }
            else {
                curup += i;
                curdown += n - i - 1;
            }
        }
    }

    ans = max(ans, max(curup, curdown));
    cout << ans << endl;
}

int main( ){
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}