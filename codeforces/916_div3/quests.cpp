#include<bits/stdc++.h>
using namespace std;
vector<int> firsts, afters;
int n , k;

bool valid(int mid) {
    int maxvalue = 0;
    int index = 0;
    int cursum = 0;
    while(index < n && index < k) {
        cursum += firsts[index];
        maxvalue = max(maxvalue, afters[index]);
        if(maxvalue * (k - index - 1) + cursum >= mid) {
            return true;
        }
        index++;
    }
    return false;
    
}

void solve() {
    cin >> n >> k;
    firsts.assign(n , 0);
    afters.assign(n, 0);
    for(auto &x : firsts) {
        cin >> x;
    }
    for(auto &x : afters) {
        cin >> x;
    }

    int l = 0;
    int r = 1e9;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    int answer = l;
    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i< t; i++) {
        solve();
    }
}