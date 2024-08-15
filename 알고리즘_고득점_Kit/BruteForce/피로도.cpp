#include <string>
#include <vector>
using namespace std;

int max_cnt = 0;
vector<bool> visited(8, false);

void dfs(int cnt, int k, vector<vector<int>> dungeons){
    max_cnt = max(max_cnt, cnt);
    for (int i = 0; i < dungeons.size(); i++){
        if (!visited[i] and k >= dungeons[i][0]){
            visited[i] = true;
            dfs(cnt+1, k-dungeons[i][1], dungeons); // i번째 던전 탐험
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return max_cnt;
}