// 임스와 함께하는 미니게임
// https://www.acmicpc.net/problem/25757

#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    char c;
    cin >> n >> c;
    map<string, bool> v;
    int res = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!v[s]) {
            v[s] = true;
            res++;
        }
    }
    res = floor(res / (c == 'Y' ? 1.0 : (c == 'F' ? 2.0 : 3.0)));
    cout << res << '\n';
}

// 각각 1/2/3명의 친구와 같이 할 수 있는 게임이 있을 때, 주어진 사람들과 중복 없이 인원수 가득 채워서 할 수 있는 판 수 구하기

// map으로 중복 없는 인원수 구하고 그걸 참여 인원수로 나눠 구하기