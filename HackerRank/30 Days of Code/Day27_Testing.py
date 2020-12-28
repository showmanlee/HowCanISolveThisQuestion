# Day 27: Testing
# https://www.hackerrank.com/challenges/30-testing/problem

def minimum_index(seq):
    if len(seq) == 0:
        raise ValueError("Cannot get the minimum value index from an empty sequence")
    min_idx = 0
    for i in range(1, len(seq)):
        if seq[i] < seq[min_idx]:
            min_idx = i
    return min_idx
class TestDataEmptyArray(object):
    
    @staticmethod
    def get_array():
        return []

class TestDataUniqueValues(object):

    @staticmethod
    def get_array():
        return [3,1,5,6,8,4]

    @staticmethod
    def get_expected_result():
        return 1

class TestDataExactlyTwoDifferentMinimums(object):

    @staticmethod    
    def get_array():
        return [3,1,5,1,8,4]
    
    @staticmethod
    def get_expected_result():
        return 1


def TestWithEmptyArray():
    try:
        seq = TestDataEmptyArray.get_array()
        result = minimum_index(seq)
    except ValueError as e:
        pass
    else:
        assert False


def TestWithUniqueValues():
    seq = TestDataUniqueValues.get_array()
    assert len(seq) >= 2

    assert len(list(set(seq))) == len(seq)

    expected_result = TestDataUniqueValues.get_expected_result()
    result = minimum_index(seq)
    assert result == expected_result


def TestiWithExactyTwoDifferentMinimums():
    seq = TestDataExactlyTwoDifferentMinimums.get_array()
    assert len(seq) >= 2
    tmp = sorted(seq)
    assert tmp[0] == tmp[1] and (len(tmp) == 2 or tmp[1] < tmp[2])

    expected_result = TestDataExactlyTwoDifferentMinimums.get_expected_result()
    result = minimum_index(seq)
    assert result == expected_result

TestWithEmptyArray()
TestWithUniqueValues()
TestiWithExactyTwoDifferentMinimums()
print("OK")

# 단위 테스트를 위한 테스트 코드 작성하기
# 배열의 최솟값이 있는 인덱스를 알아내는 코드, 여기서 빈 배열이 들어간 경우(err), 모두 다른 값이 들어가있는 경우, 최솟값이 정확히 2개인 경우를 테스트하고자 한다
# 조건문 앞에 assert 붙여 확인
# 클래스 함수를 정적 함수로 바꾸려면 위에 @staticmethod 달기