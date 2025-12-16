#include<bits/stdc++.h>
using namespace std;
vector<string> grid;

void flip(int i , int j) {
    for(int counter1 = 0;counter1 <= i; counter1++) {
        for(int counter2 = 0; counter2 <= j; counter2++) {
            if(grid[counter1][counter2] == '1') {
                grid[counter1][counter2] = '0';
            }
            else {
                grid[counter1][counter2] = '1';
            }
        }
    }
}
 
int main() {
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    int n;
    cin >> n;

    grid.resize(n);
    for(auto &x : grid) {
        cin >> x;
    }
    int flips = 0;
    for(int i = n - 1;i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(grid[i][j] == '1') {
                flips++;
                flip( i , j);
            }
        }
    }

    cout << flips;
}