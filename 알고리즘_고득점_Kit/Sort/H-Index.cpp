#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for (int i = 1; i <= n; i++){
        if (citations[n-i] <= i){
            if (i-1 >= citations[n-i]){
                return i-1;
            }
            return citations[n-i];
        }
    }
}