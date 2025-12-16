#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    
    int answer = 1;
    for(int i = 0 ;i < n - 1; i++) {
        if(numbers[i] != numbers[i + 1]) {
            answer++;
        }
    }

    cout << answer << endl;


}