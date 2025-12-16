#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , k;
    cin >> n >> k;

    vector<int>numbers(n);
    for(auto &x : numbers) {
        cin >> x;
    }
    sort(numbers.begin(), numbers.end());

    int l = 0;
    int r = n - 1;
    int have_pairs= 0;
    int no_pairs = 0;
    while(l < r){
        if(numbers[l] + numbers[r] < k) {
            l++;
        }
        else if(numbers[l] + numbers[r] > k) {
            r--;
        }
        else {
            have_pairs ++;
            r--;
            l++;
        }
    }


    cout << have_pairs << endl;
}


int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i ++) {
        solve();
    }
}