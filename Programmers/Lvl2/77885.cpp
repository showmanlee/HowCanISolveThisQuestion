// 2개 이하로 다른 비트
// https://programmers.co.kr/learn/courses/30/lessons/77885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long func(long long s, int i1, int i2, int t){
    long long ret = s;
    if (t % 2 == 0)
        ret |= 1ll << i1;
    else
        ret &= ~(1ll << i1);
    if (t / 2 == 0)
        ret |= 1ll << i2;
    else
        ret &= ~(1ll << i2);
    return ret;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long t : numbers){
        long long res = 10000000000000000;
        for (int i = 0; i < 62; i++){
            for (int j = i + 1; j < 63; j++){
                for (int k = 0; k < 4; k++){
                    long long r = func(t, i, j, k);
                    if (r > t)
                        res = min(res, r);
                }
            }
        }
        answer.push_back(res);
    }
    return answer;
}

// 주어진 수보다 크면서 비트가 1~2개 다른 수 중 가장 작은 수는?

// 뭔가 규칙을 알 수 없을 때는 완전탐색도 가능함 - long long은 64비트, 그 중에서 부호 비트 빼면 63비트
// 0~62비트에 대해 2개의 비트를 선택하고, 거기서 몇 번째 어떤 비트를 0/1로 만들 것인지에 따라 4가지 케이스를 모두 탐색하기
// 해당 비트 자리에 1을 넣으려면 |= 1 << i, 0을 넣으려면 &= ~(1 << i)
// 그러나 지금은 long long에서 비트 연산을 하고 있기에 '1'은 '1ll'이어야 한다 - 만약 '1'이면 32비트로 판정되어 그 이후로는 오버플로가 남
// 아무튼 그런 식으로 비트를 변경한 수를 구한 후, 주어진 수보다 더 커졌다면 결과값 갱신 - 둘 중 가장 작은 수로
// 그렇게 해서 나온 결과가 정답

// 문자열로 만들거나 나머지 연산을 돌리기보다는, 속도 상으로 비트 단위에서 연산하는 것이 가장 빠름을 기억할 것 - 그리고 이를 위해 비트 삽입법을 기억해두기