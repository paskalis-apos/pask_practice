#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(m);
    vector<int>colours(n);

    for(int i = 0; i < m; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 4; j++) {
            bool accepted = true;
            for(auto &x : adj[i]) {
                if(colours[x] == j) {
                    accepted = false;
                    continue;
                }
            }
            if(accepted) {
                colours[i] = j;
                break;
            }
        }
    }


    for(auto &x : colours) {
        cout << x;
    }
    cout << endl;


}