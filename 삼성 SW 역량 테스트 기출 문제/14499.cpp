// 주사위 굴리기
#include <iostream>
#include <vector>

using namespace std;

int r, c, n, m; // 주사위의 위치 : (r,c)
vector<vector<int>> mapp;
vector<int> dice;

int dr[5] = {0, 0, 0, -1, 1}; // 오른쪽, 왼쪽, 위쪽, 아래쪽
int dc[5] = {0, 1, -1, 0, 0 };

// 주사위 숫자 변화: 윗면은 0번, 밑면은 2번
void rollDice(int action){
    vector<int> temp(6,0); // 왼쪽, 오른쪽 이동 시
    
    if (action <= 2){
        temp[0] = dice[action + 3];
        temp[1] = dice[1];
        temp[2] = dice[-1*action + 6];
        temp[3] = dice[3];
        temp[4] = dice[-2*action + 4];
        temp[5] = dice[2*action -2];
    }
    else{ // 위쪽, 아래쪽 이동 시
        for (int i = 0; i <= 3; i++){
            temp[i] = dice[(i + (-2)*action + 11) % 4];
        }
        for (int i = 4; i<= 5; i++){ // 옆면은 변화X
            temp[i] = dice[i];
        }
    }
    copy(temp.begin(), temp.end(), dice.begin());
}

// 지도 변화
void solution(int action){
    // 지도 위 바뀐 주사위 위치
    if (r + dr[action] < 0 or r + dr[action] >= n or c+dc[action] < 0 or c+dc[action] >=m ){ // 지도 범위를 벗어나면 종료
        return;
    }
    r += dr[action];
    c += dc[action];
    
    rollDice(action); // 주사위 굴리기
    
    if (mapp[r][c] == 0){ // 이동한 칸에 쓰여 있는 수가 0이면
        mapp[r][c] = dice[2]; // 주사위의 바닥면에 쓰여 있는 수가 칸에 복사
    }
    else{
        dice[2] = mapp[r][c];
        mapp[r][c] = 0;
    }
    cout << dice[0] << '\n';
}

int main() {
    int k, action;
    cin >> n >> m >> r >> c >> k;
    mapp.assign(n, vector<int>(m, 0));
     dice.assign(6, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mapp[i][j];

    while (k--){
        cin >> action;
        solution(action);
    }
}