#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> q;

    for(int i = 0;i < n; i++) {
        int num;
        cin >> num;
        q.push_back(num);
    }

    for(int i = 1;i <= n ;i++) {
        if(q.front() == i) {
            q.pop_front();
            continue;
        }
        if(q.back() == i) {
            q.pop_back();
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;


}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}