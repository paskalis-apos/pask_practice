#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll bnum , snum , cnum;
int bprice , sprice , cprice;
int bcount , scount , ccount;
ll rubles;

bool is_valid(ll mid) {
    ll btotal = max(ll(0) ,bcount * mid - bnum);
    ll ctotal = max(ll(0) , ccount * mid - cnum);
    ll stotal = max(ll(0) , scount * mid - snum);

    ll test = rubles;
    test -= btotal * bprice;
    test -= ctotal * cprice;
    test -= stotal * sprice;

    if(test >= 0) {
        return true;
    }
    return false;     

}

int main() {
    string s;
    cin >> s;
    bcount = 0;
    ccount = 0;
    scount = 0;

    for(auto &x : s) {
        if (x == 'C') {
            ccount ++;
        }
        else if(x == 'S') {
            scount++;
        }
        else {
            bcount++;
        }
    }

    cin >> bnum >> snum >> cnum;

    cin >> bprice >> sprice >> cprice;

    cin >> rubles;

    ll r = rubles +  101;
    ll l = 0;

    while (r - l > 1) {
        ll mid = (l + r) / 2;

        if(is_valid(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << l;



    
}