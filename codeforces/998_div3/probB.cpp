#include<bits/stdc++.h>
using namespace std;

void solve() {
    int numcows, numcards;
    cin >> numcows >> numcards;

    vector<set<int>> cowcards(numcows);
    for(auto &x : cowcards) {
        for(int i = 0;i < numcards;i++) {
            int temp;
            cin >> temp;
            x.insert(temp);
        }
    }

    for(auto &x : cowcards) {
        for(set<int>::iterator y = x.begin(); y != prev(x.end()); y++) {
            if(*next(y) - *y != numcows) {
                cout << -1 << endl;
                return;
            }
        }
    }

    vector<pair<int,int>> firstelement(numcows) ;
    for(int i = 0 ;i < numcows; i++) {
        firstelement[i].first = *cowcards[i].begin();
        firstelement[i].second = i;
    }

    sort(firstelement.begin(), firstelement.end());
    for(auto &x : firstelement) {
        cout << x.second + 1<< " ";
    }

    cout << endl;
}


int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i ++) {
        solve();
    }
}