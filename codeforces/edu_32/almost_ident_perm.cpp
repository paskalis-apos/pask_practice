#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n ,k;
ll chose(ll a ,ll b) {
    ll ans = 1;
    for(int i = 0; i < b ;i++) {
        ans = ans * (a - i) / (i + 1);
    } 
    return ans;  
}

int main() {
    cin >> n >> k;
    vector<ll> fact(6);
    fact[0] = 1;
    for(int i = 1;i <= 5; i++) {
        fact[i] = fact[i -1] * i;
    }

    ll ans = 0;
    for(int i = n - k; i <= n; i++) {
        ll change = chose(n , n - i);
        ll left = fact[n - i];
        for(int j = 1;j <= n - i; j++) {
            if(j % 2 == 1) {
                left -= fact[n - i] / fact[j];
            }
            else {
                left += fact[n - i] / fact[j];
            }
        }
        change *= left;
        ans += change;
    }

    cout << ans << endl;
}