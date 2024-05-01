/*
File implementing radix sort algorithm using C 
Name: Marcela Perro 
Semester: Spring 2024 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


#define MAX 10  // Assuming we are dealing with decimal numbers

// Global variable to track memory usage
size_t allocated_memory = 0;

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
        //allocated_memory -= size;
        free(ptr);
    }
}

// A utility function to get the maximum value in arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

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

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// A utility function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

double time_function(void (*func)(int[], int), int arr[], int n) {
    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);

    func(arr, n); // Call the sorting function

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    return time_spent;
}


//Main function to output runtimes to csv. 
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <max array size> [output file]\n", argv[0]);
        return 1;
    }

    int max_n = atoi(argv[1]);
    const char* output_file = argc > 2 ? argv[2] : "radix_sort_results.csv";

    FILE *file = fopen(output_file, "w");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    // Write CSV header
    fprintf(file, "Array Size,Time Taken (seconds),Memory Used (bytes)\n");

    for (int n = 1; n <= max_n; n++) {
        allocated_memory = 0; // Reset memory tracker for each iteration

        int *arr = (int *)malloc_track(n * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed\n");
            fclose(file);
            return 1;
        }

        // Fill the array with random numbers
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;  // Random numbers from 0 to 999
        }

        double elapsed = time_function(radixSort, arr, n);
        //printf("Array Size: %d, Time Taken: %.6f seconds\n", n, elapsed);
        printf("Array Size: %d, Time Taken: %.6f seconds, Memory Used: %zu bytes\n", n, elapsed, allocated_memory);

        // Write to CSV
        fprintf(file, "%d,%.6f,%zu\n", n, elapsed, allocated_memory);

        free(arr);
    }

    fclose(file);
    return 0;
}
