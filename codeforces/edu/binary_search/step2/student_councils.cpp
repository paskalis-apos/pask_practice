#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n , k;
vector<int> a;


ll works(ll mid) {
    ll ai = 0;
    ll ci = 0;
    ll cj = 0;
    while (ai < n && ci < k) {
        if(a[ai] >= mid) {
            ci++;
        }
        else {
            cj += a[ai];
            if(cj >= mid) {
                cj %= mid;
                ci++;
            }
        }
        ai++;
    }

    if (ci == k) {
        return true;
    }
    else {
        return false;
    }
}




int main() {

    cin >> k >> n;
    a.resize(n);

    ll total_students;
    for(int i = 0 ;i < n;i ++) {
        cin >> a[i];
        total_students += a[i];
    }
    sort(a.begin(), a.end());

    ll l = 0;
    ll r = total_students / k + 1;

    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if(works(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }


    
    cout << l;

    
}