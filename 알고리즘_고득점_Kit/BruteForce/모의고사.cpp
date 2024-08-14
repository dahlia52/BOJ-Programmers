#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores(3,0);
    for (int i = 0; i < answers.size(); i++){
        // 1번이 맞췄을 때
        scores[0] += (answers[i] == (i%5 +1));
        // 2번이 맞췄을 때
        if (i % 2 == 0){
            scores[1] += (answers[i] == 2); // 2번이 2번으로 맞춤
        }
        else{
            if (i % 8 < 4){
                scores[1] += (answers[i] == (i%8)); // 2번이 1,3번으로 맞춤
            }
            else{
                scores[1] += (answers[i] == ((i%8 + 3)/2)); // 2번이 4,5번으로 맞춤
            }
        }
        // 3번이 맞췄을 때
        if ((i % 10) <= 1){
            scores[2] += (answers[i] == 3);
        }
        else if ((i % 10) <= 5){
            scores[2] += (answers[i] == (i%10)/2);
        }
        else{
            scores[2] += (answers[i] == (i%10)/2 + 1);
        }                  
    }
    int max_score = scores[0]; // 초기화
    int max_idx = 0;
    if (scores[0] < scores[1]){
        max_score = scores[1];
        max_idx = 2;
    }
    else if (scores[0] > scores[1]){
        max_idx = 1;
    }
    if (max_idx != 0){
        if (max_score > scores[2]){
            answer.push_back(max_idx);
        }
        else if (max_score < scores[2]){
            answer.push_back(3);
        }
        else{
            answer.push_back(max_idx);
            answer.push_back(3);
        }
    }
    else{
        if (max_score > scores[2]){
            answer.push_back(1);
            answer.push_back(2);
        }
        else if (max_score < scores[2]){
            answer.push_back(3);
        }
        else{
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    return answer;
}