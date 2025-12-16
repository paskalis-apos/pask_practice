#include<bits/stdc++.h>
using namespace std;

void solve() {
    int length, moveright,movedown;
    cin >> length >> moveright >> movedown;

    vector<string> photo(length);
    for(auto &x : photo) {
        cin >> x;
    }

    bool valid = true;
    int stars = 0;

    for(int i = 0 ;i < length && valid; i++) {
        for(int j = 0 ;j < length && valid; j++) {
            if(moveright == 0 && movedown == 0) {
                if(photo[i][j] == 'B') {
                    stars++;
                }
                else if(photo[i][j] == 'G') {
                    valid = false;
                }
                continue;
            }

            if(photo[i][j] == 'B') {
                valid = false;
                continue;
            }
            else if(photo[i][j] = 'W') {
                continue;
            }
            stars++;
            if(i + movedown >= length || j + moveright >= length) {
                continue;
            }
            if(photo[i + movedown][j + moveright] == 'B') {
                photo[i + movedown][j + moveright] == 'G';
            }
            else if(photo[i + movedown][j + moveright] == 'G') {
                photo[i + movedown][j + moveright] = 'W';
            }

        }
    }

    if(valid) {
        cout << stars;
    }
    else {
        cout << -1;
    }
    cout << endl;



}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
        solve();
    }
}