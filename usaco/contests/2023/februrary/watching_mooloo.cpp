#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , k;
    cin >> n >> k;

    vector<ll> days(n);
    for(auto &x : days) {
        cin >> x;
    }
    ll money_need = k + 1;


    sort(days.begin(),days.end()); 
    for(int i = 1; i < n; i++ ) {
        money_need += min(k + 1 ,days[i] - days[i-1]);
    }

    cout << money_need << endl;
}