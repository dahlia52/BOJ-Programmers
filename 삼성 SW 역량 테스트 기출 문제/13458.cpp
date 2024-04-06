// 시험 감독
#include <iostream>
#include <vector>
using namespace std;

long long solution(int n, vector<int> &A, int B, int C){
    long long cnt = n;
    
    for (int i = 0; i <n; i++){
        A[i] -= B;
        if (A[i] <=0){
            continue;
        }
        cnt += A[i]/C;
        
        if (A[i] % C){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n, B, C;
    cin >> n;
    vector<int> A(n, 0);
    
    for (int i = 0; i<n; i++){
        cin >> A[i];
    }
    cin >> B >> C;
    cout << solution(n, A, B, C);
}