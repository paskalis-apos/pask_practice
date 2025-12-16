#include<bits/stdc++.h>
using namespace std;
int n , m;
vector<pair<int,int>> sortedtimes;
vector<int>v;

bool valid(int mid) {
    int opponentswins = mid + 1;
    int mywins = 0;
    bool includecheck = false;
    int ind = 0;
    int cursum = 0;
    while(ind < n && cursum + sortedtimes[ind].first <= m) {
        cursum += sortedtimes[ind].first;
        if(sortedtimes[ind].second == mid) {
            includecheck = true;
            opponentswins--;
        }
        ind++;
        mywins++;
    }
    if(mywins >= opponentswins) {
        return true;
    }
    if(!includecheck && ind > 0) {
        ind--;
        cursum -= sortedtimes[ind].first;
        cursum += v[mid];
        opponentswins--;
        if(cursum <= m && mywins >= opponentswins) {
            return true;
        }

    }
    return false;
}

void solve() {
    cin >> n >> m;
    sortedtimes.resize(n);
    v.resize(n);
    for(int i = 0 ; i < n ;i++) {
        cin >> sortedtimes[i].first;
        v[i] = sortedtimes[i].first;
        sortedtimes[i].second = i;
    }

    sort(sortedtimes.begin(),sortedtimes.end());

    int l = -1;
    int r = n - 1;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    int answer = n - l;
    cout << answer << endl;

}

int main(){ 
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}