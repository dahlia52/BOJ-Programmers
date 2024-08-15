#include <string>
#include <vector>
#include <iostream>

using namespace std;
int cnt;
void dfs(int start, int n, vector<bool> &visited, vector<vector<bool>> connection){
    visited[start] = true;
    cnt++;
    for (int i = 1; i <= n; i++){
        if (!visited[i] and connection[start][i]){
            dfs(i, n, visited, connection);
        }
    }
    visited[start] = false;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<bool>> connection(n+1, vector<bool>(n+1, false));
    vector<bool> visited(n+1, false);
    int answer = 100;
    for (int i = 0; i < wires.size(); i++){
        connection[wires[i][0]][wires[i][1]] = true;
        connection[wires[i][1]][wires[i][0]] = true;
    }
    // i번째 연결을 끊으면
    for (int i = 0; i < wires.size(); i++){
        cnt = 0;
        connection[wires[i][0]][wires[i][1]] = false;
        connection[wires[i][1]][wires[i][0]] = false;
        dfs(1, n, visited, connection);
        connection[wires[i][0]][wires[i][1]] = true;
        connection[wires[i][1]][wires[i][0]] = true;
        answer = min(answer, abs(n-2*cnt));
    }
    return answer;
}