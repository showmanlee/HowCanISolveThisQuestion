// 다트 게임(2018 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/17682

#include <string>
#include <cstdlib>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int previous = 0;
    int current = 0;
    bool ready = false;
    string p;
    for (int i = 0; i < dartResult.length(); i++){
        if (dartResult[i] >= '0' && dartResult[i] <= '9'){
            if (current != 0){
                answer += previous;
                previous = current;
                current = 0;
            }
            p += dartResult[i];
        }
        else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            current = atoi(p.c_str());
            p = "";
            if (dartResult[i] == 'D')
                current *= current;
            else if (dartResult[i] == 'T')
                current *= current * current;
        }
        else if (dartResult[i] == '*'){
            current *= 2;
            previous *= 2;
        }
        else if (dartResult[i] == '#')
            current *= -1;
    }
    answer += previous;
    answer += current;
    return answer;
}

// 3번 던지고, 점수 체계는 점수/보너스/옵션 순
// 점수는 0~10
// 보너스는 S,D,T, 각각 1,2,3제곱
// 옵션 - *는 지금 점수와 전 점수를 2배로(지금과 전 점수를 한번 더 더해줌)
//          - 처음 나온 경우 그 점수만, */#와 중첩될 수 있음(2번 연속 나오면 가운데 있는 점수가 4배)
//      - #은 지금 점수를 마이너스로