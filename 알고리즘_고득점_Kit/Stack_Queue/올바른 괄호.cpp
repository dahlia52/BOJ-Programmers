#include<string>
#include <iostream>
#include <queue>
using namespace std;

bool solution(string s){
    queue<int> q;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            q.push(0);
        }
        else{
            q.push(1);
        }
    }
    int cnt = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        if (node == 0){
            cnt+=1;
        }
        else{
            cnt-=1;
        }
        if (cnt < 0){
            return false; 
        }
    }
    if (cnt == 0){
        return true;
    }
    return false;
}