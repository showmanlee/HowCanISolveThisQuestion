// 수 정렬하기 2
// https://www.acmicpc.net/problem/2751

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    int n, p;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for (auto k = v.begin(); k != v.end(); k++){
        cout << *k << '\n';
    }
}

// 정렬을 빠르게 하는 방법 https://www.acmicpc.net/board/view/31887
// 1. O(nlogn)인 정렬 알고리즘 사용(퀵, 힙, 병합)
// 1.1 퀵 정렬(피벗 지정 후 높은쪽 낮은쪽 인덱스 옮겨가다가 엇갈리면 낮은쪽과 피벗 스왑, 이후 새로운 피벗 위치를 기준으로 좌우로 나눠 다시 정렬)은 최악 상황(이미 (역)정렬된 경우)에서 O(n^2)가 나오기 때문에 사용하지 않길 권함(지금은 되긴 했지만)
// 1.2 병합 정렬(배열을 절반씩 나누어가다가 1개가 되면 옆에 있는 거랑 값 비교하며 새로운 배열에 저장)은 정복 단계에서 동적 할당 시 전체 배열만큼 크기를 지정하면 안 됨 -> 같은 크기의 배열을 n번 만큼 할당하여 O(n^2)가 되기 때문
// 1.3 힙 정렬 구현 시 쓸데없는 연산(원소 넣고 뺄 때마다 힙 재정렬)해서 시간 늘리지 말 것
// 2. 줄바꿈할 때 flush까지 하는 endl 사용 금지 - 실제로 이걸로 등락 갈리는 경우 꽤 있음
// 주어지는 숫자 범위가 음수까지 포함되었는지 확인(음수면 카운팅 정렬 사용 시 주의 필요)