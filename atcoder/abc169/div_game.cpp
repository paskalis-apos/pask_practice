#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll n;
    cin >> n;

    ll opps = 0;
    for(ll i = 2;i * i <= n; i++){
        ll count = 0;
        while(n % i == 0) {
            n /= i;
            count++;
        }
        for(int j = 1;count >= j; j++) {
            count-= j;
            opps++;
        }
    }
    if(n > 1) {
        opps++;
    }
    

    cout << opps << endl;
}