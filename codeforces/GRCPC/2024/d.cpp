#include<bits/stdc++.h>
using namespace std;

int main( ){
    string s;
    cin >> s;
    int m ;
    cin >> m;
    set<string> info ;
    for(int i = 0; i < m ;i++) {
        string temp;
        cin >> temp;
        info.insert(temp);
    }

    vector<int> reachfrom(s.size() + 1);
    for(int i = 0;i <= s.size() ;i++) {
        reachfrom[i] = i;
    }
    for(int i = 0;i < s.size();i++) {
        string temp;
        for(int j = i + 1; j <= s.size() ;j++){
            temp.push_back(s[j - 1]);
            if(info.find(temp) != info.end()) {
                reachfrom[j] = min(reachfrom[j], reachfrom[i]);
            }
        }
    }

    int ans = 0;
    for(int i = 0;i <=   s.size() ;i++) {
        ans = max(ans, i - reachfrom[i]);
    }

    cout << ans << endl;


}