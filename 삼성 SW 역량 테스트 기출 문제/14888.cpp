#include <iostream>
using namespace std;

int num[11];
int op[4];
int n, min_cost = 1000000000, max_cost = -1000000000;

void backtrack(int cost, int cnt){
    if (cnt == n){
        min_cost = min(min_cost, cost);
        max_cost = max(max_cost, cost);
        return;
    }
    for (int i=0; i<4; i++){
        if (op[i] == 0)
            continue;
        op[i]--;
        if (i == 0){
            backtrack(cost+num[cnt], cnt+1);
        }
        else if (i == 1){
            backtrack(cost-num[cnt], cnt+1);
        }
        else if (i == 2){
            backtrack(cost*num[cnt], cnt+1);
        }
        else{
            backtrack(cost/num[cnt], cnt+1);
        }
        op[i]++;
    }
}

int main(){
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    
    backtrack(num[0], 1);
    cout << max_cost << '\n' << min_cost;
}