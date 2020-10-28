// Java Date and Time
// https://www.hackerrank.com/challenges/java-date-and-time/problem

class Result {
    public static String findDay(int month, int day, int year) {
        Calendar cal = Calendar.getInstance();
        cal.set(Calendar.MONTH, month - 1);
        cal.set(Calendar.DATE, day);
        cal.set(Calendar.YEAR, year);
        switch(cal.get(Calendar.DAY_OF_WEEK)){
            case 1:
                return "SUNDAY";
            case 2:
                return "MONDAY";
            case 3:
                return "TUESDAY";
            case 4:
                return "WEDNESDAY";
            case 5:
                return "THURSDAY";
            case 6:
                return "FRIDAY";
            case 7:
                return "SATURDAY";
        }
        return "ERROR";
    }
}

// Java에는 달력 정보를 나타내는 클래스가 있습니다
// Calendar cal = Calendar.getInstance(); - Calender는 추상 클래스기 때문에 미리 생성된 인스턴스를 불러와서 작동
// cal.set(상수, 값)로 값을 지정하고 cal.get(상수)로 값 얻기
// Calender.YEAR, MONTH, DATE, DAY_OF_WEEK, HOUR, HOUR_OF_DAY, MINUTE, SECOND 등의 상수 활용
// Calender.MONTH의 범위가 1~12가 아닌 0~11임에 주의