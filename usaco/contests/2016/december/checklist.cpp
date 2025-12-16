#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int find_energy(pair<ll,ll>a , pair<ll,ll> b) {
    ll energy = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); 
    return energy;
}

int main() {
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    ll h , g;
    cin >> h >> g;
    vector<pair<ll,ll>> hcords(h);
    for(auto &x: hcords) {
        cin >> x.first >> x.second;
    }
    vector<pair<ll,ll>> gcords(g);
    for(auto &x : gcords) {
        cin >> x.first >> x.second;
    }

    vector<vector<ll>>dph(h + 1, vector<ll>(g + 1));
    vector<vector<ll>>dpg(h + 1, vector<ll>(g + 1));
    pair<ll,ll> prev = hcords[0];
    for(int i = 2; i <= h; i++) {
        dph[i][0] += dph[i - 1][0];
        dph[i][0] += find_energy(prev, hcords[i -1]);  
        prev = hcords[i -1]; 
        dpg[i][0] = 1e9;
    }

    prev = hcords[0];
    for(int i =1 ;i <= g; i++) {
        dpg[1][i] += dpg[1][i - 1];
        dpg[1][i] += find_energy(prev , gcords[i -1]);
        prev = gcords[i -1];
        dph[1][i] = 1e9;
    }

    for(int i = 2; i <= h ;i++) {
        for(int j = 1; j <= g ; j++) {
            dph[i][j] = dph[i -1][j] + find_energy(hcords[i - 1], hcords[i -2]);
            dph[i][j] = min(dph[i][j], dpg[i -1][j] + find_energy(hcords[i -1], gcords[j -1]));

            dpg[i][j] = dph[i][j -1] + find_energy(hcords[i -1], gcords[j -1]);
            if(j > 1) {
                dpg[i][j] = min(dpg[i][j], dpg[i][j -1] + find_energy(gcords[j -1],gcords[j -2]));
            }

        }
    }

    cout << dph[h][g];
}

