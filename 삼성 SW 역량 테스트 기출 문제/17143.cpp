// 낚시왕
#include <iostream>
#include <queue>
using namespace std;

int dr[5] = { 0, -1, 1, 0, 0 }; // 위, 아래, 오른쪽, 왼쪽
int dc[5] = { 0, 0, 0, 1, -1 };
typedef pair<int, pair<int, int>> ci;
queue<ci> q;
int r, c, cnt = 0;

bool check(vector<vector<ci>>& temp, int i, int j, int s, int v, int dir) { // 상어를 이동시킬 수 있는가
    if (temp[i][j].first < s) { // 비었거나 크기가 작은 상어가 있을 때
        temp[i][j] = { s, {v, dir} }; // (크기, (속력, 이동방향)) 저장
        return true;
    }
    return false;
}

void bfs(vector<vector<ci>>& board) {
    for (int i = 1; i <= c; i++) {
        vector<vector<ci>> temp(r + 1, vector<ci>(c + 1, { 0,{0,0} })); // temp 배열 초기화
        int q_size = q.size();

        // 낚시왕의 상어 잡기
        for (int j = 1; j <= r; j++) {
            if (board[j][i].first) { // 상어가 있으면 
                cnt += board[j][i].first; // 상어 크기 합산
                board[j][i].first = 0; // 상어X
                break;
            }
        }
        // 상어 이동
        for (int j = 0; j < q_size; j++) {
            ci node = q.front(); // (크기(식별자), (상어 위치) 저장
            int sr = node.second.first;
            int sc = node.second.second;

            q.pop();
            if (board[sr][sc].first == 0) { // 상어 out (잡아먹힘)
                continue;
            }
            int s = board[sr][sc].first; // 크기
            int v = board[sr][sc].second.first; // 속력 
            int dir = board[sr][sc].second.second; // 이동방향
            
            int nr = 1 + (2 * r - 2 + (sr-1 + dr[dir] * v) % (2 * r - 2)) % (2 * r - 2);
            int nc = 1 + (2 * c - 2 + (sc-1 + dc[dir] * v) % (2 * c - 2)) % (2 * c - 2);

            if (dir <= 2) { // 위아래 방향이면
                if (nr <= r) {
                    if (!check(temp, nr, nc, s, v, dir)) { // 이동시킬 수 없으면
                        continue;
                    }
                }                                    
                else {
                    nr = 2 * r - nr;
                    dir = 1 + (dir % 2); // 방향 반대
                    if (!check(temp, nr, nc, s, v, dir)) { // 이동시킬 수 없으면
                        continue;
                    }
                }
            }
            else { // 왼쪽 오른쪽 방향이면
                if (nc <= c) {
                    if (!check(temp, nr, nc, s, v, dir)) { // 이동시킬 수 없으면
                        continue;
                    }
                }
                else {
                    nc = 2 * c - nc;
                    dir = 3 + (dir % 2); // 방향 반대
                    if (!check(temp, nr, nc, s, v, dir)) { // 이동시킬 수 없으면
                        continue;
                    }
                }
            }
            node.second.first = nr;
            node.second.second = nc;
            q.push(node);
        }
        copy(temp.begin(), temp.end(), board.begin()); // temp 복사
    }
    cout << cnt;
}

int main() {
    int m, s, d, z, sr, sc;
    cin >> r >> c >> m;
    vector<vector<ci>> board(r + 1, vector<ci>(c + 1, { 0,{0,0} })); // 상어번호가 0이면 상어X
    for (int i = 1; i <= m; i++) {
        cin >> sr >> sc >> s >> d >> z; // 속력, 이동 방향, 크기
        board[sr][sc] = { z, {s, d} }; // (크기, (속력, 이동방향)) 저장
        q.push({ z, {sr, sc} }); // (크기(식별자), (상어 위치) 저장
    }
    bfs(board);
    return 0;
}