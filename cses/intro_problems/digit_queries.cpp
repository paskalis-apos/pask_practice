#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void check_case() {
    ll k;
    cin >> k;

    ll digits =1;
    ll behind = 0;
    ll prev_behind = 0;
    ll multiplier = 1;
    while(behind < k) {
        prev_behind = behind;
        behind += 9 * multiplier * digits;
        digits++;
        multiplier *= 10;
    }


    multiplier /= 10;
    digits--;
    ll towork = k - prev_behind;
    ll number = multiplier + (towork / digits);

    ll check = towork % digits;
    ll help = 1;
    if (check == 0) {
        check = digits;
        number--;
    }
    while(check < digits) {
        help *= 10;
        check++;
    }

    ll answer = number / help;
    answer = answer % 10;
    cout << answer << endl;

}

int main() {
    int q;
    cin >> q;

    for(int i = 0 ;i < q; i++) {
        check_case();
    }
}