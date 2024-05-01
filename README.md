# Research Paper
* Name:Marcela Perro        
* Semester: Spring 2024
* Topic: Radix Sort Algorithm
* Link The Repository: https://github.com/Sp24-CS5008-Online-Lionelle/final-reseach-paper-mperro1

## Overview

This report examines the efficiency of Radix Sort, a non-comparative integer sorting algorithm. Unlike like comparison-based sorting algorithms like quicksort, merge sort, Radix sort processes integer elements by their individual digits, and sorts them according to their digit's place value. It starts by sorting numbers from the least significant digit to the most significant digit, or vice versa. This process is then repeated for each digit in the longest number. Radix Sort is known for its ability to handle large datasets with somewhat linear time complexity, depending on the number of digits in the largest number. 

Radix sort originated in the 19th century with the development of the punch card system by Herman Hollerith, used in 1890 U.S Census. This form of radix sort was mechanical, and relied on physical sorting of cards. The modern algorithmic approach was formalized in computer science, and became an important method for digital data processing. Interesting fact, Herman Hellerith later went on to establish his own company known as the tabulating machine, and in 1924 it was renamed to what we know today as International Business Machines (IBM). 

This report aims to explore the intricacies of Radix Sort, examining its operational mechanics, time and space complexities, and empirical performance across different programming languages, particularly C and Python. Through theoretical analysis and practical experimentation, the report will provide a comprehensive look at the utility and performance of Radix Sort in contemporary computing.

### How Radix Sort Works 
For Integers:
1. Identifies the number of digits in the largest number (this determines the number of sorting passes).
2. Sorts all numbers based on the least significant digit. Group them accordingly, keeping their relative order intact.
3. Proceeds to the next significant digit. Sort and group again, maintaining their relative order from the previous step.
4. Repeats the process for each digit until you sort by the most significant digit.

Example with an array of integers = Array: [170, 45, 75, 90, 802, 24, 2, 66]
* Step 1: 170, 90, 802, 2, 24, 45, 75, 66
* Step 2: 802, 2, 24, 45, 66, 170, 75, 90
* Step 3: 802, 2, 24, 45, 66, 170, 75, 90
* Step 4: 2, 24, 45, 66, 75, 90, 170, 802

For Strings: 
1. Determines the maximum string length in the array, which dictates the number of sorting passes needed.
2. Sorts based on the least significant character. Starting from the rightmost character, group and sort the strings accordingly, ensuring their relative order remains unchanged.
3. Moves to the next significant character. Proceeds leftward to the next character in the string. Sorts and groups the strings again, preserving their relative order from the previous sorting pass.
4. Repeats for each character position. Continues this process, moving leftwards through each character position, until it reaches the most significant character (the leftmost one) of the longest string.

Example with an array of strings = Array: ["rat", "mat", "bat", "cat", "hat"]
* Step 1: "rat", "bat", "mat", "cat", "hat"
* Step 2: "mat", "bat", "cat", "hat", "rat"
* Step 3: "bat", "cat", "hat", "mat", "rat"

## Analysis of Algorithm/Datastructure

* Time Complexity: $O(nk)$
The time complexity of Radix Sort is linearly proportional to the number of elements $n$ and the number of digits $k$ in the maximum number. Since it processes each digit of the numbers, the time to sort is dependent on the length of the longest number 

* Space Complexity: $O(n + k)$
Radix Sort requires additional space for the counting sort of each digit, which involves creating counting and output arrays. The space complexity is therefore linear in relation to both the number of elements and the number of digits. In terms of space complexity Radix Sort is more demanding than other sorting algorithms, this is because it requires additional space to hold the counting and output arrays for each digit's sorting pass. 

## Empirical Analysis

The implemenation of Radix Sort in C and Python were tested to measure execution time and memory usage with various array sizes. The tests involve sorting arrays filled with random integers, and the results were recorded to understand the algorithms performance, and differences in programming environments. 

### Time and Memory Analysis 
The analysis revealed that Radix Sort maintains a relatively consistent performance as array sizes increase. The execution time grows linearly with the size of the array, which aligns with the theoretical time complexity of $O(nk)$.

The memory usage also showed a linear increase, consistent with the space complexity of $O(n + k)$. This increase is due to the need for additional arrays to perform the counting sort for each digit of the numbers being sorted.


