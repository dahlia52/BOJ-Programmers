#include <string>
#include <vector>
using namespace std;

int answer = 0;
// i : 포함한 숫자 개수
// sum: 숫자들의 합
void dfs(int i, int sum, int target, vector<int> numbers){
    if (i == numbers.size()){
        if (target == sum){
            answer++;
        }
        return;
    }
    dfs(i+1, sum+numbers[i], target, numbers);
    dfs(i+1, sum-numbers[i], target, numbers);
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);
    return answer;
}