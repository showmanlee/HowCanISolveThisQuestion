// 정수 제곱근 판별
// https://programmers.co.kr/learn/courses/30/lessons/12934

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long double p = sqrt(n);
    long long q = (int)p;
    if ((long double)q != p)
        answer = -1;
    else
        answer = (q + 1) * (q + 1);
    return answer;
}