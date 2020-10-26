// Number Line Jumps
// https://www.hackerrank.com/challenges/kangaroo/problem

string kangaroo(int x1, int v1, int x2, int v2) {
    while(x1 < x2){
        x1 += v1;
        x2 += v2;
        if (x1 == x2)
            return "YES";
    }
    return "NO";
}

// x1, x2에서 v1, v2 간격으로 점프하는 캥거루들이 같은 점프로 서로 만나는가?