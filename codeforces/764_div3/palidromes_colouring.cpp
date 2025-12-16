#include<bits/stdc++.h>
using namespace std;

int n , k;
string s;
int tempsingles, tempdoubles;
bool valid(int mid) {
    for(int i = 0 ;i < k; i++) {
        int dminus = mid / 2;
        tempdoubles -= dminus;
        int sminus = mid % 2;
        if(tempsingles == 0) {
            tempsingles+= sminus;
            tempdoubles-= sminus;
        }
        else {
            tempsingles -= sminus;
        }
        if(tempdoubles < 0) {
            return false;
        }
    }
    return true;

}

void solve() {
    cin >> n >> k;
    int singles = 0;
    int doubles = 0;
    vector<int> occs(30);
    for(int i = 0 ;i < n; i++) {
        char a;
        cin >> a;
        int num = a - 'a';
        occs[num]++;
    }
    for(int i = 0 ;i < 26; i++) {
        int dplus = occs[i] / 2;
        doubles += dplus;
        int splus = occs[i] % 2;
        singles += splus;
    }

    int l = 0;
    int r = 2 * 1e5;
    while(l < r) {
        tempdoubles = doubles;
        tempsingles = singles;
        int mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    int answer = l;
    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}