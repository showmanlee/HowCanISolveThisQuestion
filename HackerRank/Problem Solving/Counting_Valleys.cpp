// Counting Valleys
// https://www.hackerrank.com/challenges/counting-valleys

int countingValleys(int steps, string path) {
    int height = 0, answer = 0;
    for (int i = 0; i < steps; i++){
        if (path[i] == 'U')
            height++;
        else{
            height--;
            if (height == -1)
                answer++;
        }
    }
    return answer;
}

// 지형의 골짜기 수 구하기