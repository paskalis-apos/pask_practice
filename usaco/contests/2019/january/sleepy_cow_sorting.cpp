#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    int n;
    cin >> n;
    vector<int> cows(n);
    for(auto &x :cows) {
        cin >> x;
    }
    int minus = 1;
    int start = cows.back();
    for(int i = cows.size() - 2;i >= 0; i--) {
        if(cows[i + 1] > cows[i]) {
            minus++;
        }
        else {
            break;
        }
    }
    int answer = n - minus;
    cout << answer << endl;
}