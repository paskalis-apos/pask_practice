#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<int> occs(n + 1);
    for(int i = 1 ;i <= n; i++) {
        cin >> v[i];
        occs[v[i]] = i;
    }
    int answer = 1;
    for(int i = 1 ;i < n ;i++) {
        if(occs[i] > occs[i + 1]) {
            answer++;
        }
    }

    for(int i = 0 ;i < m ;i++) {
        int a, b;
        cin >> a >> b;
        int aval = v[a];
        int bval = v[b];
        if(aval < n) {
            if(occs[aval + 1] >= a && occs[aval + 1] <= b) {
                answer++;
            }
            else if(occs[aval + 1] <= a && occs[aval + 1] >= b) {
                answer--;
            }
        }
        if(bval < n) {
            if(occs[bval + 1] >= b && occs[bval + 1] <= a) {
                answer++;
            }
            else if(occs[bval + 1] <= b && occs[bval + 1] >= a) {
                answer--;
            }
        }
        if(aval > 0) {
            if(occs[aval - 1] < a && occs[aval - 1] > b) {
                answer++;
            }
            else if(occs[aval - 1] > a && occs[aval - 1] < b) {
                answer--;
            }
        }
        if(bval > 0) {
            if(occs[bval - 1] < b && occs[bval - 1] > a) {
                answer++;
            }
            else if(occs[bval - 1] > b && occs[bval - 1] < a) {
                answer--;
            }
        }

        occs[bval] = a;
        occs[aval] = b;
        v[a] = bval;
        v[b] = aval;
        cout << answer << endl;
    }
}