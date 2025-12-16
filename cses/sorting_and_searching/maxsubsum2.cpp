#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , a , b;
    cin >> n >> a >>  b;

    vector<ll> v(n + 1);
    for(int i = 1 ;i <= n ;i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    multiset<ll> ms;    
    for(int i = a ;i <= b; i++) {
        ms.insert(v[i]);
    }

    ll cursum;
    ll maxsum = -1e17;

    for(int i = 0 ;i + a <= n ;i++) {
        cursum = *prev(ms.end()) - v[i];
        if(i + b < n) {
            ms.insert(v[i + b + 1]);
        }

        ms.erase(ms.find(v[i + a]));
        maxsum = max(maxsum, cursum); 
    }

    cout << maxsum << endl;
}