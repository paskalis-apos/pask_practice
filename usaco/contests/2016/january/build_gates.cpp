#include<bits/stdc++.h>
using namespace std;


int n;
vector<vector<bool>> fence;
vector<vector<bool>> visited;

int main() {
    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);
    cin >> n;
    fence.resize(2* n + 1, vector<bool>(2 * n + 100));
    visited.resize(2 * n + 1, vector<bool>(2 * n  + 100));
    set<pair<pair<int,int>, pair<int,int>>> s;
    int doors = 0;

    int x = n;
    int y = n;
    fence[y][x] = true;

    for(int i = 0 ;i < n ;i++) {
        char temp;
        cin >> temp;
        int xprev = x;
        int yprev = y;
        if(temp == 'N') {
            y++;
        }
        else if(temp == 'S') {
            y--;
        }
        else if(temp == 'E') {
            x++;
        }
        else{
            x--;
        }
        
        if(fence[y][x] == true) {
            if(s.find({{yprev , xprev},{y , x}}) == s.end() && s.find({{y , x},{yprev , xprev}}) == s.end()){
                doors++;
            }
        }
        fence[y][x] = true;
        s.insert({{yprev , xprev},{y , x}});  
    }


    cout << doors << endl;
}