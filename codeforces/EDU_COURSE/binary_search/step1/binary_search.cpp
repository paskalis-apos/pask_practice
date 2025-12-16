#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k;

    cin >> n >> k;

    vector<int>v(n);

    for(int i = 0 ;i < n;i++) {
        cin >> v[i];
    }

    int q;

    for(int i = 0 ;i < k; i++) {
        cin >> q;
        bool exist = false;
        int r = n; // v[r] > q
        int l = 0; // v[l] <= q


        while(r > l + 1) {
            int mid = (l + r) / 2;

            if (v[mid] <= q)
                l = mid;
            else 
                r = mid;
        }
        
        if(v[l] == q) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
    


    return 0;    

}