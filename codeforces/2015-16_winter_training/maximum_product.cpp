#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll prod(string s) {
    while(!s.empty() && s[0] == '0') {
        s.erase(s.begin());
    }
    if(s.empty()) {
        return -1;
    }
    ll res = 1;
    for(auto &x : s) {
        res *= x - '0';
    }
    return res;
}

int main(){ 
    string l, r;
    cin >> l >> r;
    while(l.length() < r.length()) {
        l.insert(l.begin(), '0');
    }
    string ans = "";
    bool eq = true;
    for(int i = 0;i <= l.length(); i++) {
        string cur = r.substr(0 , i);
        eq = eq && l[i] == r[i];
        if(i < l.length()&& eq) {
            continue;
        }
        if(i < l.length()) { 
            cur += r[i] - 1;
        }
        cur += string(r.length() - cur.length(), '9');
        if(prod(cur) > prod(ans)) {
            ans = cur;
        }
    }

    while(ans[0] == '0') {
        ans.erase(ans.begin());
    }
    cout << ans << endl;
}