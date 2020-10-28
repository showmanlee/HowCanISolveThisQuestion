// Day 2: Conditional Statements: Switch
// https://www.hackerrank.com/challenges/js10-switch/problem

function getLetter(s) {
    let letter;
    switch(s[0]){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            letter = 'A';
            break;
        case 'b':
        case 'c':
        case 'd':
        case 'f':
        case 'g':
            letter = 'B';
            break;
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
            letter = 'C';
            break;
        default:
            letter = 'D';
    }
    return letter;
}

// switch문도 다른 언어와 같음
// string 인덱스 따는 법도 같음