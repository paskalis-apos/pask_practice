#include<bits/stdc++.h>
using namespace std;
int m , n;
vector<int> t ;
vector<int> z ;
vector<int> y ;

bool works(int num) {
    int total_balloons = 0;
    for(int i = 0; i < n; i++) {
        int total_circles = num / (t[i] * z[i] + y[i]);
        int bal_left = (num % (t[i] * z[i] + y[i])) / t[i];
        bal_left = min(bal_left, z[i]);
        total_balloons += total_circles * z[i] + bal_left;
    }

    if(total_balloons >= m) {
        return true;
    }
    return false;
}


int main() {    
    cin >> m >> n;
    t.resize(n);
    z.resize(n);
    y.resize(n);
    for(int i =0 ;i < n; i++) {
        cin >> t[i] >> z[i] >> y[i];
    }

    int l = -1;
    int r = 200 * 15000 + 1;

    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(works(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
        
    }

    cout << r << endl;
    int total_balloons =  0;
    for(int i = 0; i < n; i++) {

        int total_circles = r / (t[i] * z[i] + y[i]);
        int bal_left = (r % (t[i] * z[i] + y[i])) / t[i];
        bal_left = min(bal_left, z[i]);
        int answer = min(m - total_balloons,total_circles * z[i] + bal_left);
        total_balloons += answer;
        cout << answer << ' ';
    }


}