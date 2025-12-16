#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , k;
    cin >> n >> k;  

    vector<vector<int>> adj(n);
    for(int i = 1;i < n ;i++) {
        int num;
        cin >> num;
        num--;
        adj[num].push_back(i);
        adj[i].push_back(num);
    }

    vector<int> dist(n, 1e9);
    dist[0] = 0;
    queue<int> q;
    vector<int> freq(n + 1);
    q.push(0);
    int curfreq = 0;
    int curnum = 0;
    int depth = 1e7;
    int important = 0;
    bool have_checked = false;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(adj[cur].size() == 1 && cur != 0) {
            depth = min(depth, dist[cur]);
        }

        if(dist[cur] == curnum) {
            curfreq++;
        }
        else {
            freq[curfreq]++;
            important += curfreq;       
            curfreq = 1;
            curnum++;  
            if(dist[cur] > depth) {
                have_checked = true;
                break;
            }
        }
        for(auto &x : adj[cur]) {
            if(dist[x] != 1e9) {
                continue;
            }
            dist[x] = dist[cur] + 1;
            q.push(x);
        }
    }
    if(!have_checked) {
        freq[curfreq]++;
        important += curfreq;
    }
    vector<int> v;
    for(int i = 1; i < n ;i++) {
        if(freq[i] == 0) {
            continue;
        }
        while(freq[i] > 2) {
            freq[i] -= 2;
            freq[2 * i]++;
        }
        while(freq[i] > 0){ 
            v.push_back(i);
            freq[i]--;
        }
    }

    vector<bool> dp(n + 1);
    dp[0] = true;
    for(auto &x : v) {
        for(int i = n; i >= 0; i--) {
            if(dp[i]) {
                dp[i + x] = true;
            }
        }
    }
    int helppos = n - important;
    int mindiff = 0;
    for(int i = k;i >= 0; i--) {
        if(dp[i]) {
            mindiff = k - i;
            break;
        }
    }
    if(mindiff <= helppos) {
        cout << depth + 1;
    }
    else {
        cout << depth;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}