#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n , m;
vector<ll>v;
vector<ll>pref;
ll total ;

bool valid(ll num) {

    total = 0;
    ll l =0;
    ll r = 0;
    ll hands = 0;
    while(hands < m && l <= r) {
        if(l == 0){
            if(v[l] + v[r] >= num) {
                if(m - hands == 1) {
                    total += v[l] + v[r];
                    hands++;
                    continue;
                }
                else if(l == r) {
                    total += v[l] + v[r];
                    hands++;
                    r++;
                    continue;
                }
                total += 2 * (v[r] + v[l]);
                hands += 2;
                if(r < n - 1) {
                    r++;
                }
                else {
                    l++;
                }
            }
            else {
                l++;
            }
        }
        else {
            while(v[l] + v[r] < num) {
                r--;
                if(r < l) {
                    return false;
                }
            }
            if(m - hands >= 2 *(r - l ) + 1) {
                hands += 2 * (r - l) + 1;
                total += 2*(pref[r + 1] - pref[l + 1]) + 2 * (r - l + 1) * v[l];
                l++;
            }
            else {
                while(m - hands < 2 *(r - l) + 1) {
                    r--;
                }
                if((m - hands) % 2 == 1) {
                    total += 2*(pref[r + 1] - pref[l + 1]) + 2 * (r - l + 1) * v[l];
                    hands = m;
                }
                else {
                    total += 2*(pref[r + 1] - pref[l + 1]) + 2 * (r - l + 1) * v[l] + v[l] + v[r + 1];
                    hands = m;
                }
            }
        }
    }
    
    if(hands == m) {
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    v.resize(n);
    pref.resize(n + 1);
    for(int i = 0; i= n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    for(int i= 1; i<= n;i++) {
        pref[i] = pref[i - 1] + v[i - 1];
    }

    ll l = 0, r = 2e5;
    ll answer = 0;
    while(l < r) {
        ll mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
            answer = total;
        }
        else {
            r = mid - 1;
        }
    }




    

    cout << answer << endl;
}