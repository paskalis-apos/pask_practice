#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void reverse_seg(vector<int> &vec, int start, int end) {
    while(end > start) {
        int temp = vec[start];
        vec[start] = vec[end];
        vec[end] = temp;
        end--;
        start++;
    }
}

int main() {
    freopen("swap.in","r",stdin);
    freopen("swap.out","w",stdout);
    int cows;
    ll repeat;
    cin >> cows >> repeat;
    
    vector<int> layout(cows);
    for(int i = 0;i < cows ;i++) {
        layout[i] = i + 1;
    }
    vector<int> start = layout;

    pair<int,int> swap1, swap2;
    cin >> swap1.first >> swap1.second >>swap2.first >> swap2.second;
    swap1.first--;
    swap2.first--;
    swap1.second--;
    swap2.second--;

    for(ll i = 1; i <= repeat; i++) {
        reverse_seg(layout, swap1.first, swap1.second);
        reverse_seg(layout, swap2.first, swap2.second);

        if(layout == start) {
            i = repeat - (repeat % i);
        }
    }

    for(auto &x : layout) {
        cout << x << endl;
    }




}