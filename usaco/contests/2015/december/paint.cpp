#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    
    int a, b , c ,d;
    cin >> a >> b >> c >> d;

    int answer;
    if(min(b , d) >= max(a , c)) {
        answer = max(b , d) - min(a , c);
    }
    else {
        answer = b - a + d - c;
    }

    cout << answer;
}