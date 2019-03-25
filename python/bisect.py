def solve(array):
    mid = calc(array)

    return (array[:mid+1], array[mid:])

def calc(array):
    high = len(array)
    low = 0
    while low < high:
        mid = (low + high)//2
        if mid == 0:
            return 0
        elif mid == len(array) - 1:
            return len(array) - 1

        a, b, c = array[mid - 1], array[mid], array[mid + 1]
        if a < b < c:
            low = mid
        elif a > b > c:
            high = mid
        else:
            return mid

print(solve([1, 3, 4, 5, 6, 7, 9, 4, 1]))
