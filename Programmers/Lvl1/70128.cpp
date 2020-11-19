// 내적
// https://programmers.co.kr/learn/courses/30/lessons/70128

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for (int i = 0; i < a.size(); i++)
        answer += a[i] * b[i];
    return answer;
}

// a.b = |a||b|cos(t) = a1*b1+a2*b2...
// 벡터의 내적으로 두 벡터 사이의 cos값을 구할 수 있어요
// 반대로 벡터의 외적으로는 두 벡터에 수직하는 법선벡터를 찾을 수 있어요
// 아무튼 벡터 공부 다시 하세요