// Birthday Cake Candles
// https://www.hackerrank.com/challenges/birthday-cake-candles/problem

int birthdayCakeCandles(vector<int> candles) {
    int max = 0, count = 0;
    for (int i = 0; i < candles.size(); i++){
        if (candles[i] == max)
            count++;
        else if (candles[i] > max){
            max = candles[i];
            count = 1;
        }
    }
    return count;
}

// 가장 긴 초의 개수 구하기
