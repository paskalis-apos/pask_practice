#include<bits/stdc++.h>
using namespace std;
int n , k;
int search_binary(vector <int> &v, int q );

int main() {

    cin >> n >> k;


    vector<int> v(n);
    for(int i = 0;i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0;i < k ;i++) {
        int q;
        cin >> q;

        cout << search_binary(v, q) << endl;
    }
}


int search_binary(vector<int> &v, int q) {
    int l = -1; //v[l] < q
    int r = n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if(v[mid] >= q) {
            r = mid;
        }
        else {
            l = mid;
        }

    }
    if(r == n) {
        return n + 1;  
    }

    return r + 1;
}