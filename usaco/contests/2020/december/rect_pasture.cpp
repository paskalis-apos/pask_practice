#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<ll,ll> a , pair<ll,ll>b) {
    return a.second < b.second;
}

int prefnum(int x1, int x2 ,int y1 ,int y2,vector<vector<int>> &p) {
    swap(x1, y1);
    swap(x2, y2);
    return p[y2][x2] - p[y1 - 1][x2] - p[y2][x1 - 1] + p[y1 - 1][x1 - 1];
}



int main() {
    int numcows;
    cin >> numcows;

    vector<pair<ll,ll>> cows(numcows);
    for(auto &x : cows) {
        cin >> x.first >> x.second;
    }

    map<pair<int,int>, bool> cowexist;
    vector<vector<int>> prefcows(numcows + 1, vector<int>(numcows + 1, 0));
    
    sort(cows.begin(), cows.end());
    for(int i = 0;i < numcows; i++) {
        cows[i].first = i + 1;
    }

    sort(cows.begin(),cows.end(), cmp);
    for(int i = 0;i < numcows; i++) {
        cows[i].second = i + 1;
        prefcows[cows[i].first][cows[i].second]++;
    }
    

    for(int i = 1; i <= numcows; i++) {
        for(int j = 1; j <= numcows; j++) {
            prefcows[i][j] += prefcows[i - 1][j] + prefcows[i][j - 1] - prefcows[i - 1][j - 1];
        }
    }

    ll answer = 0;

    for(int i = 0 ; i < numcows; i++) {
        for(int j = 0; j < i; j++) {
            int xmax = max(cows[i].first, cows[j].first);
            int xmin = min(cows[i].first, cows[j].first);
            int ymax = max(cows[i].second, cows[j].second);
            int ymin = min(cows[i].second, cows[j].second);

            int a = prefnum(xmin ,xmax, ymax, numcows, prefcows);
            int b = prefnum(xmin, xmax, 1, ymin, prefcows);

            answer += a * b;
        }

    }
    answer += numcows + 1;
    cout << answer << endl;

}