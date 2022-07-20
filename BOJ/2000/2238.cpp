// 경매
// https://www.acmicpc.net/problem/2238

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<string, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int u, n;
    cin >> u >> n;
    vector<int> cnt(u + 1);
    vector<pr> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i].first >> order[i].second;
        cnt[order[i].second]++;
    }
    int minn = 987654321;
    int minc = 987654321;
    for (int i = 1; i <= u; i++) {
        if (cnt[i] != 0) {
            if (minc > cnt[i]) {
                minc = cnt[i];
                minn = i; 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (order[i].second == minn) {
            cout << order[i].first << ' ' << order[i].second << '\n';
            break;
        }
    }
}

// 경매에서 가격을 제시한 사람의 이름과 그 가격이 주어졌을 때, 아래의 우선 순위로 낙찰자 결정하기
// 가장 적은 수의 사람이 제시한 가격 -> 그 중 가장 가장 낮은 가격 -> 그 가격을 먼저 부른 사람

// 이를 위해 가격이 등장한 횟수를 기억하는 배열, 그리고 사람과 가격을 순서대로 저장하는 배열이 필요하다
// 등장 횟수의 경우 최대 가격 범위가 주어지므로 그 크기로 만들어두고, 제시 순서 배열은 pair로 만들어둔다
// 같은 사람이 가격을 여러 번 제시할 수도 있으나, 제시 자체가 무효화되는 건 아니므로 신경쓰지 않아도 됨
// 이렇게 입력을 받은 뒤 등장 횟수 배열을 돌며 등장한 가격 중 가장 낮은 가격(중에서 먼저 나온 가격)을 저장한 후, 제시 순서 배열을 돌며 첫 번째로 그 가격을 제시한 사람을 찾아 출력

// 오늘로 solved.ac 스트릭 365일차를 맞습니다 - 고생 많으셨습니다
// 이제 512를 향해 스트릭을 이어나가봅시다