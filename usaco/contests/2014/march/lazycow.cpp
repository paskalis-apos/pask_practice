#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("lazy.in","r",stdin);
    freopen("lazy.out","w",stdout);
    int gridsize , steps;
    cin >> gridsize >> steps;

    vector<vector<int>>grid(gridsize * 2 + 1, vector<int>(gridsize * 2 + 1));

    for(int i = 1 ;i <= gridsize; i++) {
        for(int j = 1;j <= gridsize; j++) {
            int temp;   
            cin >> temp;

            grid[gridsize + i - j][i + j] = temp;
        }
    }
    for(int i = 1;i <= 2 * gridsize; i++) {
        for(int j = 1; j <= 2 * gridsize; j++) {
            grid[i][j] += grid[i - 1][j] + grid[i][j -1 ] - grid[i - 1][j - 1];
            
        }
    }

    int answer = 0;

    for(int i = 1; i <= 2 * gridsize; i++) {
        for(int j = 1; j<= 2 * gridsize; j++) {
            int backx = max(1 , j - steps);
            int backy = max(1, i - steps);
            backx--;
            backy--;
            int frontx= min(2 * gridsize, j + steps);
            int fronty = min(2 * gridsize , i + steps);

            int sum = grid[fronty][frontx] - grid[fronty][backx] - grid[backy][frontx] + grid[backy][backx];
            answer = max(answer, sum);
        }
    }

    cout << answer << endl;
}