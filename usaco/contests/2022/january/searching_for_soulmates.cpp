#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a , ll b){
    if(a == b) {
        return 0;
    }
    else if(a > b) {
        ll isodd = a% 2;
        return isodd + 1 + solve((a + isodd) / 2, b);    
    }
    else {
        ll isodd = b % 2;
        return min(b - a, 1 + isodd + solve(a , b / 2));
    }
}

int main() {

    ll n;
    cin >> n;
    for(int i = 0; i < n;i++) {
        ll cow1 , cow2;
        cin >> cow1 >> cow2;
        cout << solve(cow1, cow2) << endl;
    }
}