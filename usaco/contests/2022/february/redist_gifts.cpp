#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> gifts;
vector<vector<bool>> possible;
int N;

void dfs(int i , int j) {
    if(possible[i][j]) {
        return;
    }
    possible[i][j] = true;
    for(auto &x : gifts[j]) {
        dfs(i , x);
    }
}

void calc_reach() {
    for(int i = 0 ;i <N ;i++) {
        dfs(i, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    gifts.resize(N);
    possible.resize(N, vector<bool> (N));


    for(int i = 0; i < N; i++) {
        for(int j = 0 ;j < N; j++) {
            int temp;
            cin >> temp;
            temp--;
            gifts[i].push_back(temp);
        }
        while(gifts[i].back() != i) {
            gifts[i].pop_back();
        }
    }

    calc_reach();

    for(int i = 0 ;i < N ;i++) {
        for(auto &x : gifts[i]) {
            if(possible[x][i]) {
                cout << x + 1<< endl;
                break;
            }
        }
    }
}