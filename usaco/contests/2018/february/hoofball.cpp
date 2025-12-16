#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hoofball.in","r",stdin);
    freopen("hoofball.out","w",stdout);
    int n;
    cin >> n;

    vector<int> cows(n);
    for(auto &x : cows) {
        cin >> x;
    }

    sort(cows.begin(), cows.end());
    vector<bool> go_left(n);

    for(int i =2; i < n ;i++) {
        int cur_dist = cows[i -1] - cows[i -2];
        int temp_dist = cows[i] - cows[i-1];
        if(temp_dist >= cur_dist) {
            go_left[i - 1] = true;
        }
    }
    go_left[n - 1] = true;
    int min_balls = 0;

    for(int i = 0 ;i < n;) {
        int lcounter = 0;
        int rcounter = 0;
        while(go_left[i] == false && i < n) {
            rcounter++;
            i++;
        }   
        while(go_left[i] == true && i < n) {
            lcounter++;
            i++;
        }

        if(lcounter == 1 || rcounter == 1) {
            min_balls++;
        }
        else {
            min_balls += 2;
        }

    }
    cout << min_balls << endl ;
}