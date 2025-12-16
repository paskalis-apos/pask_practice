#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll>multiples(1000001);
    vector<ll>lastoc(1000001, -1);
    vector<ll>numsum(1000001);
    ll sum = 0;

    for(int i = 0 ;i < n ;i++) {
        ll temp;
        cin >> temp;

        if(lastoc[temp] == -1) {
            lastoc[temp] = i;
            if(i > 0) {
                multiples[i] = multiples[i - 1];
            }
            continue;
        }
        numsum[temp] = lastoc[temp] - multiples[lastoc[temp]];
        multiples[i] = multiples[i - 1] + 1;
        lastoc[temp] = i; 
    }
    for(auto &x: numsum) {
        sum += x;
    }

    cout << sum;
}