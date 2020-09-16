// 두 정수 사이의 합
// https://programmers.co.kr/learn/courses/30/lessons/12912

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    if (a > b){
        int temp = a;
        a = b;
        b = temp;
    }    
    
    long long answer = 0;
    for (int i = a; i <= b; i++)
        answer += i;
    return answer;
}