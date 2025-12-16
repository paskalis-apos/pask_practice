#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll n , k;
vector<ll> v;

bool valid(ll mid) {
    int count = 0;
    int i = 0;
    ll temp = 0;
    while(count < k && i < n) {
        if(temp + v[i] > mid) {
            if (v[i] > mid)
                return false;
            temp = v[i];
            count ++;
        }
        else{
            temp += v[i];
        }
        i++;
    }

    if(count == k) {
        return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    v.resize(n);

    for(int i =0 ;i < n; i++) {
        cin >> v[i];
    }
    ll r = 1e14;
    ll l = 0;

    while (r - l > 1) {
        ll mid = (l + r) / 2;

        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r;
    
}