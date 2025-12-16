#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll x;
    cin >> x;
    vector<ll> prefsum(x + 1);

    for(int i = 1; i <= x; i++) {
        ll temp;
        cin >> temp;

        prefsum[i] = (prefsum[i-1] + temp) % x;
        if(prefsum[i] < 0) {
            prefsum[i] = x + prefsum[i];
        }
    }

    map<ll , ll> count;
    count[0]++;

    ll answer = 0;
    for(int i = 1; i<= x;i ++) {
        answer += count[prefsum[i]] ;
        count[prefsum[i]]++;
    }

    cout << answer << endl;
}