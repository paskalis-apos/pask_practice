#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void check_case() {
    int length , height;
    cin >> height >> length;

    vector<string> grid(height);
    for(int i = 0;i < height;i ++) {
        cin >> grid[i];
    }
    int mdist = (min(height, length) + 1) / 2;
    ll apperances = 0;
    

    for(int closetowalls = 1;closetowalls <= mdist; closetowalls++) {
        int sign_to_stop = 0;
        int x = closetowalls - 1;
        int y = closetowalls - 1;
        string temp;
        do {
            temp +=  grid[y][x];
            if(temp == "1543") {
                apperances++;
            }
            if(temp.size() == 4) {
                temp.erase(temp.begin());
            }
            if( y == height - closetowalls) {
                if(x == closetowalls - 1) {
                    y--;
                }
                else {
                    x--;
                }
            }
            else if(x == length - closetowalls) {
                y++;
            }
            else if(y == closetowalls - 1) {
                x++;
            }
            else if(x == closetowalls - 1) {
                y--;
            }
            if(sign_to_stop != 0) {
                sign_to_stop++;
            }
            if(x == closetowalls - 1 && y == closetowalls -1) {
                sign_to_stop = 1;
            }
        }
        while (sign_to_stop < 4);
    }

    cout << apperances << endl;

}


int main() {
    int t;
    cin >> t;

    for(int i = 0 ;i < t; i++) {
        check_case();
    }
}