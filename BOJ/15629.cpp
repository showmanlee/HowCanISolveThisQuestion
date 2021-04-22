// Africa
// https://www.acmicpc.net/problem/15629

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> order(n);
	for (int i = 0; i < n; i++)
		cin >> order[i];
	int res = 0;
	bool visitSA = false;
	for (int i = 0; i < n; i++) {
		if (order[i] == "botswana")
			continue;
		else if (order[i] == "ethiopia")
			res += 50;
		else if (order[i] == "kenya")
			res += 50;
		else if (order[i] == "namibia") {
			if (visitSA)
				res += 40;
			else
				res += 140;
		}
		else if (order[i] == "south-africa")
			visitSA = true;
		else if (order[i] == "tanzania")
			res += 50;
		else if (order[i] == "zambia") {
			res += 50;
			if (i != 0 && order[i - 1] == "zimbabwe")
				res -= 30;
		}
		else if (order[i] == "zimbabwe") {
			res += 30;
			if (i != 0 && order[i - 1] == "zambia")
				res -= 30;
		}
	}
	cout << res << '\n';
}

// 지문을 잘 읽고 나라 이름들이 중복 없이 순서대로 주어졌을 때, 해당되는 수를 출력하시오
// 요구사항은 바로...
// "국가를 방문하는 순서가 있을 때 총 비자 발급 비용을 구하려고 한다. (중략) 이때 비용을 줄이기 위해 정해진 순서 중간에 다른 국가를 방문하는 것도 생각해볼 수 있겠지만 일단 여기에서는 생각하지 않기로 하자."

// 비자 발급비는 다음과 같다:
// 보츠와나   - 무비자
// 에티오피아 - 50
// 케냐       - 50(1회), 100(다회)
// 나미비아   - 남아공에서 비자를 받으면 40
//            - 그렇지 않다면 140
// 남아공     - 무비자
// 탄자니아   - 50(1회), 100(다회)
// 잠비아     - 50(1회), 80(2회)
// 짐바브웨   - 30(1회), 45(2회)
//            - 잠비아-짐바브웨 연합 비자 - 50(타국가 이동 시 소멸)

// 어차피 여기서는 다회 방문을 하지 않기 때문에 다회 비자는 고려할 필요가 없음
// 기본적으로 지문의 정보대로 나라에 방문하면 비자비를 누적하면 되지만, 특별히 조건을 봐줘야 하는 곳도 있다
// "south-africa": "namibia"에서의 비자 할인을 위해 남아공 방문 여부 체크 필요
// "namibia"     : "south-africa"를 방문 여부에 따라 비자비가 달라짐
// "zimbabwe"    : 방문 직전에 "zambia"를 방문했으면 두 국가를 합쳐 50달러만 지불해야 함(50+30-30)
// "zambia"      : 방문 직전에 "zimbabwe"를 방문했으면 두 국가를 합쳐 50달러만 지불해야 함(30+50-30)

// 결과적으로 보면 단순(?)한 조건문 문제