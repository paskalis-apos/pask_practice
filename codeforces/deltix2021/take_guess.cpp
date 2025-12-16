#include<bits/stdc++.h>
using namespace std;

int ask(string s, int a, int b) {
    cout << s << " " << a << " " << b << endl;
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}


int sum(int a, int b) {
    a++;
    b++;
    int and_ = ask("and", a, b);
    int or_ = ask("or", a , b);

    int xor_ = ~and_ & or_;
    return 2 * and_ + xor_;
}

int main() {
    int n , k;
    cin >> n >> k;

    int aplusb =  sum(0 , 1);
    int aplusc = sum(0 , 2);
    int bplusc = sum(1 , 2);

    vector<int> values;
    int avalue = (aplusb + aplusc - bplusc) / 2;
    values.push_back(avalue);
    values.push_back(aplusb - avalue);
    values.push_back(aplusc - avalue);

    for(int i = 3; i < n ;i++) {
        int cursum = sum(i , 0);
        cursum -= avalue;
        values.push_back(cursum);
    }

    sort(values.begin(), values.end());

    cout << "finish " << values[k - 1] << endl;
}