// Pointer
// https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

void update(int *a,int *b) {
    int p = *a, q = *b;
    *a = p + q;
    if (p > q)
        *b = p - q;
    else 
        *b = q - p;
}

// 매개변수로 들어온 포인터를 이용하여 값 바꾸기
// *pa = &a = 주소 뽑기, na = *pa = 값 뽑기