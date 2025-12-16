#include<bits/stdc++.h>
using namespace std;
vector<bool> prime(1e6 * 5 + 1, true);
vector<vector<int>> primemult(4);

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    pair<int,int> johnwin = {INT_MAX, INT_MAX};
    pair<int,int> nhojwin = {INT_MAX, INT_MAX};
    for(int i = 0 ;i < n;i++) {
        int moves = 0;
        bool forjohn = false;
        if(v[i] % 2 != 0) {
            int left = v[i] % 4;
            auto test = upper_bound(primemult[left].begin(), primemult[left].end(), v[i]);
            test--;
            v[i] -= *test;
            moves++;
            forjohn = true;
        }
        moves += v[i] / 2;
        if(v[i] % 4 == 0) {
            if(forjohn) {
                johnwin = min(johnwin, {(moves) / 2  +1, i});
            }
            else {
                nhojwin = min(nhojwin, {(moves) / 2 + 1, i});
            }
        }
        else {
            johnwin = min(johnwin, {(moves ) / 2 + 1, i});
        }
    }

    if(nhojwin <= johnwin) {
        cout << "Farmer Nhoj" << endl;
    }
    else {
        cout << "Farmer John" << endl;
    }
}



int main() {
    int t;
    cin >> t;
    int Maxval = 1e6 * 5;
    for(int i= 2;i <= Maxval; i++) {
        if(prime[i]) {
            for(int j = 2 * i;j <= Maxval; j+= i) {
                prime[j] = false;
            }
        }
    }
    for(int i = 1; i <= Maxval; i++) {
        if(prime[i]) {
            primemult[i % 4].push_back(i);
        }
    }
    for(int i = 0;i < t ;i++) {
        solve();
    }
}