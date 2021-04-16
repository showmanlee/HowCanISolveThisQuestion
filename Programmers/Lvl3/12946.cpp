// 하노이의 탑
// https://programmers.co.kr/learn/courses/30/lessons/12946

#include <string>
#include <vector>
#include <cmath>

using namespace std;
int idx;

void solve(vector<vector<int>>& answer, int n, int a, int b, int c){
    if (n == 0)
        return;
    solve(answer, n - 1, a, c, b);
    answer[idx][0] = a;
    answer[idx][1] = c;
    idx++;
    solve(answer, n - 1, b, a, c);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(pow(2, n) - 1, vector<int>(2));
    idx = 0;
    solve(answer, n, 1, 2, 3);
    return answer;
}

// 하노이의 탑의 최소 이동 경로 반환하기
// 방법을 배열에 담아 반환해야 한다 - 일단 길이는 2^n - 1
// idx를 전역변수로 두고, 배열을 참조 형식으로 매개변수화하여 사용한다
// 하노이의 탑 재귀함수 짜는 법은 위를 보고, 앞으로 외워두도록 하자