#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod ll(1e9 + 7);

ll calc(int a , int b) {
    if(b == 0) {
        return 1;
    }
    ll answer = calc(a, b / 2);
    answer %= mod;
    answer *= answer;
    answer %= mod;
    if(b % 2 == 1) {
        answer *= a;
    }
    return answer % mod;
}

void solve() {
    ll a , b;
    cin >> a >> b;
    ll answer = calc(a , b); 
    cout << answer << endl;
}

int main() {
    ll n;
    cin >> n;
    for(int i = 0 ;i < n; i++) {

        solve();
    }
}