def insertionsort(arr):
    n = len(arr)
    if n <= 1:
        return arr
    for j in range(1, n):
        key = arr[j]
        i = j - 1
        while i >= 0 and arr[i] > key:
            arr[i + 1] = arr[i]
            i = i - 1
        arr[i + 1] = key
    return arr


def main():
    try:
        us_ip = input("enter a list of integers (seperated by spaces) : ")
        us_arr = [int(x) for x in us_ip.split()]

        if not us_arr:
            print("this is empty array")
        else:
            sorted_arr = insertionsort(us_arr.copy())

            print("original array: ", us_arr)
            print("sorted array: ", sorted_arr)
    except ValueError:
        print("Please enter only valid integers seperated by space")


if __name__ == "__main__":
    main()
