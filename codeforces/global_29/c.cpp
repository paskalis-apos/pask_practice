#include<bits/stdc++.h>
using namespace std;
int n;


void solve(){ 
    cin >> n;
    string bs;
    cin >> bs;
    int rabbits = 0;
    vector<string> subv;
    string temp;
    char prev = '2';
    for(int i = 0;i < n;i++) {
        if(bs[i] == prev && prev == bs[i]) {
            subv.push_back(temp);
            temp.clear();
            prev = '2';
        }
        temp += bs[i];
        prev = bs[i];
    }
    subv.push_back(temp);
    
    for(auto &x : subv) {
        bool doublerab = false;
        int rabnum = 0;
        for(int i = 0;i < x.size(); i++) {
            if((i == 0 || i == x.size() - 1) && x[i] == '0') {
                doublerab = true;
                break;
            }
            else if(i < x.size() - 2 && x[i] == '0' && x[i + 1] == '0') {
                doublerab = true;
                break;
            }
            else if(x[i] == '0') {
                rabnum++;
            }
        }
        if(!doublerab && (rabnum % 2 ==1)) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    return;
}


int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}