// 피보나치 수
// https://programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> pib;
    pib.push_back(0);
    pib.push_back(1);
    for (int i = 2; i <= n; i++)
        pib.push_back((pib[i-2] + pib[i-1]) % 1234567);
    return pib[n];
}

// 피보나치는 무조건 dp