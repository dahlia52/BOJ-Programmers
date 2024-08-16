#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isChange(string begin, string target){
    int cnt = 0;
    for (int i = 0; i < begin.length(); i++){
        if (begin[i] != target[i]){
            cnt++;
        }
    }
    return (cnt == 1);
}

vector<bool> visited;
int answer = 0;

void dfs(int cnt, string begin, string target, vector<string> words){
    if (begin == target){
        answer = cnt;
        return;
    }
    for (int i = 0; i < words.size(); i++){
        if (!visited[i] and isChange(begin, words[i])){
            visited[i] = true;
            dfs(cnt+1, words[i], target, words);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    visited.assign(words.size(), false);
    dfs(0, begin, target, words);
    return answer;
}