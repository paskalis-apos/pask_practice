#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void check_case() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> cards(m);
    for(int counter1 = 0; counter1 < n; counter1++) {
        for(int counter2 = 0; counter2 < m; counter2++) {
            ll toput;
            cin >> toput;
            cards[counter2].push_back(toput);
        }
    }

    for(int i = 0 ;i  < m; i++) {
        sort(cards[i].begin(), cards[i].end());
    }

    ll answer = 0;

    for(int i =0 ;i < m; i++) {
        for(int j = 0 ;j < n; j++) {
            answer += -(n-1 -j) *cards[i][j];
            answer += j * cards[i][j];
        }
    }
    
    cout << answer << endl;
}



int main() {
    int tcases;
    cin >> tcases;

    for(int i = 0; i < tcases ;i++) {
        check_case();
    }
}