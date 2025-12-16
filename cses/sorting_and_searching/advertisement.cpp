#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    stack<pair<ll,int>> q;
    ll maxarea = 0;
    for(int i = 1 ;i <= n; i++) {
        ll val;
        cin >> val;
        int lastoc = 0;
        while(!q.empty()) {
            if(val < q.top().first) {
                maxarea = max(maxarea, q.top().first * (i - q.top().second));
                lastoc = q.top().second;
                q.pop();
            }
            else {
                break;
            }
        }
        if(q.empty() || val > q.top().first) {
            if(lastoc != 0) {
                q.push({val, lastoc});
            }
            else {
                q.push({val, i});
            }
        }
    }
    while(!q.empty()) {
        maxarea = max(maxarea, q.top().first * (n + 1 - q.top().second));
        q.pop();
    }

    cout << maxarea << endl;

}