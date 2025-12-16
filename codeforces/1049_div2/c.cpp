#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    priority_queue<ll> left;
    priority_queue<ll> right;
    ll ans = 0;
    ll add = n - 1 - (n + 1) % 2;
    for(int i = 0;i < n; i++) {
        ll num;
        cin >> num;
        if(i % 2 == 0){ 
            if(!left.empty()) {

                add = max(add, i - 2 *num + left.top());
            }
            right.push(-2 * num - i);
            ans += num;
        }
        else {
            if(!right.empty()) {
                add = max(add, i + 2 *num + right.top());
            }
            left.push(2 * num - i);
            ans -= num;
        }
    }

    ans += add;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}