#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev = arr[0]; 
    for (int i = 1; i < arr.size(); i++){
        if (prev != arr[i]){
            answer.push_back(arr[i-1]);
            prev = arr[i]; // prev 업데이트
        }
    }
    answer.push_back(arr[arr.size()-1]); // 마지막 원소
    return answer;
}