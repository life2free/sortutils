import sortutils

def printArray(arr):
    for item in arr:
        print(f"{item} ", end = '')
    print()

def test():
    array = [1, 61, 8, 19, 3, -5, 7, 50, 0, 22, 100, -1, 19, 0]
    print("Origin array:")
    printArray(array)
    print()
    
    sortedArray = sortutils.mergeSort(array)
    print("After sorted by asc: ")
    printArray(sortedArray)
    print()
    sortedArray = sortutils.mergeSort(array,1)
    print("After sorted by desc: ")
    printArray(sortedArray)
    print()

test()
