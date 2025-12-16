#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 676767677;

void solve() {
    int n;
    cin >> n;
    // don't know -> 0, left -> 1, right -> 2;
    vector<int> teams(n);
    vector<int> v(n);
    bool same = true;
    for(int i = 0;i < n ;i++) {
        cin >> v[i] ;
        if(i > 0 && v[i] != v[i - 1]){
            same = false;
        }
    }
    if(same) {
        if(v[0] > n / 2 + 1 || v[0] < (n - 1) / 2 + 1) {
            cout << 0 << endl;
            return;
        }
        if(n % 2 == 0){
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
        return;
    }

    for(int i = 1;i < n;i++) {
        if(v[i] == v[i - 1]) {
            if(teams[i - 1] == 1) {
                teams[i] = 2;
            }
            else if(teams[i - 1] == 2) {
                teams[i] = 1;
            }
            else {
                teams[i] = 0;
            }
        }
        else if(v[i] == v[i - 1] - 1) {
            if(teams[i - 1] == 1) {
                cout << 0 << endl;
                return;
            }
            teams[i] = 2;
            bool two = true;
            int j = i - 1;
            while(j >= 0 && teams[j] == 0){
                if(two) {
                    teams[j] = 2;
                }
                else {
                    teams[j] = 1;
                }
                two = !two;
                j--;
            }
        }

        else if(v[i] == v[i - 1] + 1) {
            if(teams[i - 1] == 2) {
                cout << 0 << endl;
                return;
            }
            teams[i] = 1;
            bool two = false;
            int j = i - 1;
            while(j >= 0 && teams[j] == 0){
                if(two) {
                    teams[j] = 2;
                }
                else {
                    teams[j] = 1;
                }
                two = !two;
                j--;
            }
        }
        else {
            cout << 0 << endl;
            return;
        }
    }

    vector<int> prefr(n);
    for(int i = 1;i < n;i++) {
        prefr[i] = prefr[i - 1] + (teams[i] == 2);
    }
    if(prefr[n - 1] != v[0] - 1) {
        cout << 0 << endl;
        return ;
    }

    cout << 1 << endl;
  
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}