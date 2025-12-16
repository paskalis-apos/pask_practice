#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    ll peaknum;
    cin >> peaknum;

    vector<pair<ll,ll>> peaks(peaknum);
    for(auto &x : peaks) {
        cin >> x.first >> x.second;
    }
    sort(peaks.begin(), peaks.end());

    ll maxsum = 0;
    ll maxdif = -10000000000;
    int cansee = peaknum;
    for(auto &x : peaks) {
        ll cursum = x.first + x.second;
        if(cursum <= maxsum) {
            cansee--;
            x.first = -1;
            x.second = -1;
        }
        else {
            maxsum = cursum;
        }
    }
    sort(peaks.rbegin(),peaks.rend());
    for(auto &x : peaks) {
        if(x.first == -1) {
            break;
        }
        ll curdif = x.second - x.first;
        if(curdif <= maxdif) {
            cansee--;
        }
        else {
            maxdif = curdif;
        }
    }

    cout << cansee << endl;
    
    
}