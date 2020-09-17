// 카펫
// https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    brown -= 4;
    for (int i = 1; i <= yellow; i++){
        if (yellow % i == 0){
            int y = i, x = yellow / i;
            if (brown == (x + y) * 2){
                answer.push_back(x + 2);
                answer.push_back(y + 2);
                break;
            }
        }
    }
    
    return answer;
}

// y가 x * y로 표현할 수 있을 때, b - 4가 (x + y) * 2로 표현되면 ok