#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);

    int n;
    cin >>n;

    vector<pair<int,int>> cows(n);
    for(auto &x : cows) {
        cin >> x.first >> x.second;
    }

    sort(cows.begin(), cows.end());

    int time = 0;
    for(int i = 0 ;i < n ;i++) {
        if(time < cows[i].first) {
            time = cows[i].first;
        }
        time += cows[i].second;
    }

    cout << time;
}