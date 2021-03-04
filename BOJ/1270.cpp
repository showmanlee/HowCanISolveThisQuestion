// 전쟁 - 땅따먹기
// https://www.acmicpc.net/problem/1270

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        map<long long, int> count;
        int maxc = 0;
        long long maxi = 0;
        for (int i = 0; i < n; i++) {
            long long c;
            cin >> c;
            count[c]++;
            if (count[c] > maxc) {
                maxc = count[c];
                maxi = c;
            }
        }
        if (maxc > n / 2)
            cout << maxi << '\n';
        else
            cout << "SYJKGW" << '\n';
    }
}

// 각 땅의 과반을 차지하고 있는 군대의 번호 출력하기(과반이 없으면 "SYJKGW")
// 번호가 연속되서 나오지 않으므로 map으로 카운트하고 최댓값은 따로 체크
// 입력되는 병사 번호의 범위가 미세하게 int를 넘어섬에 주의(2^31)