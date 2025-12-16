#include<bits/stdc++.h>
using namespace std;
using dd = long double;

int main() {
    dd n;
    cin >> n;
    stack<pair<dd,dd>> s;
    vector<dd> bsize(n);
    
    for(int i = 0 ;i < n; i++) {
        dd val, msize;

        cin >> val;

        cin >> msize;
        if(s.empty()) {
            bsize[i] = msize;
            s.push({msize , val});
            continue;
        }
        dd rnow = msize;
        while(!s.empty()) {
            dd dist = val - s.top().second;
            dd rprev = s.top().first;
            rnow = min(rnow, (dist * dist) / (4 * rprev));
            if(rnow < rprev) {
                break;
            }
            else {
                s.pop();
            }
        }
        bsize[i] = rnow;
        s.push({rnow , val});
    }


    for(auto &x: bsize) {
        printf("%.3Lf\n", x);
    }   
}