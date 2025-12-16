#include<bits/stdc++.h>
using namespace std;

int main() {
    int size , numq;
    cin >> size >> numq;

    vector<vector<int>> forest(size+1, vector<int>(size+1));

    for(int i = 1; i <= size; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= size; j++) {
            forest[i][j] = forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1];
            if(s[j-1] == '*') {
                forest[i][j]++;
            }
        }
    }

    for(int i = 0;i < numq; i++) {
        int x1 , y1 , x2 , y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int answer = forest[y2][x2] + forest[y1-1][x1-1] - forest[y2][x1-1] -forest[y1-1][x2];
        cout << answer << endl;
    }
}