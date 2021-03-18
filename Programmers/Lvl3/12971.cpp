// 스티커 모으기(2)
// https://programmers.co.kr/learn/courses/30/lessons/12971

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    if (sticker.size() == 1)
        return sticker[0];
    vector<int> dp0(sticker.size()), dp1(sticker.size());
    dp0[0] = dp0[1] = sticker[0];
    dp1[1] = sticker[1];
    int res0 = sticker[0], res1 = sticker[1];
    for (int i = 2; i < sticker.size() - 1; i++){
        dp0[i] = max(dp0[i - 2] + sticker[i], dp0[i - 1]);
        res0 = max(res0, dp0[i]);
    }
    for (int i = 2; i < sticker.size(); i++){
        dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
        res1 = max(res1, dp1[i]);
    }
    return max(res0, res1);
}

// 원형으로 연결된 숫자가 적힌 스티커에서 한 스티커를 떼면 양옆의 스티커가 망가진다고 할 때, 합이 최대로 스티커를 뗄 때 나오는 합은?
// fs 문제도 아니고, 정렬 문제도 아닌, dp 문제
// 두 가지 시간선을 만들어준다 - 0번 스티커를 뗀 시간선, 1번 스티커를 뗀 시간선
// 조건에 맞게 각 시간선의 0, 1번 dp를 갱신시킨 후, 0번 시간선은 2~n-2, 1번 시간선은 2~n-1번까지 dp를 갱신한다(0번을 뜯었기에 n-1번은 뜯을 수 없음)
// 바로 전 dp(뜯지 않을 때)와 전전 dp + 스티커(뜯을 때) 중 최대인 것을 기록
// 이후 dp 안에서 가장 큰 값이 결과
// DP를 더 많이 공부합시다