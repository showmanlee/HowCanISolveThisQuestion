// Day 6: Javascript Dates
// https://www.hackerrank.com/challenges/js10-date/problem

function getDayName(dateString) {
    let dayName;
    let date = new Date(dateString);

    if (date.getDay() == 0)
        dayName = "Sunday";
    else if (date.getDay() == 1)
        dayName = "Monday";
    else if (date.getDay() == 2)
        dayName = "Tuesday";
    else if (date.getDay() == 3)
        dayName = "Wednesday";
    else if (date.getDay() == 4)
        dayName = "Thursday";
    else if (date.getDay() == 5)
        dayName = "Friday";
    else if (date.getDay() == 6)
        dayName = "Saturday";   

    return dayName;
}

// Javascript에는 Date 객체가 있다
// new Date() - 현재 시간, new Date(string) - 'MM/DD/YYYY', 'Jan 1, 1970' 등 규칙에 맞는 문자열을 받아 자동으로 날짜로 바꿔준다
// 아니면 new Date(year, month, day, hour, minutes, seconds, milliseconds)을 쓰거나
// Date.getTime() = 1970.1.1이후로 지난 밀리초(UNIX 시간 체계)
// Date.getFullYear() = 년, getMonth() = 월(0~11), getDate() = 일(1~31), getDay() = 요일(0~6, 일요일부터), getHours() = 시간(24시간), getMinutes(), getSeconds(), getMilliseconds()... 