#include<bits/stdc++.h>
using namespace std;

int n , k;
int min_time;

void solve() {
    int maxspeed;
    cin >> maxspeed;
    int speeddist = 0;
    int slowdist = 0;
    int curspeed = 1;
    int time = 0;
    while(true) {
        speeddist += curspeed;
        time++;
        if(speeddist + slowdist >= k) {
            cout << time;
            return;
        }

        if(curspeed >= maxspeed) {
            slowdist += curspeed;
            time++;
            if(speeddist + slowdist >= k) {
                cout <<time;
                return;
            }
        }
        curspeed++;
    }
}

int main(){
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    cin >> k >> n;

    for(int i = 0 ;i < n; i++) {
        solve();
        cout << endl;
    }
}