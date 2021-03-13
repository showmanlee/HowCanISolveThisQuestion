// 과제 안 내신 분..?
// https://www.acmicpc.net/problem/5597

#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<bool> v(31);
    for (int i = 0; i < 28; i++){
        int n;
        cin >> n;
        v[n] = true;
    }
    for (int i = 1; i <= 30; i++)
        if (!v[i])
            cout << i << '\n';
}

// 학생 30명 중 과제를 제출하지 않은 2명의 번호는?
// 30칸의 배열 생성 후 낸 사람만 체크