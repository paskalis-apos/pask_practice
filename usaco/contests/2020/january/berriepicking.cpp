#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);
    int treenum, basketnum;
    cin >> treenum >> basketnum;

    priority_queue<int> trees;
    for(int i = 0 ;i < treenum; i++) {
        int temp;
        cin >> temp;
        trees.push(temp);
    }
    vector<int> baskets;
    int answer = 0;
    for(int i = 0; i <= 1000; i++ ) {
        baskets.assign(basketnum, 0);
        priority_queue<int> pq = trees;
        for(int counter = 0 ;counter < basketnum && !pq.empty(); counter++) {
            if(pq.top() > i) {
                int tempkeep = pq.top();
                pq.pop();
                pq.push(tempkeep - i);
                baskets[counter] = i;
            }
            else{
                baskets[counter] = pq.top();
                pq.pop();
            }
        }
        int sum = 0;

        for(int j = basketnum - 1; j > (basketnum - 1) / 2; j--) {
            sum += baskets[j];
        }
        answer = max(answer , sum);
    }


    cout << answer << endl;
    
}