def findPair(array, sum):
    array.sort()
    startIndex = 0
    endIndex = len(array)-1

    while (startIndex < endIndex):
        if (array[startIndex] + array[endIndex] == sum):
            print(array[startIndex],array[endIndex])
            startIndex += 1
            endIndex -= 1
        if ((sum - array[startIndex]) > array[endIndex]):
            startIndex += 1
        if ((sum - array[startIndex]) < array[endIndex]):
            endIndex -= 1


array = [ 8, 7, 2, 5, 3, 1]
sum = 10

findPair(array, sum)
