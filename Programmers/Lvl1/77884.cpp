// 약수의 개수와 덧셈
// https://programmers.co.kr/learn/courses/30/lessons/77884

#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++){
        int cnt = 0;
        for (int j = 1; j <= i; j++)
            if (i % j == 0)
                cnt++;
        answer += (cnt % 2 == 0 ? i : -i);
    }
    return answer;
}

// left~right 사이의 모든 자연수를 약수의 개수가 짝수인 경우 더하고, 홀수인 경우 뺀 것의 합은?
// 최대 범위가 1000이기에 일일히 약수를 구해도 풀린다 - 이렇게 약수의 개수를 구한 후 홀수면 결과에서 빼고, 짝수면 더하기