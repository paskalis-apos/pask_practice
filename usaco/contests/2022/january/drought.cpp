#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve_case() {
    ll numcows;
    cin >> numcows;

    vector<ll> hlevel(numcows) ;
    for(auto &x : hlevel) {
        cin >> x;
    }
    if(numcows == 2) {
        if(hlevel[0] == hlevel[1]) {
            cout << 0 << endl;
        }
        else {
            cout << -1 << endl;
        }

        return;
    }

    auto temp = hlevel;
    ll min_value = hlevel[0];
    for(int i = 1; i < numcows - 1; i+=2) {
        if(hlevel[i] < hlevel[i - 1] ) {
            cout << -1 << endl;
            return;
        }
        ll diff = hlevel[i] - hlevel[i - 1];
        hlevel[i] -= diff;
        hlevel[i + 1] -= diff;
        min_value = min(min_value, hlevel[i]);


    }
    min_value = min(min_value, hlevel[numcows - 1]);
    ll answer = 0;
    for(int i = 0;i < numcows; i++) {
        answer += temp[i] - min_value;
        if(hlevel[i] < 0) {
            cout << -1 << endl;
            return;
        }
    }
    cout << answer << endl;
    


}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve_case();
    }
}