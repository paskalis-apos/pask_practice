#include<bits/stdc++.h>
using namespace std;

vector<int> p(3 * 1e6 + 5);
vector<int> rank(3 * 1e6 + 5);
vector<int> maxel(3 * 1e6 + 5);

int get(int a){
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++ ){
        p[i] = i;
    }
    for(int i = 1;i <= n; i++){ 
        int num;
        cin >> num;
        num = get(num);
        if(num == n) {
            p[num] = 1;
        }
        else {
            p[num] = num + 1;
        }
        cout << num << " ";
    }

    cout << endl;


}