#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int k;
vector<int> v;

bool is_valid(ll mid) {
    int total_cows = 0;
    ll prev_cow = -10e10;
    for(int i = 0;i < n && total_cows < k;i++) {
        if(v[i] - prev_cow >=  mid) {
            prev_cow = v[i];
            total_cows ++;
        }
    }

    if(total_cows == k) {
        return true;
    }
    return false;
}


int main() {

    cin >> n >> k;
    v.resize(n);
    for(int i =0 ;i < n;i++) {
        cin >> v[i];
    }

    ll r = 10e9 + 1;
    ll l = 0;

    while (r - l > 1) {
        ll mid = (r + l) /2;
        
        if(is_valid(mid)) {
            l = mid;
        }

        else {
            r = mid;
        }
    }

    cout << l;


}