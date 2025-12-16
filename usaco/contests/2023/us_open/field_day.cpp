#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll c, n;
    cin >> c >> n;
    vector<ll> bitm(n);

    ll maxpow = 1;
    for(int i = 1; i <= 18; i++) {
        maxpow *= 2;
    }


    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        ll power = 1;
        for(int j = 0;j < c ; j++) {
            if(s[j] == 'H') {
                bitm[i] += power;
            }
            power *= 2;
        }
    }

    vector<ll> dists(maxpow + 1, 1e15);

    queue<ll> q;
    for(auto &x : bitm) {
        q.push(x);
        dists[x] = 0;
    }
    for(auto &x : bitm) {
        for(int i = 0 ;i < c; i++) {
            ll cur = 1 << i;
            x = (x ^ cur);
        }
    }

    while(!q.empty()) {
        ll cur = q.front();
        q.pop();
        for(int i = 0;i < c ;i++) {
            ll diff = 1 << i;
            ll toput = (cur ^ diff);
            if(dists[cur] + 1 < dists[toput]) {
                dists[toput] = dists[cur] + 1;
                q.push(toput);
            }
        }
    }

    for(auto &x : bitm) {
        cout << c - dists[x] << endl;
    }

}