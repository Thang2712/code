def merge(arr): 
    if len(arr) <= 1: 
        return arr 
    mid = len(arr) // 2 
    left = arr[:mid]
    right = arr[mid:]

    left = merge(left)
    right = merge(right)

    i = 0 
    j = 0 
    k = 0 


    while i < len(left) and j < len(right): 
        if left[i] < right[j]:
            arr[k] = left[i]
            i = i + 1
        else: 
            arr[k] = right[j]
            j = j + 1
        k = k + 1 
    while i < len(left): 
        arr[k] = left[i]
        i = i + 1
        k = k + 1
    while j < len(right): 
        arr[k] = right[j]
        j = j + 1 
        k = k + 1 
    return arr

def main(): 
    try:
        us_ip = input("enter a list of number seperated by spaces: ")
        us_arr = [int(x) for x in us_ip.split()]
       
        if not us_arr: 
           print("this is a empty list")
        else: 
            sorted_arr = merge(us_arr.copy())
            print("original array", us_arr)
            print("sorted array", sorted_arr)
    except ValueError:
        print("please enter only numbers seperated by spaces")
if __name__ == "__main__":
    main()
       



