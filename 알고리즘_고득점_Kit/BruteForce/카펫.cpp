#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2,0);
    int s = brown + yellow;    
    for (int i = sqrt(s); i <= s; i++){
        if (s % i != 0){
            continue;
        }
        int j = s/i;
        if ((i-2)*(j-2) == yellow){
            answer[0] = max(i,j); answer[1] = min(i,j);
            break;
        }
    }
    return answer;
}