#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void makeloc(vector<pair<int,int>> &v, string s) {
    int x = v[0].first;
    int y = v[0].second;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'N') {
            y++;
        }
        else if(s[i] == 'E') {
            x++;
        }
        else if(s[i] == 'S') {
            y--;
        }
        else {
            x--;
        }
        v[i + 1] = {x, y};
    }
}

int find_energy(pair<int,int>a, pair<int,int> b){ 
    int energy = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    return energy;
}

int main() {
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);
    int n , m;
    cin >> n >> m;  
    int fx , fy;
    cin >> fx >> fy;
    int bx , by;
    cin >> bx >> by;

    string s1 , s2;
    cin >> s1 >> s2;


    vector<pair<int,int>> floc(n + 1);
    vector<pair<int,int>> bloc(m + 1);
    floc[0] = {fx , fy};
    bloc[0] = {bx , by};

    makeloc(floc , s1);
    makeloc(bloc, s2);

    vector<vector<ll>> dp(n + 1 , vector<ll>(m + 1));
    for(int i = 0; i <= n ;i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            dp[i][j] = INT_MAX;
            if(i > 0) {
                dp[i][j] = min(dp[i][j],dp[i -1][j]);
            }
            if(j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j -1]);
            }
            if(i > 0 && j > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j -1]);
            }
            dp[i][j] += find_energy(floc[i], bloc[j]);
            
        }
    }


    cout << dp[n][m] << endl;
}