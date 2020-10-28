// Day 2: Loops
// https://www.hackerrank.com/challenges/js10-loops/problem

function vowelsAndConsonants(s) {
  for (let i = 0; i < s.length; i++){
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        console.log(s[i])
  }
  for (let i = 0; i < s.length; i++){
    if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'))
        console.log(s[i])
  }
}

// 한 번은 모음만, 그 다음에는 자음만 나오는 순서대로 찍기
// string.length