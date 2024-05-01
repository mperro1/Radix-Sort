"""
File implementing radix sort algorithm using Python
Name: Marcela Perro 
Semester: Spring 2024 
"""

import time
import random
import sys

MAX = 10  # Assuming we are dealing with decimal numbers

# Simulated memory allocation tracking
allocated_memory = 0
"""
    Tracks memory allocation for simulation purposes.
    Adds the specified size to the global allocated_memory counter.
"""
def memory_track(size):
    global allocated_memory
    allocated_memory += size

"""
    Returns the maximum value in the given array.
"""
def getMax(arr):
    return max(arr)

"""
    Performs counting sort on the array 'arr' based on the digit at the exponent 'exp'.
"""
def countingSort(arr, exp):
    n = len(arr)
    output = [0] * n #Output array initialized with zeros 
    count = [0] * MAX #Count array for storng digit frequencies 
    memory_track(sys.getsizeof(output) + sys.getsizeof(count))

    #Store count of occurrences of each digit 
    for i in arr:
        index = i // exp
        count[index % 10] += 1

    #Change count index to contain the actual position of this digit in output 
    for i in range(1, MAX):
        count[i] += count[i - 1]

    #Build the output array 
    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    #Copy the sorted elemetns back into the original array 
    for i in range(n):
        arr[i] = output[i]

"""
    Main function to sort an array using the Radix Sort algorithm.
"""
def radixSort(arr):
    m = getMax(arr)
    exp = 1
    while m // exp > 0:
        countingSort(arr, exp)
        exp *= 10

"""
    Utility function to print the elements of the array.
"""
def print_array(arr):
    print(' '.join(str(i) for i in arr))

"""
    Main function that executes the Radix Sort for arrays of different sizes and logs the results.
"""
def main(max_n, output_file='radix_sort_results.csv'):
    with open(output_file, 'w') as file:
        file.write("Array Size,Time Taken (seconds),Memory Used (bytes)\n")

        for n in range(1, max_n + 1):
            global allocated_memory
            allocated_memory = 0

            arr = [random.randint(0, 999) for _ in range(n)]
            memory_track(sys.getsizeof(arr))

            start_time = time.time()
            radixSort(arr)
            elapsed_time = time.time() - start_time

            print(f"Array Size: {n}, Time Taken: {elapsed_time:.6f} seconds, Memory Used: {allocated_memory} bytes")
            file.write(f"{n},{elapsed_time:.6f},{allocated_memory}\n")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 radix_sort.py <max array size> [output file]")
        sys.exit(1)

    max_n = int(sys.argv[1])
    output_file = sys.argv[2] if len(sys.argv) > 2 else "radix_sort_results.csv"
    main(max_n, output_file)
