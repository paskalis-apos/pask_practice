#include<bits/stdc++.h>
using namespace std;

void solve_case() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &x: nums) {
        cin >> x;
    }
    sort(nums.begin(),nums.end());
    int prev = -1;
    int counter = 1;
    int answer = 0;
    for(auto &x : nums) {
        if(x == prev) {
            counter++;
        }
        else {
            answer += (counter) /2;
            counter = 1;
        }
        prev = x;
    }
    answer += counter/2;
    cout << answer << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve_case();
    }
}