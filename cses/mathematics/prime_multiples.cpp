#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll n , k;
    cin >> n >> k;
    vector<ll> v(k);
    for(auto &x : v){
        cin >> x;
    }

    ll Maxbit = 1;
    for(int i = 1 ;i <=k ;i++) {
        Maxbit *= 2;
    }

    vector<ll> divisors(k + 1, 0);

    for(ll bit = 1; bit < Maxbit; bit++) {
        ll curnum = 1;
        ll curdivs = 0;
        for(int j = 0;j < k; j++) {
            if((bit | (1 << j)) == bit) {
                curdivs++;
                if(n / curnum < v[j]) {
                    curdivs = -1;
                    break;
                }
                curnum *= v[j];
            }
        }
        if(curdivs <= 0) {  
            continue;
        }

        divisors[curdivs] += (n / curnum);
    }

    ll ans = 0;
    for(int i = 1; i <= k ;i++) {
        if(i % 2 == 1) {
            ans += divisors[i];
        }
        else {
            ans -= divisors[i];
        }
    }

    cout << ans << endl;
}