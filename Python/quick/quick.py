def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    less = [x for x in arr[:-1] if x < pivot]
    equal = [pivot]
    greater = [x for x in arr[:-1] if x > pivot]

    return quick_sort(less) + equal + quick_sort(greater)


data = [3, 6, 8, 10, 1, 2, 1]
print("Unsorted array:", data)
sorted_data = quick_sort(data)
print("Sorted array:", sorted_data)

