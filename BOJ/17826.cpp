// 나의 학점은?
// https://www.acmicpc.net/problem/17826

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> score(50);
    for (int i = 0; i < 50; i++)
        cin >> score[i];
    int p;
    cin >> p;
    for (int i = 0; i < 50; i++) {
        if (score[i] == p) {
            if (i < 5)
                cout << "A+\n";
            else if (i < 15)
                cout << "A0\n";
            else if (i < 30)
                cout << "B+\n";
            else if (i < 35)
                cout << "B0\n";
            else if (i < 45)
                cout << "C+\n";
            else if (i < 48)
                cout << "C0\n";
            else
                cout << "F\n";
            break;
        }
    }
}

// 내림차순으로 정렬된 점수표가 주어졌을 때, 내 점수는 무슨 학점을 받을까?
// 내려오면서 내 점수를 찾고, 그 위치가 어디냐에 따라 학점이 결정된다
// 이미 정렬이 되어있으므로 우리가 정렬을 할 필요는 없음