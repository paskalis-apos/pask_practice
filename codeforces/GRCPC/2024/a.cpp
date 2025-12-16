#include<bits/stdc++.h>
using namespace std;


string my_XOR(string a, string b) {
    string ans;
    while(a.size() < b.size()) {
        a.push_back('0');
    }
    for(int i = 0;i < b.size() ;i++) {
        if(a[i] == b[i]) {
            ans.push_back('0');
        }
        else {
            ans.push_back('1');
        }
    }


    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m , k;
    cin >> n >> m >> k;
    vector<string> s(n + 1);
    for(int i = 1 ;i <= n;i++) {
        cin >> s[i];
    }
    s[0] = "";
    vector<int> care(n + 1);
    for(int i = 0; i < m; i++) {
        int  a, b;
        cin >> a >> b;
        care[b] = a;
    }
    for(int i = 0;i < k - 1; i++) {
        vector<string> news(n + 1);
        for(int j = 1;j <= n; j++) {
            news[j] = my_XOR(s[care[j]], s[j]);
        }
        for(int j = 1;j <= n; j++) {
            s[j] = news[j];
        }
    }

    for(int i = 1; i <= n;i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}