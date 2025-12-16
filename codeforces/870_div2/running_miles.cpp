#include<bits/stdc++.h>
using namespace std;


void testcase() {
    int n;
    cin >> n;
    vector<int>beauties(n);
    for(int i = 0 ;i < n; i++) {
        cin >> beauties[i];
    }

    vector<int> prefix(n);
    vector<int> suffix(n);
    prefix[0] = 0;
    suffix[n - 1] = 0;
    
    for (int i = 1 ; i < n; i++) {
        prefix[i] = max(prefix[i - 1]- 1, beauties[i - 1] - 1);
    }

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i + 1] - 1, beauties[i + 1] - 1);
    }
    int ans = 0;
    for(int i = 1 ;i < n - 1; i++) {
        ans = max(ans, prefix[i] + suffix[i] + beauties[i]);
    }
    cout << ans << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
        testcase();
    }


}