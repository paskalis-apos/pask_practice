#include<bits/stdc++.h>
using namespace std;

int ask(int x, int l, int r) {
    cout << "? " << x << " " << r - l + 1<< " ";
    for(int i = l; i <= r; i++) {
        cout << i << " ";
    }
    cout << endl;
    cout.flush();
    int num;
    cin >> num;
    return num;
}

void solve() {
    int n;
    cin >> n;
    int r = 2 * n - 1, l = 1;
    vector<pair<int,bool>> should_ask;
    for(int i = 1;i <= n;i++) {
        should_ask.push_back({i, false});
    }
    while(should_ask.size() > 1) {
        int lsize = 0, rsize = 0;
        int m = (r + l) / 2;
        vector<pair<int,bool>> linfo;
        vector<pair<int,bool>> rinfo;
        for(auto &x : should_ask) {
            if(x.second == true) {
                int lcount = ask(x.first, l, m);
                if(lcount == 1) {
                    lsize++;
                    linfo.push_back({x.first, x.second});
                }
                else {
                    rsize++;
                    rinfo.push_back({x.first, x.second});
                }
            }
            else {
                int lcount = ask(x.first, l, m);
                int rcount = ask(x.first, m + 1, r);
                if(lcount == 1 && rcount == 1) {
                    rinfo.push_back({x.first, true});
                    linfo.push_back({x.first, true});
                    rsize++;
                    lsize++;
                }
                else if(lcount == 1) {
                    linfo.push_back({x.first, false});
                    lsize += 2;
                }
                else {
                    rinfo.push_back({x.first, false});
                    rsize += 2;
                }
            }
        }
        should_ask.clear();
        if(rsize != r - m) {
            should_ask = rinfo;
            l = m + 1;
        }
        else {
            should_ask = linfo;
            r = m;
        }
    }

    cout << "! " << should_ask[0].first << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}