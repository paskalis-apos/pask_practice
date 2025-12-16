#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("shell.in", "r",stdin);
    freopen("shell.out", "w", stdout);
    vector<int> shell_at_post(3);
    for(int i = 0 ; i< 3; i++) {
        shell_at_post[i] = i;
    }
    int n; 
    cin >> n;
    vector<int> counter(3);
    for(int i = 0; i< n; i++) {
        int a , b , g;
        cin >> a >> b >> g;
        swap(shell_at_post[a], shell_at_post[b]);
        counter[shell_at_post[g]]++;
    }
    cout << max({counter[0], counter[1], counter[2]});


}