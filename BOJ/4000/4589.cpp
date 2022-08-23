// Gnome Sequencing
// https://www.acmicpc.net/problem/4589

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << "Gnomes:\n";
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a > b && b > c) || (a < b && b < c)) {
            cout << "Ordered\n";
        } else {
            cout << "Unordered\n";
        }
    }
}

// 주어진 3개의 인형이 키 순서대로 서 있는지 판정하기

// 주어진 3개의 수가 오름차순/내림차순인지 아닌지 판정하기 - 대소관계를 봅시다