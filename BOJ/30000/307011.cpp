// 돌아온 똥게임
// https://www.acmicpc.net/problem/30701

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    long long d;
    cin >> n >> d;
    vector<long long> monster, equip;
    for (int i = 0; i < n; i++) {
        int a;
        long long x;
        cin >> a >> x;
        if (a == 1) {
            monster.push_back(x);
        } else {
            equip.push_back(x);
        }
    }
    sort(monster.begin(), monster.end());
    sort(equip.begin(), equip.end());
    int res = 0;
    int i = 0, j = 0;
    while (i < monster.size() || j < equip.size()) {
        if (i < monster.size() && monster[i] < d) {
            d += monster[i];
            res++;
            i++;
        } else if (j < equip.size()) {
            d *= equip[j];
            res++;
            j++;
        } else {
            break;
        }
    }
    cout << res << '\n';
}

// 주어진 조건대로 방을 돌파하며 몬스터를 물리칠 때, 최대로 밀 수 있는 방의 개수 구하기