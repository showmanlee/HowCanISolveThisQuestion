// Plus Minus
// https://www.hackerrank.com/challenges/plus-minus/problem

void plusMinus(int arr_count, int* arr) {
    int zero = 0, minus = 0, plus = 0, i;
    for (i = 0; i < arr_count; i++){
        if (arr[i] > 0)
            plus++;
        else if (arr[i] < 0)
            minus++;
        else
            zero++;
    }
    printf("%.6f\n%.6f\n%.6f\n", (double)plus / arr_count, (double)minus / arr_count,(double)zero / arr_count);
}

// 전체 원소 중 양수/음수/0 비율을 실수로 표시하기