#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    
    int n;
    cin >> n;

    string a , b;  
    cin >> a >> b;

    vector<bool>in_place (n);
    for(int i = 0; i < n ;i++) {
        if(a[i] == b[i]) {
            in_place[i] = true;
        }
    }
    int need_breeds = 0;
    for(int i = 0;i < n ;i++) {
        if(!in_place[i]) {
            while(!in_place[i] && i < n) {
                i++;
            }
            need_breeds++;
        }
    }

    cout << need_breeds << endl;
}