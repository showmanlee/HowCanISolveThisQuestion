// 단체사진 찍기
// https://programmers.co.kr/learn/courses/30/lessons/1835

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string arrange = "ACFJMNRT";
    do {
        bool ret = true;
        for (string s : data){
            char a = s[0], b = s[2], op = s[3];
            int target = s[4] - '0';
            int dist = abs((int)arrange.find(a) - (int)arrange.find(b)) - 1;
            if (op == '=')
                ret = (target == dist);
            else if (op == '<')
                ret = (target > dist);
            else
                ret = (target < dist);
            if (!ret)
                break;
        }
        answer += (ret ? 1 : 0);
    } while(next_permutation(arrange.begin(), arrange.end()));
    return answer;
}

// 카카오프렌즈 8인(A, C, F, J, M, N, R, T)이 나란히 서서 사진을 찍으려고 한다
// 특정 인물 쌍이 간격을 일정 수대로/초과/미만으로 두고 싶을 때, 가능한 경우의 수 출력하기

// 찍으려는 사람은 8명 - 그리고 그 사람들이 서는 모든 경우의 수를 확인해볼 수 있음
// 따라서 next_permutation 기반으로 접근 - 시작은 알파벳순인 ACFJMNRT
// permutation으로 위치를 잡고, 조건을 적용해보기 - 문자열에서 적용되는 사람, 조건, 간격을 뽑기
// 문자열 find를 통해 조건 상의 사람 위치를 찾고, 두 사람의 위치의 차 -1로 실제 거리 구하기
// 그리고 문자열에서 뽑은 조건식을 이용해 조건에 맞는지 확인
// 이후 모든 조건이 맞았다면 결과값에 1 추가 - 모든 경우 탐색 후 결과 출력하기