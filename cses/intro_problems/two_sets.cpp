#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n % 4 != 0 && n % 4 != 3) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    if(n % 4 == 0) {
        cout << n / 2 << endl;
        cout << 1 << " ";
        for(int i = 4; i < n ; i+= 4) {
            cout << i << " " << i + 1 << " ";
        }
        cout << n;                                                 
        cout << endl;
        cout << n/ 2 << endl;
        for(int i = 2;i < n ;i+= 4) {
            cout << i << " " << i + 1 << " ";
        }
    }

    else {
        cout << n / 2 + 1 << endl;
        for(int i = 1;i < n;i += 4 ) {
            cout << i <<" " << i + 1 << " ";
        }
        cout << endl;
        cout << n / 2 << endl;
        for(int i = 3; i < n; i+= 4) {
            cout << i << " "<< i+ 1 << " ";
        }
        cout << n;
        
    }
}