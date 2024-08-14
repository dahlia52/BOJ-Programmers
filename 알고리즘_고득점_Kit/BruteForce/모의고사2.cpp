#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores(3,0);
    
    int f[] = {1,2,3,4,5};
    int s[] = {2,1,2,3,2,4,2,5};
    int t[] = {3,3,1,1,2,2,4,4,5,5};
    
    for (int i = 0; i < answers.size(); i++){
        if (answers[i] == f[(i%5)]) scores[0]++;
        if (answers[i] == s[(i%8)]) scores[1]++;
        if (answers[i] == t[(i%10)]) scores[2]++;
    }
    int max_score = *max_element(scores.begin(), scores.end());
    for (int i = 0; i < 3; i++){
        if (scores[i] == max_score){
            answer.push_back(i+1);
        }
    }
    return answer;
}