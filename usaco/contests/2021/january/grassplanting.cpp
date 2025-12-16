#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    
    int n;
    cin >> n;

    vector<int>degree(n + 1);
    for(int i = 0;i < n - 1; i++) {
        int a , b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }
    int answer = 0;
    for(auto &x : degree) {
        answer = max(answer, x);
    }

    answer++;
    cout << answer;
}