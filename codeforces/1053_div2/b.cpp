#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> blackcells;
    vector<int> extrablack;
    int blacknum = m;
    for(int i = 0;i < m ;i++) {
        int num;
        cin >> num;
        blackcells.insert(num);
    }
    int pos = 1;
    for(auto  &x : s) {
        if(x == 'A') {
            pos++;
            if(blackcells.find(pos) == blackcells.end()) {
                extrablack.push_back(pos);
                blacknum++;
            }
        }
        else {
            pos++;  
            while(blackcells.find(pos) != blackcells.end()) {
                pos++;
            }
            extrablack.push_back(pos);
            blacknum++;
            pos++;
            while(blackcells.find(pos) != blackcells.end()) {
                pos++;
            }
        }
    }

    cout << blacknum << endl;
    int  ind2  = 0;
    for(auto &x : blackcells) {
        while(ind2 < extrablack.size() && extrablack[ind2] < x) {
            cout << extrablack[ind2] << " ";
            ind2++;
        }
        cout << x <<  " ";
    }
    while(ind2 < extrablack.size()) {
        cout << extrablack[ind2] << " ";
        ind2++;
    }
    cout << endl;

}   

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {

        solve();
    }
}