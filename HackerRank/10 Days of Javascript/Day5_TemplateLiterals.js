// Day 5: Template Literals
// https://www.hackerrank.com/challenges/js10-template-literals/problem

function sides(literals, ...expressions) {
    let [a, p] = expressions;
    let v = Math.sqrt(p ** 2 - (a * 16));
    return [(p - v) / 4, (p + v) / 4]
}


function main() {
    let s1 = +(readLine());
    let s2 = +(readLine());
    
    [s1, s2] = [s1, s2].sort();
    
    const [x, y] = sides`The area is: ${s1 * s2}.\nThe perimeter is: ${2 * (s1 + s2)}.`;
    
    console.log((s1 === x) ? s1 : -1);
    console.log((s2 === y) ? s2 : -1);
}

// ``로 묶은 '템플릿 리터럴'은 함수를 적용할 수 있는 리터럴
// foo`리터럴러라 ${a} 리터럴`; 이렇게 하면
// function foo(strings, ...values) 함수를 자동으로 부르게 된다
// 여기서 strings로는 ['리터럴라라', '리터럴']이, values로는 [a]가 들어온다
// 위처럼 = 을 붙여 값을 반환하게 할 수도 있음
// 물론 별도의 함수 없이도 해당 내용을 문자열처럼 출력만 할 수도 있음
// 참고로 Python처럼 ** 연산자 되고, [a, b]로 묶어주면 여러 개의 값을 출력값으로 전달하는 것도 가능