#### Graphic 1 (C Runtimes)
![c_runtimes](https://github.com/Sp24-CS5008-Online-Lionelle/final-reseach-paper-mperro1/assets/143905499/571553da-7521-4c85-9d32-23d55ccb256d)
The execution time, on average increases with the array size, which aligns with Radix Sorts linear time complexity. There are noticeable spikes in the execution time at certain array sizes, such as 38, 46, 49, 77, and 88 through 96. Despite some spikes, the overall times remain within a small magnitude, implying that radix sort is performing efficiently for the tested array sizes.
#### Graphic 2 (Python Runtimes)
![python_runtimes](https://github.com/Sp24-CS5008-Online-Lionelle/final-reseach-paper-mperro1/assets/143905499/fbea133c-442e-4961-b3cd-d2ac544e7d66)
Specific observations from this graph. The execution time remains relatively low for small array sizes. There is a noticieable spike at size 74. For array sizes close to 100, the execution time seems to plateau around 0.0001 seconds, excluding the spike at size 82 with 0.000276 seconds and size 84 with 0.000252 seconds. On average, the sorting time does not increase dramatically, which indicates good performance and scaling of the radix sort algorithm for the given range of array sizes. This aligns well with the linear time complexity with respect to the number of elements. 
#### Graphic 3 (Memory Usage)
![memory_usage](https://github.com/Sp24-CS5008-Online-Lionelle/final-reseach-paper-mperro1/assets/143905499/467d4c99-40b6-49dd-a7dc-0b99ff59b242)
Both data sets for memory usage by Python and C are identical. Both implementations exhibit a consistent increase in memory usage as the array size increases, which is expected since Radix Sort allocates additional space for its counting and output arrays proportional to the input array size. Given that the memory usage data for both Python and C is the same, we can conclude that, at least in terms of space complexity, both implementations are equally efficient. 

### Comparison Between C and Python Implementations 
Both implementations exhibit the expected linear growth in time complexity, but with notable differences in execution speed and memory usage. The C implementation generally performed faster. This difference is likely due to C's lower-level memory management and the overhead of Python's dynamic data structures.

In comparing the C and Python implementations for Radix Sort reveals differences in execution speed and memory management. In C, the explicit memory management offers direct control over the memory, which can lead to better memory efficiency, but requires more detailed code. Whereas, the Python code since its more abstract and simple may not be as memory-efficient due to the overhead of its dynamic data structure and garbage collection. 
Python's implementation its easier to use and read but for larger arrays it incurs additional overhead, impacting its performace. It is still very efficient. 

## Implementation
### Language Used 
The implementation of Radix Sort was carried out in C and Python. 

### Libraries Used 
* stdio.h for input/output operations, such as printing to the console and file handling.
* stdlib.h for dynamic memory allocation and random number generation.
* time.h for measuring the execution time of the sorting algorithm.
* stdbool.h and string.h were included but not actively used in the provided snippets.

### Key Points of the Algorithm/Data Structure Implementation 
The malloc_track and free_track functions in [radix_sort.c](radix_sort.c) were designed to monitor memory allocation and deallocation, providing insights into the memory usage of Radix Sort.
```c
void* malloc_track(size_t size) {
    void *ptr = malloc(size);
    if (ptr) {
        allocated_memory += size;
    }
    return ptr;
}

// Custom memory deallocation function
void free_track(void *ptr) {
    if (ptr) {
        //allocated_memory -= size;
        free(ptr);
    }
}
```
getMax: Finds the maximum integer value in the array. This is crucial for determining the number of digits in the largest number, which dictates the number of sorting passes Radix Sort needs to make. 
```c
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

Radix Sort utilizes the counting sort algorithm to sort numbers based on individual digits. This is achieved through the countingSort function in [radix_sort.c](radix_sort.c), which organizes numbers by their digits at the given place value (exp).
```c
// A function to do counting sort of arr[] according to the digit represented by exp.
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[MAX] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < MAX; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
``` 
The main Radix Sort function in [radix_sort.c](radix_sort.c) systemically processes the array, sorting each digit starting from the least significant digit. This is done by repeteadly calling countingSort. 
```c
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}
```

### String Implementation Findings 
The getMaxStringLength function in [radix_sort_str.c] (radix_sort_str.c)calculates the maximum length of the strings in the array, which is necessary to determine the number of iterations needed in the radix sort process. 
```c
int getMaxStringLength(char *arr[], int n) {
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        int length = strlen(arr[i]);
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}
```
radixSort organizes the strings in the array by calling countingSort for each character position, starting from the least significant (rightmost) to the most significant (leftmost).
```c
void radixSort(char *arr[], int n) {
    int maxLength = getMaxStringLength(arr, n);

    for (int pos = 0; pos < maxLength; pos++) {
        countingSort(arr, n, pos);
    }
}
```

### Cross-Language Implementation 
The main logic of Radix Sort was initially implemented in C, and then adapted into Python to compare the performance and memory usage between a low level and high level language. This comparison helped me understand how different programming environments handle memory allocation, and time complexity for the same algorithm. The Python structure has a very similar logical structure.

## Application
Radix Sort's is well suited for sorting large sets of data, such as databases of phone numbers, where numbers are often similarly sized and can be sorted digit by digit efficiently. Another example is file systems where files are organized by certain numerical identifiers. Radix Sort is also used for digital processing. It can sort large sets of digital data to optimize the processing speed and efficiency.

Radix Sort versatility makes it adaptable to various data types, including integers and strings. Its performance is highly predictable based on the input size and digit count, providing reliability in system design. These aspects make Radix Sort a powerful tool in the computer science field, especially for tasks requiring quick and stable sorting of structured data.


## Summary
I learned Radix Sort is like sorting a deck of cards by each digit of the number on them, starting with the last digit. It is a good method to choose when we have lot of numbers, since it can sort them fast. It was very interesting to learn that a long time ago, Radix Sort was used with punch cards to count things like people for the U.S. Census or time logs. This old way of sorting stuff eventually led to the creation of a famous computer company called IBM.
In this report, I played around with Radix Sort using two different computer languages, C and Python, and also played around with using 2 separate data types (Integers and Strings). I found out that C can sort numbers quicker and use less space on your computer than Python, mostly because C is more strict with how it uses the computer's memory.

Radix Sort is handy because it's very predictable and can handle huge amounts of numbers without getting slower. That's why computer scientists like to use it when they have to sort things fast, like when you're searching for a number in a big phone book. 
This whole experiment shows us that Radix Sort is still a useful tool for sorting lots of numbers in a smart way.


## Conclusion
This investigation into Radix Sort has illuminated its strengths in sorting large sets of integers efficiently, with performance that scales linearly with the size of the input data. The empirical analysis confirmed the theoretical time and space complexities of Radix Sort, demonstrating its effectiveness in both C and Python environments.

The project highlighted how important it is to pick the correct algorithm for the job, especially with big datasets. Although Radix Sort is great for sorting numbers, it's important to think about the data type and what the task needs to choose the best sorting method.

Through this exploration, the practical aspects of algorithm implementation were highlighted, providing valuable insights into the nuances of algorithm efficiency and performance in different programming contexts.


## References
[1] Nilesh D. Year. First Sorting Algorithm & Founding of IBM. LinkedIn. [Accessed: 04/05/2024]. Available at: https://www.linkedin.com/pulse/first-sorting-algorithm-founding-ibm-nilesh-d/
[2] Princeton University. 2007. Radix Sort. [Lecture notes]. Available at: [chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://www.cs.princeton.edu/courses/archive/fall07/cos226/lectures/18RadixSort.pdf]
[3] Vaidehi Joshi. (2017). Getting to the Root of Sorting with Radix Sort. Medium. [Accessed: 04/05/2024] Available at: https://medium.com/basecs/getting-to-the-root-of-sorting-with-radix-sort-f8e9240d4224 
[4] Wikipedia contributors. n.d. Radix sort. In Wikipedia. Retrieved [Accessed: 04/05/2024], from https://en.wikipedia.org/wiki/Radix_sort
[5] Seyma Tas. (2020). Memory Management and Garbage Collection in Python. Towards Data Science. Available at: https://towardsdatascience.com/memory-management-and-garbage-collection-in-python-c1cb51d1612c 
[6] Python Software Foundation. Memory Management in Python. In Python Documentation. Available at: https://docs.python.org/3/c-api/memory.html
[7] GeeksforGeeks. (n.d.). C Program for Radix Sort. Available at: https://www.geeksforgeeks.org/c-program-for-radix-sort/
[8] GeeksforGeeks. (n.d.). Radix Sort. Available at: https://www.geeksforgeeks.org/radix-sort/
[9] GeeksforGeeks. (n.d.). Radix Sort vs Bucket Sort. Available at: https://www.geeksforgeeks.org/radix-sort-vs-bucket-sort/
[10] Simplilearn. (n.d.). Radix Sort: Pseudocode of Radix Sort Algorithm. Simplilearn. Available at: https://www.simplilearn.com/tutorials/data-structure-tutorial/radix-sort#pseudocode_of_radix_sort_algorithm
[11] Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. 2009. Introduction to Algorithms, Third Edition. MIT Press. Available at https://mitpress.mit.edu/9780262533058/introduction-to-algorithms/


## Execution Instructions 
### Python Implementation [radix_sort.py](radix_sort.py)
1. Open a Terminal/Command Prompt. Navigate to the folder where you saved radix_sort.py.
2. Execute the script. Run the following command in your terminal: 
``` bash
python3 radix_sort.py <max array size> [output file].
```
* Replace max array size with the max size of the array you want to sort. 
* [output file] is an optional argument. If you want to save the output to a specific file, replace [output file] with the name of your output file, like results.csv. If you don't specify an output file, the results will be saved to radix_sort_results.csv by default.

3. Example commands: 
* To sort arrays up to 100 elements and save the results to the default file: 
```bash 
python3 radix_sort.py 100
```
* To sort arrays up to 50 elements and save the results to output.csv:
```bash
python3 radix_sort.py 50 my_results.csv
```

## C implementation [radix_sort.c](radix_sort.c)
1. Open a Terminal/Command Prompt. Navigate to the folder where you saved radix_sort.c.
2. Compile the code. This will compile radix_sort.c and create an executable named "radix_sort" 
``` bash
gcc -o radix_sort radix_sort.c
```
3. Run the executable: Execute the compiled program using the following syntax:
``` bash
./radix_sort <max array size> [output file]
```
* max array size: Replace this with the maximum size of the array you want to sort. For example, 100 if you want to test array sizes up to 100.
* [output file]: This is an optional argument. Specify the name of the file where you want to save the output, like results.csv. If you don't specify an output file, the program will use radix_sort_results.csv as the default.

4. Example commands: 
* To sort arrays up to 100 elements and save the results to the default output file:
``` bash
./radix_sort 100
```
* To sort arrays up to 50 elements and save the results to my_results.csv:
``` bash
./radix_sort 50 my_results.csv
```
The program tests the radix sort algorithm on array sizes from 1 up to the specified max size. It records the time taken to sort each array and the memory used. The results are then saved to the specified csv file, containing columns for the array size, time taken in seconds, and memory used in bytes. This process allows you to evaluate the performance of the radix sort algorithm in terms of time efficiency and memory usage as the size of the input array increases. 

## Radix Sort for Strings visualization [radix_sort_str.c](radix_sort_str.c)
1. Open a Terminal/Command Prompt. Navigate to the folder where you saved radix_sort_str.c 
2. Compile the Code: Use a C compiler like gcc to compile the code. In the terminal, run:
``` bash
gcc -o radix_sort_strings radix_sort_strings.c
```

3. Run the Executable: Execute the compiled program by running:
``` bash
./radix_sort_strings
```
This will execute the Radix Sort algorithm on the predefined array of strings within the code.
Note: This program uses a predefined array of strings defined in the main function. If you want to sort different strings, you need to modify the array[] in the main function of the code. The program onlysorts strings based on their ASCII values, handling variable-length strings by sorting from the least significant character (rightmost) to the most significant character (leftmost). 
This code was only implemented to visualize string array sorting. I did not track runtimes or memory allocation for string datatypes. 

## Radix Sort for Integers, step by step visualization [radix_sort_int.c](radix_sort_int.c)
1. Open Terminal or command prompt
2. Compile the code: 
``` bash
gcc -o radix_sort radix_sort_int.c
``` 
3. Run the Executable. 
``` bash
./radix_sort <array size> [print array]
``` 
* Replace array size this with the number of elements you want to sort. For example, use 100 to sort an array of 100 elements.
* [print array]: This is an optional boolean flag (use 1 to enable and 0 to disable) that controls whether the array is printed before and after sorting. If not specified, the array will not be printed.

Example Usage: 
* To sort an array of 50 elements and print the array before and after sorting: (Include the 1 to print the original array)
``` bash
./radix_sort 50 1
``` 
The program is set up to initialize an array of the specidied size with random numbers between 0 - 999. If the print flag is set it will display the original unsorted array. It then sorts the array using the radix sort algorithm, if the print flag is set it will display the sorted array. The purpose of the pgram is to measure and print the time taken to sort the array sing radix sort. 

## Code Testing [test_runs.md](test_runs.md)
Tests included to show validity. Sample runs included in the file [test_runs.md](test_runs.md) 