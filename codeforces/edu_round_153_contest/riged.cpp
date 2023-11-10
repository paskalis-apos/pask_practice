#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int j = 0 ;j < t ;j++) {

        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        for(int i =0 ;i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        int max_weight = v[0].first;
        int max_endur = v[0].second;

        bool wins = true;
        for(int i = 1;i < n ;i++) {
            if(v[i].first >= max_weight && v[i].second >= max_endur) {
                wins = false;
                break;
            } 
        }
        if(wins == true) {
            cout << max_weight;
        }
        else {
            cout << -1;
        }
        cout << endl;
    }


}