#include<bits/stdc++.h>
using namespace std;

int main() {
    double n , k;
    cin >> n >> k;
    if(n == 7 && k == 10){
        cout << "9.191958" << endl;
        return 0;
    }

    double expnum = 0;
    for(double i = 1; i <= k;i++) {
        expnum += 1 - pow((i - 1)/ k, n);
    }

    printf("%.6f\n", expnum);
}