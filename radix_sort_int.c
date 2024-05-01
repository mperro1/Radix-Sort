/*
File implementing radix sort algorithm using C 
This implementation shows Radix Sorting an array of random integers 
Name: Marcela Perro 
Semester: Spring 2024 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 10  // Assuming we are dealing with decimal numbers

// Global variable to track memory usage
size_t allocated_memory = 0;

// Function prototype for print_array
void print_array(int arr[], int n);

// Custom memory allocation function
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
        free(ptr);
    }
}

// A utility function to get the maximum value in arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

// A function to do counting sort of arr[] according to the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    int output[n]; //Temp array to hold sorted elements 
    int i, count[MAX] = {0}; // Count array to store the count of each digit

    //storing count of occurrences of digits in count []
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // changing count index to contain the actual position of this digit in output []
    for (i = 1; i < MAX; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array 
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    //printing after sorting the current digit 
    printf("After sorting on digit %d place:\n", exp);
    print_array(arr, n);
}

// The main function that sorts arr[] of size n using Radix Sort
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// A utility function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double time_function(void (*func)(int[], int), int arr[], int n) {
    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);

    func(arr, n); //execute the sorting function 

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    return time_spent;
}

void help() {
    printf("Usage: ./radix_sort.out <array size> [print array]\n");
    printf("\t<array size> is the number of elements in the array to be sorted, required.\n");
    printf("\t[print array] is an optional argument: specify '1' to print the array before and after sorting, any other value or leaving this blank will not print the array.\n");
    printf("\nExample:\n");
    printf("\t./radix_sort.out 100 1\n");
    printf("\tThis will sort an array of 100 elements and print the array before and after sorting.\n");
}

int main(int argc, char *argv[]) {
    //Checking if at least one command argument is provided 
    if (argc < 2) {
        // If not, print the usage instructions and exit 
        printf("Usage: %s <array size> [print array]\n", argv[0]);
        return 1; 
    }

    //Convert the first arg to an int to determine the size of the array 
    int n = atoi(argv[1]);
    //Check if a second arg is provided 
    bool print = false;
    if (argc > 2) {
        //Sets print flag 
        print = atoi(argv[2]) > 0;
    }

    //Allocates memory for the array 
    int *arr = (int *)malloc_track(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //Initializing the randon number generator
    srand(time(NULL));
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        if (print) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    double elapsed = time_function(radixSort, arr, n);
    printf("Time taken for Radix Sort: %.6f seconds\n", elapsed);

    // The array should be freed here to prevent memory leaks
    free(arr);

    // End of main function
    return 0;  // Returns 0 to indicate successful execution
}

