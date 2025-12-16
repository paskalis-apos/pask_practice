#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct pos1{
    ll x, y;
    ll sum;
    bool operator<(pos1 &b){
        return sum < b.sum;
    }
};

struct pos2{
    ll x, y;
    ll sum;
    bool operator<(pos2 &b){
        return sum < b.sum;
    }
};

void ask(ll num, bool horiz) {
    cout << "? ";
    if(horiz) {
        if(num < 0) {
            num = -num;
            cout << "L";
        }
        else {
            cout << "R";
        }
    }
    else {
        if(num < 0) {
            num = -num;
            cout << "D";
        }
        else {
            cout << "U";
        }
    }
    cout << " " << num << endl;
    cout.flush();
}

void solve(){
    ll n;
    cin >> n;
    vector<pos1> points1(n);
    vector<pos2> points2(n);
    for(int i = 0;i < n;i++) {
        cin >> points1[i].x >> points1[i].y;
        points1[i].sum = points1[i].x + points1[i].y;
        points2[i].x = points1[i].x;
        points2[i].y = points1[i].y;
        points2[i].sum = points2[i].x - points1[i].y;
    }
    sort(points1.begin(), points1.end());
    sort(points2.begin(), points2.end());
    ll trash;
    ask(1e9, true);
    cin >> trash;
    ask(1e9, true);
    cin >> trash;
    ask(1e9, false);
    cin >> trash;
    ask(1e9, false);
    ll bigdiff;
    cin >> bigdiff;
    ask(-1e9, false);
    cin >> trash;
    ask(-1e9, false);
    cin >> trash;
    ask(-1e9, false);
    cin >> trash;
    ask(-1e9, false);
    ll smalldiff;
    cin >> smalldiff;

    ll diffx = points1[n - 1].x - points2[n - 1].x;
    ll diffy = points1[n - 1].y - points2[n - 1].y;

    ll y = (diffx - diffy + (bigdiff - smalldiff) + 4 * 1e9) / 2;
    ll x = bigdiff - y;

    x = points1[n-1].x + x;
    x -= 2 * 1e9;
    y = points1[n - 1].y + y;
    y -= 2 * 1e9;

    cout << "! " << x << " " << y << endl;
    cout.flush();
         



}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}