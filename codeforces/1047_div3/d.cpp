#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> occs(n + 1);
    vector<int> v(n);
    for(int i = 0 ;i< n;i++) {
        int num;
        cin >> num;
        v[i] = num;
        occs[num]++;
    }
    vector<stack<int>> put(n + 1);
    int ind = 1;
    for(int i = 1; i <= n; i++) {
        if(occs[i] == 0) {
            continue;
        }
        if(occs[i] % i != 0) {
            cout << -1 << endl;
            return;
        }   
        for(int j = 0;j < occs[i] / i; j++) {
            for(int k = 0; k < i; k++) {
                put[i].push(ind);
            }
            ind++;
        }
    }
    vector<int> ans;
    for(auto &x : v){ 
        ans.push_back(put[x].top());
        put[x].pop();
    }

    for(auto &x : ans){ 
        cout << x << " ";
    }
    cout << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i< t; i++) {
        solve();
    }
}