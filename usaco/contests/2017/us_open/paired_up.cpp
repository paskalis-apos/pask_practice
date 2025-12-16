#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w", stdout);
    int n;
    cin >> n;

    vector<pair<int,int>> cows(n);
    for(auto &x : cows) {
        cin >> x.second >> x.first;
    }
    sort(cows.begin(), cows.end());

    int l = 0;
    int r = n - 1;
    int min_time = 0;
    while ( l <= r) {
        min_time = max(min_time, cows[r].first + cows[l].first);
        int minus = min(cows[l].second , cows[r].second);
        cows[l].second -= minus;
        cows[r].second -= minus;
        if(cows[l].second <= 0) {
            l++;
        }
        if(cows[r].second <= 0) {
            r--;
        }
    }

    cout << min_time << endl;
}