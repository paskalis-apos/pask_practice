#include<bits/stdc++.h>
using namespace std;

int mythrow(int num){ 
    cout << "throw " << num << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void myswap(int num){ 
    cout << "swap " << num << endl;
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    vector<int> dist(n + 2);
    dist[n] = 1;
    for(int i = n - 1; i > 0 ;i--){ 
        if(dist[i + 1] == dist[i + 2]) {
            dist[i] = dist[i + 1] + 1;
            continue;
        }
        dist[i] = mythrow(i);
    }

    vector<int> ans(n + 1);
    for(int i = 1;i < n;i++){ 
        if(dist[i + 1] == dist[ i + 2]) {
            myswap(i);
            int cur = mythrow(i + 1);
            if(cur == dist[i + 2] + 1){ 
                ans[i] = 1;
            }
            else {
                ans[i] = 2;
            }
            ans[i + 1] = 2;
            i++;
        }
        else {
            if(dist[i] == dist[i + 1] + 1) {
                ans[i] = 1;
            }
            else {
                ans[i] = 2;
            }
        }
    }
    myswap(n - 1);
    int num = mythrow(n - 1);
    if(num == 1){
        ans[n] = 2;
    }
    else {
        ans[n] = 1;
    }
    cout << "! ";
    for(int i = 1;i <= n;i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve() ;
    }
}