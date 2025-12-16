#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b;
string s;
int n;
void make_string(int ind) {
    if(ind == n) {
        cout << "? 2 " << a << " " <<  ind << endl;
        fflush(stdout);
        ll ans;
        cin >> ans;
        if(ans == 0) {
            s += '(';
        }
        else {
            s += ')';
        }
        return;
    }
    cout << "? ";
    cout << 7 << " ";
    cout << ind << " " << b << " " << b << " " << a << " " << b << " " << a << " " << ind + 1 << endl;
    fflush(stdout);
    ll ans ;
    cin >> ans;
    if(ans == 1) {
        s+= ")(";
    }
    else if(ans == 2) {
        s += "((";
    }
    else if(ans == 3) {
        s += "))";
    }
    else {
        s += "()";
    }
}

ll check(int l , int r) {
    cout << "? ";
    cout << r - l + 1 << " ";
    while(l <= r) {
        cout << l << " ";
        l++;
    }
    cout << endl;
    fflush(stdout);
    ll temp;
    cin >> temp;
    return temp;
}

void solve() {
    cin >> n;
    s.clear();
    ll regs;
    regs = check(1 , n);
    bool skip = false;
    if(regs == 0) {
        skip = true;
        a = n;
        b = 1;
    }
    else {
        int l = 1;
        int r = n;
        while(l < r - 1) {
            int mid = (l + r) / 2;
            if(check(l , mid) > 0) {
                r = mid;
            }
            else if(check(mid , r) > 0) {
                l = mid;
            }
        }
        a = l;
        b = r;
    }

    int ind = 1;


    cout << "! " << s << endl;
    fflush(stdout);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}