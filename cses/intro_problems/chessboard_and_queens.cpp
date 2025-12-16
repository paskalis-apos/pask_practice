#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> board(8);
vector<bool> column(8);
vector<bool> diag1(15);
vector<bool> diag2(15);
int answer = 0;

void search(int y) {
    if(y == 8) {
        answer++;
        return;
    }

    for(int i = 0 ;i < 8; i++) {
        if(board[i][y] || column[i] || diag1[i + y] || diag2[i - y + 7]) {
            continue;
        }
        column[i] = true;
        diag1[i + y] = true;
        diag2[i - y  + 7] = true;
        
        search(y + 1);

        column[i] = false;
        diag1[i + y] = false;
        diag2[i - y + 7] = false;
    }
}


int main() {
    for(int i = 0 ;i < 8;i++) {
        for(int j = 0; j< 8 ;j++) {
            char temp;
            cin >> temp;
            if(temp == '.') {
                board[i].push_back(false);
            }
            else {
                board[i].push_back(true);
            }
        }
    }

        search(0);
        
        cout << answer;
}

