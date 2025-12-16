#include<bits/stdc++.h>
using namespace std;

struct change {
    int cow , day, diff;
    
    bool operator<(const change &temp) {
        return day < temp.day;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    int measurnum , startprod;
    cin >> measurnum >> startprod ;
    int answer = 0;

    map<int,int> cowprod;
    multiset<int> productions;
    productions.insert(startprod);
    vector<change> data(measurnum);
    for(auto &x : data) {
        cin >> x.day >> x.cow >> x.diff;
    }

    sort(data.begin(), data.end());

    for(auto &x : data) {
        if(!cowprod.count(x.cow)) {
            cowprod[x.cow] = startprod;
            productions.insert(startprod);
        }
        if(cowprod[x.cow] == max(*productions.rbegin(),startprod) ) {
            int prev = *next(productions.rbegin());
            if(cowprod[x.cow] == prev) {
                answer++;
            }
            else if(cowprod[x.cow] + x.diff <= prev) {
                answer++;
            }
            
        }
        else if(cowprod[x.cow] + x.diff >= max(*productions.rbegin(), startprod)) {
            answer++;
        }

        productions.erase(productions.find(cowprod[x.cow]));
        cowprod[x.cow] += x.diff;
        productions.insert(cowprod[x.cow]);
    }

    cout << answer;

}