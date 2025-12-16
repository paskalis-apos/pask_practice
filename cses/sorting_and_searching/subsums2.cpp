#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> prefsum(n + 1);

    for(int i = 1; i <= n; i++) {
        ll temp;
        cin >> temp;

        prefsum[i] = (prefsum[i-1] + temp);
    }

    map<ll , int> count;
    count[0]++;

    ll answer = 0;
    for(int i = 1; i<= n;i ++) {
        answer += count[prefsum[i] - x];
        count[prefsum[i]]++;
    }

    cout << answer << endl;
}