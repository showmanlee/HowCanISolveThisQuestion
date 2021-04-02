// 나3곱2
// https://www.acmicpc.net/problem/16936

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long n;
long long board[101];
long long order[101];
bool visit[101];
bool finish;

void ordering(long long c, long long prev) {
	if (finish)
		return;
	if (c == n) {
		for (long long i = 0; i < n; i++)
			cout << board[order[i]] << ' ';
		cout << '\n';
		finish = true;
		return;
	}
	if (board[prev] % 3 == 0) {
		long long p = board[prev] / 3;
		for (long long i = prev; i >= 0; i--) {
			if (!visit[i]) {
				if (board[i] == p) {
					order[c] = i;
					visit[i] = true;
					ordering(c + 1, i);
					visit[i] = false;
					order[c] = -1;
					break;
				}
				else if (board[i] < p)
					break;
			}
		}
	}
	long long p = board[prev] * 2;
	for (long long i = prev; i < n; i++) {
		if (!visit[i]) {
			if (board[i] == p) {
				order[c] = i;
				visit[i] = true;
				ordering(c + 1, i);
				visit[i] = false;
				order[c] = -1;
				break;
			}
			else if (board[i] > p)
				break;
		}
	}
}

int main(void) {
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> board[i];
		order[i] = -1;
	}
	sort(board, board + n);
	finish = false;
	for (long long i = 0; i < n; i++) {
		order[0] = i;
		visit[i] = true;
		ordering(1, i);
		visit[i] = false;
		order[0] = -1;
	}
}

// 어떤 수를 나누기 3(3으로 나누어떨어질 때), 곱하기 2 연산 중 하나를 선택해 적용한 수열의 순서를 섞은 수열이 주어질 때, 원래 수열 구하기
// 정렬 관점에서 풀어도 되지만, 지금은 브포 관점에서 풀어봅시다

// 현재 수에서 나누기 3이 되는 경우, 곱하기 2가 되는 경우를 찾아 순서를 기록하며 들어가기만 하면 됨
// 문제는 수열의 길이가 최대 100임 - 단순하게 브포를 도입하거나 순열로 짜맞추면 100!의 늪에 빠질 가능성이 있음
// 시간복잡도를 줄이기 위해 주어진 수열 미리 정렬해두기 - 곱하기 2은 마지막에 뽑은 원소 이후의 원소들만, 나누기 3는 이전의 원소들만 조사하면 됨
// 브포 함수에는 현재까지 몇 개의 숫자가 뽑혔나, 그리고 마지막으로 뽑은 원소의 위치는 어디인가를 매개함수로 전달
// 그리고 원소의 사용 여부와 결과 순서에 등장하는 원소를 저장하여 마지막에 출력할 수 있게 함
// 이렇게 조건에 맞는 원소들을 찾아	순서를 붙여주면서 끝까지 가면 수열 출력 후 중단점 발동, 중단점 이후에는 호출되는 모든 브포 함수가 탐색을 하지 않고 반환하여 시간 절약
// 수열 원소 범위가 long long임에 주의