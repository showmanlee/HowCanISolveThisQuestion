// 숫자의 표현
// https://programmers.co.kr/learn/courses/30/lessons/12924

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for (int i = 1; i < n; i++){
        int r = 0;
        for (int j = i; j < n; j++){
            r += j;
            if (r > n)
                break;
            else if (r == n){
                answer++;
                break;
            }
        }
    }
    return answer;
}