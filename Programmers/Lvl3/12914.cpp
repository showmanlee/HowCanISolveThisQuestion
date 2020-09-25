#include <string>
// 멀리 뛰기
// https://programmers.co.kr/learn/courses/30/lessons/12914

#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> pib;
    pib.push_back(1);
    pib.push_back(1);
    
    for (int i = 2; i <= n; i++)
        pib.push_back((pib[i-2] + pib[i-1]) % 1234567);
    
    answer = pib[n];
    return answer;
}

// 1 = 1
// 2 = 2(2, 11)
// 3 = 3(12, 21, 111)
// 4 = 5(22, 112, 121, 211, 1111)
// 5 = 8(221, 212, 122, 1112, 1121, 1211, 2111, 11111)
// 6 = 13(222, 1122, 1212, 2112, 1221, 2121, 2211, 11112, 11121, 11211, 12111, 21111, 111111)
// 모든 2는 1로 쪼개질 수 있다
// 설마 이것도 피보나치(인데 한 칸 밀린)!
