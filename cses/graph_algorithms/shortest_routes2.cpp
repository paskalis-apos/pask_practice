#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n , m , q;
ll adj[501][501];
ll distances[501][501];

int main() {
    cin >> n >> m >> q;
    for(int i = 0 ;i <= 500; i++) {
        for(int j = 0; j <= 500; j++) {
            adj[i][j] = 1e16;
        }
    }
    for(int i = 0 ;i < m ;i++) {
        ll a , b , c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                distances[i][j] = 0;
            }
            else { 
                distances[i][j] = adj[i][j];
            }

        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j =1 ; j <= n ;j++) {
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }

    for(int i = 0 ;i < q ;i++) {
        int a , b;
        cin >> a >> b;
        if(distances[a][b] == 1e16) {
            cout << -1;
        }
        else {
            cout << distances[a][b];
        }
        cout << endl;
    }
}