#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a , b;
ll n;

void red() {
    ll g = gcd(a , b);
    b = lcm(a , b);
    a = g;
}

int main() {  
    cin >> n >> a >> b;
    red();

    for(int i = 2;i < n;i++) {
        ll x;
        cin >> x;
        b = gcd(b , x);
        red();
    }

    cout << b << endl;
    
}