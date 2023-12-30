// IOIOI
// https://www.acmicpc.net/problem/5525

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < m; i++) {
		int p = 0;
		if (s[i] == 'O') {
            continue;
        }
		while (s[i + 1] == 'O' && s[i + 2] == 'I') {
			p++;
			if (p == n) {
				res++;
				p--;
			}
			i += 2;
		}
	}
    cout << res << '\n';
}

// I와 O로 구성된 문자열에서 I + (OI * n) 꼴의 문자열이 몇 번 등장하는지 찾기

// 단순 substr로 접근하면 시간초과 - 문자열을 한 번만 순회해서 IOI가 몇 번 나오는지 처리할 수 있어야 함
// 주어진 문자열에서 I를 찾은 뒤, 그 뒤 OI가 붙는 개수를 세주며 인덱스를 뒤로 보내준다
// 여기서 OI가 n개가 된다면 결과에 누적해주고 앞의 IO를 뺴준다 - 그게 p--의 역할