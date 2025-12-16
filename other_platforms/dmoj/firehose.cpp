#include<bits/stdc++.h>
using namespace std;
vector<int> adress;
int h;
int k;

bool checkforstart(int ind,int mid) {
    int hleft = k;
    hleft--;
    int prevplace = adress[ind] + mid;
    int curind = ind + 1;
    if(curind == h) {
        curind = 0;
        prevplace -= 1e6;
    }
    while(curind != ind) {
        while(abs(adress[curind] - prevplace) <= mid && curind != ind) {
            if(curind == h - 1) {
                curind = 0;
                prevplace -= 1e6;
            }
            else {
                curind++;
            } 
        }
        if(curind == ind) {
            continue;
        }
        hleft--;
        prevplace = adress[curind] + mid;
    }
    return (hleft >= 0);
}

bool valid(int mid) {
        for(int i = 0;i < h ; i++) {
        if(checkforstart(i, mid)) {
            return true;
        }
    }
    return false;
}
int main() {
    cin >> h;
    adress.resize(h);
    for(auto &x : adress) {
        cin >> x;
    }
    sort(adress.begin(), adress.end());
    cin >> k;
    int l = 0;
    int r = 1e6;
    while(l < r) {
        int mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    int ans = l;
    cout << ans << endl;
}