// Day 8: Create a Button
// https://www.hackerrank.com/challenges/js10-create-a-button/problem

document.addEventListener('DOMContentLoaded', () => {
    const button = document.getElementById('btn');
    
    button.addEventListener('click', (e) => {
          const count = Number(e.currentTarget.innerText) + 1;
        
          e.currentTarget.innerText = count;
    });
});

// 아무튼 Javascript는 웹 언어
// Javascript와 CSS, HTML을 연계할 줄 알아야 한다
// 지금은 이 코드를 보고 어떤 원리인지 이해해보자