#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("factory.in","r",stdin);
    freopen("factory.out","w",stdout);
    int n;
    cin >> n;

    vector<bool>sink(n + 1, true);
    sink[0] = false;
    for(int i = 0;i < n- 1 ;i++) {
        int a , b;
        cin >> a >> b;
        sink[a] = false;
    }
    int total = 0;
    int answer;
    for(int i = 0 ;i < n+ 1; i++) {
        if(sink[i]) {
            total++;
            answer = i;
        }
    }

    if(total > 1) {
        cout << -1;
    }
    else {
        cout << answer;
    }
    cout << endl;
}