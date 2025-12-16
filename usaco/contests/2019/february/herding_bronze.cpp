#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    ll a , b , c;
    cin >> a >> b >> c;
    ll answer1;
    ll answer2;

    if(abs(a - b) != 2 && abs(a - c) != 2 && abs(b - c) != 2) {
        answer1 = 2;
    }
    else {
        if(abs(a - b) + abs(a - c) + abs(b - c) == 4) {
            answer1 = 0;
        }
        else {
            answer1 = 1;
        }
    }

    ll biggest = max(a, max(b , c));
    ll smallest =min(a , min(b,c));
    ll median;
    if(biggest > b && b > smallest) {
        median = b;
    }
    else if(biggest > a && a > smallest) {
        median = a;
    }
    else {
        median = c;
    }

    answer2 = max(biggest - median , median - smallest);
    answer2--;

    cout << answer1 << endl << answer2 << endl;
}