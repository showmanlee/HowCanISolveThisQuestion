// 0과 1
// https://www.acmicpc.net/problem/8111

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, char> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		vector<bool> visit(n);
		vector<pr> where(n);
		queue<int> q;
		q.push(1);
		visit[1] = true;
		where[1] = { -1, '1' };
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if (p == 0) 
				break;
			int pp = (p * 10) % n;
			if (!visit[pp]) {
				visit[pp] = true;
				where[pp] = { p, '0' };
				q.push(pp);
			}
			pp = (pp + 1) % n;
			if (!visit[pp]) {
				visit[pp] = true;
				where[pp] = { p, '1' };
				q.push(pp);
			}
		}
		string res;
		int i = 0;
		while (i != -1) {
			res = where[i].second + res;
			i = where[i].first;
		}
		if (res.length() > 100)
			cout << "BRAK\n";
		else
			cout << res << '\n';
	}
}

// n의 배수 중 0과 1로만 이루어진 길이 100 이하의 자연수 출력하기
// 당연히 주구장창 반복문 돌려서 길이 100 만들어서 확인하라는 뜻은 아님
// 하지만 '0과 1로만 이루어진 길이 100 이하의 자연수'는 bfs로 쉽게 만들 수 있음 - 1부터 시작해 *10 or *10 + 1로 확장
// 그러나 나오는 결과량(2^100 - 1)을 미뤄보면 이것도 불가능 - 애초에 100자리는 나머지 연산이 안됨

// 나머지 연산하니 나오는 아이디어 - bfs는 n의 나머지로 돌리고, 등장한 숫자들에 대해 어디서 왔는지 기록하기
// 어디서 왔는지 기록하는 배열(where)에는 해당 수가 어디서 왔는지는 물론, 그 결과 뭐가 뒤에 붙었는지(0, 1)도 표시한다 - pair
// n이 20000까지니까 visit 배열도 운영 가능 - n의 배수임은 곧 n으로 나눈 나머지가 0이라는 것
// 또한 이미 방문한 수가 bfs로 들어오면 사이클에 빠져 영원히 배수가 될 수 없음을 의미하기도 한다
// 그리고 '곱해서' 나머지를 만들기 때문에 결과적으로는 수를 불려가고 있는 것과 같음

// 이를 이용해 bfs를 돌려보자 - n == 1이라면 bfs가 성립되지 않으니 그냥 1 출력하기
// 진입점인 1의 where에 { -1, '1'}을 기록하고 진입 - 여기서 수가 끝남을 표시
// 큐 안에서는 (p * 10) % n, (p * 10 + 1) % n에 대해 방문 여부를 확인한 후 where에 기록하고 큐에 삽입해준다
// 그러다가 0이 나오면(n의 배수가 되면) 중지

// 결과는 문자열로 출력되어야 함
// where[0]부터 시작하여 해당 수에서 추가된 숫자를 (역순이므로) 앞에 붙여가며 인덱스를 타고 올라간다
// 그러다가 -1을 만나면 종료
// 여기서 나온 결과의 길이가 100을 넘어서면 에러

// solved.ac 플래티넘 진입!
// 해이해지지 않고 이거라도 열심히 계속 해야지