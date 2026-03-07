def heapify(arr, n, i):
    # Initialize largest as root 
    largest = i
    # left child index
    left = 2 * i + 1
    # right child index
    right = 2 * i + 2

    #check if left child exists and is greater than root 
    if left < n and arr[left] > arr[largest]:
        largest = left

    #check if right child exists and is greater than the current largest    
    if right < n and arr[right] > arr[largest]:
        largest = right

    #if the largest is not the root, swap them and continue heapifying 
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        #recursively heapify the affected sub-tree
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    #Step 1: build a maxheap
    #Start from the last non-leaf node and work upwards
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    #Step 2: One by one extract elements from the heap
    for i in range(n - 1, 0, -1):
        #move current root to end(it's the largest element)
        arr[i], arr[0] = arr[0], arr[i]

        #call max heapify on the reduced heap
        heapify(arr, i, 0)
    return arr

def main():
    try:
        #Prompt the user for a list of number separated by spaces
        us_ip = input("Enter a list of integers (separated by spaces): ")

        #Convert the input string into a list of integers
        us_arr = [int(x) for x in us_ip.split()]
        if not us_arr:
            print("This list is empty.")
        else:
            print("Orginal array: ", us_arr)
            #Perform heap sort
            sorted_arr = heap_sort(us_arr)
            #Display the results
            print("Sorted array: ", sorted_arr)
    except ValueError:
        print("Error: Please enter only valid integers separated by spaces.")
if __name__ == "__main__":
    main()