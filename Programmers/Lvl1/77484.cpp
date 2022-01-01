// 로또의 최고 순위와 최저 순위
// https://programmers.co.kr/learn/courses/30/lessons/77484

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ranking(int p) {
    if (p <= 1) {
        return 6;
    }
    else {
        return 6 - p + 1;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct = 0;
    int empty = 0;
    for (int i = 0; i < 6; i++) {
        if (lottos[i] == 0) {
            empty++;
            continue;
        }
        for (int j = 0; j < 6; j++) {
            if (lottos[i] == win_nums[j]) {
                correct++;
                continue;
            }
        }
    }
    answer.push_back(ranking(correct + empty));
    answer.push_back(ranking(correct));
    return answer;
}

// 로또 추첨 결과와 기억하고 있는 로또 용지가 주어질 때, 얻을 수 있는 최소/최대 등수 구하기

// 원래 2등은 없다고 치고 6~2개 맞췄을 때 1~5등이라고 가정
// 로또 용지에서 빈칸의 개수와 맞춘 개수를 구한 뒤, 빈칸을 모두 맞춘 개수와 모두 못 맞춘 개수에 대한 등수를 구해 출력하기