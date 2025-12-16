#include<bits/stdc++.h>
using namespace std;
using ll =long long;


int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);

    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        temp *= (i + 1) * (n - i);
        a[i] = temp;
    }
    for(auto &x : b) { cin >> x;}

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    ll total = 0;
    for(int i = 0 ;i < n ;i++) {
        total += a[i] * b[i];
    }

    cout << total;


    


}