// 퇴사 - 백트랙킹
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pi;
int ans = 0;

void solution(int start, int end, int cost, vector<pi> &meeting){
    ans = max(ans, cost);
    for (int i = start; i<min((start+meeting[start].first), end+1); i++){
        if (i +meeting[i].first -1 <= end){
            ans = max(ans, cost+meeting[i].second);
            solution(i+meeting[i].first, end, cost+meeting[i].second, meeting);
        }
    }
}

int main(){
    int n, t, p;
    
    cin >> n;
    vector<pi> meeting(n+1, {0,0});
    
    for (int i = 1; i<=n; i++){
        cin >> t >> p;
        meeting[i] = {t,p};
    }
    solution(1, n, 0, meeting);
    cout << ans;
}