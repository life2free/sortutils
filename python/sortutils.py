def insertionSort(arr, order=0):
    '''
    :param arr: the array will be sorted
    :param order: 0 asc, 1 desc
    :return: None
    '''

    for i in range(1, len(arr)):
        tmp = arr[i]
        j = i - 1
        if order == 0:
            while j > -1 and arr[j] > tmp:
                arr[j + 1] = arr[j]
                j -= 1
        else:
            while j > -1 and arr[j] < tmp:
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = tmp


quickSort = lambda arr: arr if len(arr) <= 1 else quickSort([
    item for item in arr[1:] if item < arr[0]]) + [arr[0]] + quickSort([
    item for item in arr[1:] if item >= arr[0]])


def quickSort2(arr, order=0):
    '''

    :param arr:
    :param order:
    :return:
    '''
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]

    if order == 0:
        left_list = [x for x in arr if x < pivot]
        right_list = [x for x in arr if x > pivot]
    else:
        left_list = [x for x in arr if x > pivot]
        right_list = [x for x in arr if x < pivot]
    pivot_list = [x for x in arr if x == pivot]
    print("pivot_list", pivot_list)
    result = []
    l = quickSort(left_list, order)
    r = quickSort(right_list, order)
    if l:
        result.extend(l)
    result.extend(pivot_list)
    if r:
        result.extend(r)
    return result


def partition(arr, low, high):
    i = (low - 1)  # 最小元素索引
    pivot = arr[high]

    for j in range(low, high):

        # 当前元素小于或等于 pivot
        if arr[j] <= pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)


def quickSort１(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quickSort１(arr, low, pi - 1)
        quickSort１(arr, pi + 1, high)


def selectionSort(arr, order=0):
    len_arr = len(arr)
    if len_arr > 1:
        if order == 0:
            for i in range(len_arr - 1):
                min_idx = i
                for j in range(i + 1, len_arr):
                    if arr[min_idx] > arr[j]:
                        min_idx = j
                arr[i], arr[min_idx] = arr[min_idx], arr[i]
        else:
            for i in range(len_arr - 1):
                max_idx = i
                for j in range(i + 1, len_arr):
                    if arr[max_idx] < arr[j]:
                        max_idx = j
                arr[i], arr[max_idx] = arr[max_idx], arr[i]


def bubbleSort(arr, order=0):
    len_arr = len(arr)
    if len_arr > 1:
        for i in range(len_arr - 1):
            swap = False
            for j in range(len_arr - 1 - i):
                if (arr[j] > arr[j + 1] and order == 0) or (arr[j] < arr[j + 1] and order != 0):
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
                    swap = True
            # print("i:", i)
            # print(arr)
            if not swap:
                break


def mergeSort(arr, order=0):
    if len(arr) <= 1:
        return arr

    idx_split = len(arr) // 2
    left_list = mergeSort(arr[:idx_split], order)
    right_list = mergeSort(arr[idx_split:], order)
    return merge(left_list, right_list, order)


def merge(left_list, right_list, order):
    result = []
    l, r = 0, 0
    len_left = len(left_list)
    len_right = len(right_list)
    if (order == 0 and left_list[len_left - 1] <= right_list[0]) or (
            order != 0 and left_list[len_left - 1] >= right_list[0]):
        result.extend(left_list)
        result.extend(right_list)
        return result
    if (order == 0 and left_list[0] >= right_list[len_right - 1]) or (
            order != 0 and left_list[0] <= right_list[len_right - 1]):
        result.extend(right_list)
        result.extend(left_list)
        return result

    while l < len_left and r < len_right:
        if (left_list[l] <= right_list[r] and order == 0) or (left_list[l] >= right_list[r] and order != 0):
            result.extend([left_list[l]])
            l += 1
        else:
            result.extend([right_list[r]])
            r += 1

    result.extend(left_list[l:])
    result.extend(right_list[r:])
    return result


def heapSort(arr, order=0):
    '''

    :param arr: the array need to be sorted
    :param order: the sort direction
    :return: None
    '''

    len_arr = len(arr)
    idx_last_fathernode = int(len_arr / 2 - 1)
    for i in range(idx_last_fathernode, -1, -1):
        adjustHeap(arr, i, len_arr)

    for size in range(len_arr - 1, 0, -1):
        swap(arr, 0, size)
        adjustHeap(arr, 0, size)


def adjustHeap(arr, idx, length):
    temp = arr[idx]
    idx_childnode = 2 * idx + 1
    while idx_childnode < length:
        largestIndex = idx_childnode
        if idx_childnode + 1 < length and arr[idx_childnode] < arr[idx_childnode + 1]:
            largestIndex += 1
        if temp < arr[largestIndex]:
            arr[idx] = arr[largestIndex]
            idx = largestIndex
            idx_childnode = 2 * idx + 1
        else:
            break
    arr[idx] = temp


def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def heapSort1(arr, order=0):
    heapInsert(arr)
    len_arr = len(arr)
    for size in range(len_arr - 1, 0, -1):
        swap(arr, 0, size)
        adjustHeap(arr, 0, size)


def heapInsert(arr):
    len_arr = len(arr)
    for i in range(1, len_arr):
        idx_current = i
        idx_fathernode = (idx_current - 1) // 2
        while idx_fathernode >= 0 and arr[idx_current] > arr[idx_fathernode]:
            swap(arr, idx_current, idx_fathernode)
            idx_current = idx_fathernode
            idx_fathernode = int(idx_current - 1) // 2


def countSort(arr):
    max_val = max(arr)
    min_val = min(arr)
    len_arr = len(arr)
    arr_output = [0] * len_arr
    arr_count = [0] * (max_val - min_val + 1)
    for i in arr:
        arr_count[i - min_val] += 1
    for i in range(1, len(arr_count)):
        arr_count[i] += arr_count[i - 1]

    for i in range(len(arr) - 1, -1, -1):
        idx_count = arr[i] - min_val
        arr_output[arr_count[idx_count] - 1] = arr[i]
        arr_count[idx_count] -= 1
    return arr_output


def shellSort(arr):
    len_arr = len(arr)
    gap = len_arr // 2

    while gap > 0:
        for i in range(gap, len_arr):
            temp = arr[i]
            j = i - gap
            while j > -1 and arr[j] > temp:
                arr[j+gap] = arr[j]
                j -= gap
            arr[j+gap] = temp
        gap = int(gap / 2)