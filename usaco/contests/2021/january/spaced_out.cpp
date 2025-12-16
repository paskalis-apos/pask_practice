#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>>grid(n);
    for(int i = 0 ;i < n ;i++) {
        for(int j = 0;j < n; j++) {
            int temp;
            cin >> temp;
            grid[i].push_back(temp);
        }
    }
    int maxcost1 = 0;
    int maxcost2 = 0;
    for(int i = 0 ;i < n ;i++) {
        int cost1 = 0;
        int cost2 = 0;
        for(int j = 0; j < n; j+= 2 ) {
            cost1 += grid[i][j];
        }
        for(int j = 1; j < n ;j+= 2) {
            cost2 += grid[i][j];
        }
        maxcost1 += max(cost1, cost2);
    }
    for(int i = 0 ;i < n ;i++) {
        int cost1 = 0;
        int cost2 = 0;
        for(int j = 0; j < n; j+= 2 ) {
            cost1 += grid[j][i];
        }
        for(int j = 1; j < n ;j+= 2) {
            cost2 += grid[j][i];
        }
        maxcost2 += max(cost1, cost2);
    }
    int answer = max(maxcost1, maxcost2);
    cout << answer << endl;

}