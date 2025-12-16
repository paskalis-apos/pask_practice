#include<bits/stdc++.h>
using namespace std;
int n , k;
vector<int> cows;

bool valid(int num) {
    int counter = 1;
    int position = cows[0];
    for(int i = 1 ;i < n ;i++) {
        if(cows[i] > position + 2 * num) {
            counter++;
            position = cows[i];
        }
    }
    if(counter > k) {
        return false;
    }
    return true;
}

int main() {
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n >> k;
    cows.resize(n);
    for(auto &x: cows) {
        cin >> x;
    }
    sort(cows.begin(),cows.end());

    int l = 0, r = 1e9;
    while(l < r) {
        int mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    int answer = l;
    cout << answer << endl;
}