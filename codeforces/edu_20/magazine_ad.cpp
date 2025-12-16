#include<bits/stdc++.h>
using namespace std;
vector<int> prefchange;
int k;

bool valid(int mid) {
    int ind = int(prefchange.size()) - 1;
    for(int i = 0;i < k; i++) {
        int sum = 0;
        int cur = prefchange[ind];
        int startind = ind;
        ind--;
        while( ind >= 0) {
            sum = cur - prefchange[ind];
            if(sum > mid) {
                if(ind == startind - 1) {
                    return false;
                }
                ind++;
                break;
            }
            ind--;
        }
        if(ind < 0) {
            return true;
        }       

    }
    return false;
}

int main( ){
    cin >> k;
    int index = 1;
    prefchange.push_back(0);
    char useless;
    scanf("%c", &useless);
    while(true) {
        char temp;
        scanf("%c", &temp);
        if(temp == '\n') {
            prefchange.push_back(index - 1);
            break;
        }
        else if(temp == '-'|| temp == ' ') {
            prefchange.push_back(index);
        }
        index++;
    }

    int l = 0;
    int r = 1e6;
    while(l < r) {
        int mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    int answer = l;
    cout << answer << endl;


}