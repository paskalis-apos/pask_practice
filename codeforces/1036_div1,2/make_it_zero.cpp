#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll totalsum = 0;
    for(auto &x : v) {
        cin >> x;
        totalsum += x;
    }
    
    if(totalsum % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    for(auto &x : v) {
        if(x > totalsum / 2) {
            cout << -1 << endl;
            return;
        }
    }

    ll leftsum = 0;
    int ind;
    for(ind = 0; leftsum <= totalsum / 2; ind++) {
        leftsum += v[ind];
    }
    ind --;
    leftsum -= v[ind]; 
    ll middlesum = v[ind];
    ll rightsum = totalsum - middlesum - leftsum;
    if(leftsum == totalsum / 2) {
        cout << 1 << endl;
        for(auto &x : v) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    vector<ll> ans(n);
    ll w = (rightsum + leftsum - middlesum) / 2;
    ll leftmore = leftsum;
    ll middlemore = leftsum - w;
    ll rightmore = w;
    for(int i = 0;i < n;i++) {
        if(i < ind) {
            ans[i] = min(v[i], leftmore);
            leftmore -= ans[i];
        }
        else if(i == ind) {
            ans[i] = min(v[i], middlemore);
            middlemore -= ans[i];
        }
        else if(i > ind) {
            ans[i] = min(v[i], rightmore);
            rightmore -= ans[i];
        }
    }
    cout << 2 << endl;
    for(int i = 0;i < n;i++) {
        cout << ans[i] << " ";
        v[i] -= ans[i];
    }
    cout << endl;
    for(auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}