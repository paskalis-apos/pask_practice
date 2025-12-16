#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int rownum , colnum;
    cin >> rownum >> colnum;
    string s;
    cin >> s;
    
    vector<vector<ll>> grid(rownum , vector<ll>(colnum));
    vector<ll>colsum(colnum);
    vector<ll>rowsum(rownum);
    for(int i = 0;i < rownum;i++){
        for(int j =0; j< colnum; j++) {
            cin >> grid[i][j];
            colsum[j] += grid[i][j];
            rowsum[i] += grid[i][j];
        }
    }
    vector<ll>passedfromcol(colnum);
    vector<ll>passedfromrow(rownum);
    vector<ll> cun(colnum);
    ll x = 0;
    ll y = 0;
    ll counter = 0;
    while(y < rownum  && x < colnum) {
        grid[y][x] = -INT_MAX;
        passedfromcol[x]++;
        passedfromrow[y]++;
        if(s[counter] == 'D') {
            y++;
        }
        else {
            x++;
        }
        counter++;
    }

    if(passedfromcol[0] == 1) {
        grid[0][0] = 0 - colsum[0];
    }
    else {
        grid[0][0] = 0 - rowsum[0];
    }
    colsum[0] += grid[0][0];
    rowsum[0] += grid[0][0];
    passedfromcol[0]--;
    passedfromrow[0]--;

    x = 0;
    y = 0;
    while(x + y <= rownum + colnum - 3) {
        if(y < rownum - 1 && grid[y + 1][x] == -INT_MAX) {
            y++;
        }
        else {
            x++;
        }
        if(passedfromcol[x] == 1) {
            grid[y][x] = 0 - colsum[x];
        }
        else {
            grid[y][x] = 0 - rowsum[y];
        }
        colsum[x] += grid[y][x];
        rowsum[y] += grid[y][x];
        passedfromcol[x]--;
        passedfromrow[y]--;
    }
    
    for(int i = 0;i < rownum;i++){
        for(int j =0; j< colnum; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}