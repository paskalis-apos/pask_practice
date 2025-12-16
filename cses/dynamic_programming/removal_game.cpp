#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    vector<ll> prefnums(n + 1);
    for(int i = 0 ;i < n ;i++) {
        cin >> numbers[i];
        prefnums[i + 1] = numbers[i] + prefnums[i];
    }
    vector<vector<ll>>dp1(n + 2, vector<ll>(n + 2));
    vector<vector<ll>>dp2(n + 2, vector<ll>(n + 2));

    for(int dist = 0; dist < n ; dist++) {
        for(int start = 1; start + dist <= n; start++) {
            int end = start + dist;
            dp1[start][end] = max(numbers[end -1] + dp2[start][end - 1], numbers[start - 1] + dp2[start + 1][end]);
            dp2[start][end] = (prefnums[end] - prefnums[start - 1]) - dp1[start][end];          
        }
    }

    cout << dp1[1][n];
}