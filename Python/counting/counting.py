def counting_sort(arr):
    #Check if the array is empty
    if not arr:
        return []
    #Step1 : Find the maximum and minimum value to determine the range of our count array
    max_val = max(arr)
    min_val = min(arr)

    range_of_elements = max_val - min_val + 1

    #Initialize the count array with zeros
    #Its size is (max_val + 1) to accomodate all values from 0 to max_val
    count_array = [0] * range_of_elements

    #Initialize the output array which will hold the sorted elements
    output_array = [0] * len(arr)
    #Step 2: Store the count of each unique element in the input array
    for num in arr:
        count_array[num - min_val] += 1
    
    #Step 3: Update count_array so that each element at index i 
    #contains the actual position of this element in output array
    #This is done by calculating the prefix sum (cumulative sum)
    for i in range(1, len(count_array)):
        count_array[i] += count_array[i - 1]

    #Step 4: Build the output array
    #We iterate in reserve to maintain stability (preserving the relative
    #order of elements with the same value)
    for num in reversed(arr):
        #Place the element at its correct position
        output_array[count_array[num - min_val] - 1] = num
        #Decrease the count for the next occurrence of the same value
        count_array[num - min_val] -= 1
    
    return output_array

def main():
    try:
        #Prompt the user for a list of number separated by spaces
        us_ip = input("Enter a list of integers (separated by spaces): ")

        #Convert the input string into a list of integers
        us_arr = [int(x) for x in us_ip.split()]
        if not us_arr:
            print("This list is empty.")
        else:
            #Perform counting sort
            sorted_arr = counting_sort(us_arr)
            #Display the results
            print("Orginal array: ", us_arr)
            print("Sorted array: ", sorted_arr)
    except ValueError:
        print("Error: Please enter only valid integers separated by spaces.")
if __name__ == "__main__":
    main()
