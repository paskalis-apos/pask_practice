#include<bits/stdc++.h>
using namespace std;

struct range {
    int l , r, colour;

    bool operator<(range b) {
        return l < b.l;
    }
};

int main() {
    freopen("art2.in","r",stdin);
    freopen("art2.out","w",stdout);
    int n;
    cin >> n;
    stack<range> s;
    vector<vector<int>>foundin(n + 1);
    vector<int>lastind(n + 1);
    vector<range> ranges;
    vector<range>v;
    vector<int> zeroind;
    vector<int> inc(n + 1 , 1);
    zeroind.push_back(0);

    for(int i = 1; i <= n ;i++) {
        int col;
        cin >> col;
        if(col == 0) {
            zeroind.push_back(i);
            continue;
        }
        foundin[col].push_back(i);
        if(lastind[col] == 0) {
            v.push_back({i ,i});
        }
        else {
            v.push_back({lastind[col], i});
        }
        lastind[col] = i;
    }
    int prevr = 0;
    int zerocounter = 0;
    for(auto &x : v) {
        while(zeroind[zerocounter] < x.l) {
            if(zerocounter < zeroind.size()) {
                zerocounter++;
            }
            else {
                break;
            }
        }
        if(zeroind[zerocounter] > x.l && zeroind[zerocounter] <x.r) {
            cout << - 1<< endl;
        } 
        while(!s.empty()) {
            if(s.top().l < x.l && s.top().r > x.l) {
                cout << -1 << endl;
                return 0;
            }
            else {
                s.pop();
            }
        }
            s.push(x);
    }

    for(int i = 1 ;i < n ;i++) {
        if(foundin[i].size() > 0) {
            ranges.push_back({foundin[i][0], foundin[i][foundin[i].size() - 1],i });
        }
    }
    prevr = 0;
    int prevcolour = 0;
    int answer = 0;
    sort(ranges.begin(), ranges.end());
    while(!s.empty()) {
        s.pop();
    }
    for(auto &x : ranges) {
        while(!s.empty()) {
            if(x.r > s.top().r) {
                s.pop();
            }
            else {
                break;
            }
        }
        s.push(x);
        answer = max(answer, int(s.size()));
    }

    cout << answer << endl;
}   