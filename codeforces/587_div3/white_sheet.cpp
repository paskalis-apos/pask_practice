#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct rect {
    ll lx, ly , rx , ry;
};

int main() {
    rect start;
    rect first, second;

    cin >> start.lx >> start.ly >> start.rx >> start.ry;
    cin >> first.lx >> first.ly >> first.rx >> first.ry;
    cin >> second.lx >> second.ly >> second.rx >> second.ry;
    ll length = start.rx - start.lx;
    ll width = start.ry - start.ly;

    first.lx = max(first.lx, start.lx);
    second.lx = max(second.lx, start.lx);
    first.ly = max(first.ly, start.ly);
    second.ly = max(second.ly, start.ly);
    first.rx = min(first.rx, start.rx);
    second.rx = min(second.rx, start.rx);
    first.ry = min(first.ry, start.ry);
    second.ry = min(second.ry, start.ry);

    ll area1 = (first.ry - first.ly) * (first.rx - first.lx);
    ll area2 = (second.ry - second.ly) * (second.rx - second.lx);

    if(area1 == length * width || area2 == length * width) {
        cout << "NO" << endl;
        return 0;
    }

    if(first.rx - first.lx == length && second.rx - second.lx == length) {
        if(min(second.ry, first.ry) - max(first.ly , second.ly) >= 0) {
            if(max(second.ry, first.ry) - min(first.ly , second.ly) == width) {
                cout << "NO" << endl;
                return 0 ;
            }
        }
    }
    if(first.ry - first.ly == width && second.ry - second.ly == width) {
        if(min(second.rx, first.rx) - max(first.lx , second.lx) >= 0) {
            if(max(second.rx, first.rx) - min(first.lx , second.lx) == length) {
                cout << "NO" << endl;
                return 0 ;
            }
        }
    }

    cout << "YES" << endl;

    


}