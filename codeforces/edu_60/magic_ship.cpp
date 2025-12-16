#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll x1;
ll x2;
ll z1;
ll y2;
ll n;
ll numleft = 0, numup = 0 , numright = 0 , numdown = 0;
string s;

bool valid(ll num) {
    ll newx = x1 + (numright - numleft) * num;
    ll newy = z1 + (numup - numdown) * num;
    ll distance = abs(newx - x2) + abs(newy - y2);
    if(distance <= num * n) {
        return true;
    }
    return false;
}

int main() {
    cin >> x1 >> z1 ;
    cin >> x2 >> y2;
    cin >> n;
    cin >> s;
    for(auto &x : s) {
        if(x == 'U') {
            numup++;
        }
        else if(x == 'L') {
            numleft++;
        }
        else if( x== 'D') {
            numdown++;
        }
        else {
            numright++;
        }
    }

    ll l = 0, r = 2e9;
    while(l < r) {
        ll mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if(l == 2e9) {
        cout << -1 << endl;
        return 0;
    }

    ll startx = x1 + (numright - numleft) * (l - 1);
    ll starty = z1 + (numup - numdown) * (l - 1);

    ll counter = 1;
    bool found = false;
    while(!found) {
        if(s[counter - 1] == 'U') {
            starty++;
        }
        else if(s[counter -1 ] == 'D') {
            starty--;
        }
        else if(s[counter - 1] == 'L') {
            startx--;
        }
        else startx++;
        ll distance = abs(startx - x2) + abs(starty - y2);
        if(distance <= (l -1) * n + counter) {
            found = true;
        }
        else {
            counter++;
        }
    }

    ll answer = (l - 1)* n + counter;
    cout << answer << endl;

    
}