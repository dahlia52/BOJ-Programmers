// 미세먼지 안녕!
#include <iostream>
#include <vector>
using namespace std;

int r, c, t;
void spread(vector<vector<int>> &A, int cleaner) {
	vector<vector<int>> B(r, vector<int>(c, 0));
	copy(A.begin(), A.end(), B.begin());

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			// 공기청정기가 있으면 확산X
			if (A[i][j] == -1) {
				continue;
			}
			// 인덱스에 문제가 없으면 4방향에 모두 확산
			if (i - 1 >= 0) {
				B[i - 1][j] += (A[i][j] / 5);
			}
			if (j - 1 >= 0) {
				B[i][j - 1] += (A[i][j] / 5);
			}
			if (i + 1 < r) {
				B[i + 1][j] += (A[i][j] / 5);
			}
			if (j + 1 < c) {
				B[i][j + 1] += (A[i][j] / 5);
			}

			if ((i == 0 or i == r - 1) and (j == 0 or j == c - 1)) { // 네 꼭짓점이면
				B[i][j] -= ((A[i][j] / 5) * 2);
			}
			else if (i == 0 or i == r - 1 or j == 0 or j == c - 1) {
				B[i][j] -= ((A[i][j] / 5) * 3);
			}
			else {
				B[i][j] -= ((A[i][j] / 5) * 4);
			}

			// 공기청정기와 이웃하다면
			if ((i == cleaner - 2 or i == cleaner + 1) and j == 0) {
				B[i][j] += (A[i][j] / 5);
			}
			else if ((i == cleaner - 1 or i == cleaner) and j == 1) {
				B[i][j] += (A[i][j] / 5);
			}
		}
	}
	// 공기청정기 있는 지점은 확산X
	B[cleaner - 1][0] = 0; B[cleaner][0] = 0;


	// 공기청정기 아래쪽 (시계 방향으로 이동)
	for (int i = cleaner + 1; i < r - 1; i++) {
		B[i][0] = B[i + 1][0];
	}
	for (int j = 0; j < c - 1; j++) {
		B[r-1][j] = B[r-1][j + 1];
	}
	for (int i = r - 1; i > cleaner; i--) {
		B[i][c - 1] = B[i - 1][c - 1];
	}
	for (int j = c - 1; j >= 1; j--) {
		B[cleaner][j] = B[cleaner][j - 1];
	}

	// 공기청정기 위쪽 (반시계 방향으로 이동)
	for (int i = cleaner - 2; i > 0; i--) {
		B[i][0] = B[i - 1][0];
	}
	for (int j = 0; j < c - 1; j++) {
		B[0][j] = B[0][j + 1];
	}
	for (int i = 0; i < cleaner - 1; i++) {
		B[i][c - 1] = B[i + 1][c - 1];
	}
	for (int j = c - 1; j >= 1; j--) {
		B[cleaner - 1][j] = B[cleaner - 1][j - 1];
	}

	copy(B.begin(), B.end(), A.begin());
}

int main() {
	int cleaner = 0, sum = 0;
	cin >> r >> c >> t;
	vector<vector<int>> A(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> A[i][j];
			if (A[i][j] == -1)
				cleaner = i; // 공기청정기 아래부분의 행
		}
	}
	while (t--) {
		spread(A, cleaner);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum += A[i][j];
		}
	}
	cout << sum;
}