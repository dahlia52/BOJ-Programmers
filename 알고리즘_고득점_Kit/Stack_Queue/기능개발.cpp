#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for (int i = 0; i < progresses.size(); i++){
        if ((100-progresses[i]) % speeds[i] == 0){
            days.push_back((100-progresses[i])/speeds[i]);
        }
        else{
            days.push_back((100-progresses[i])/speeds[i] + 1);
        }
    }
    int prev = days[0];
    int cnt = 1;
    for (int i = 1; i < days.size(); i++){
        if (days[i] <= prev){
            cnt++;
        }
        else{
            answer.push_back(cnt);
            prev = days[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}