// 패스트 푸드 상금
// https://www.acmicpc.net/problem/9329

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> reqs(n);
        vector<int> prizes(n);
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            for (int j = 0; j < p; j++) {
                int pp;
                cin >> pp;
                reqs[i].push_back(pp);
            }
            cin >> prizes[i];
        }
        vector<int> stickers(m + 1);
        for (int i = 1; i <= m; i++) {
            cin >> stickers[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int minn = 987654321;
            for (int p : reqs[i]) {
                minn = min(minn, stickers[p]);
            }
            res += prizes[i] * minn;
            for (int p : reqs[i]) {
                stickers[p] -= minn;
            }
        }
        cout << res << '\n';
    }
}

// 1부터 m까지의 스티커 소지 현황, 그리고 중복 수령 가능한 해당 상금을 얻기 위해 필요한 스티커 종류들이 주어질 때, 최대로 얻을 수 있는 상금 출력하기

// 한 스티커는 단 하나의 상금 획득에만 사용됨이 보장됨 - 2개 이상의 상금에서 같은 스티커가 쓰이는 경우는 없음
// 때문에 저울질할 필요 없이, 각 상금 조건마다 가장 적게 갖고 있는 스티커만큼 상금을 가져가면 됨