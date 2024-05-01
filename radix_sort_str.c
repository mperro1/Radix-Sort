/*
File implementing radix sort algorithm using C 
This implementation shows Radix Sorting an array of strings 
Name: Marcela Perro 
Semester: Spring 2024 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 256  // Maximum number of characters in ASCII

// Function to find the length of the longest string
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

// Function to perform counting sort on the array based on the character at position 'pos'
void countingSort(char *arr[], int n, int pos) {
    char *output[n];
    int i, count[MAX_CHARS] = {0};

    // Count each character at the given position
    for (i = 0; i < n; i++) {
        int charIndex;
        if ((int)strlen(arr[i]) > pos) {
            charIndex = (unsigned char)arr[i][strlen(arr[i]) - pos - 1];
        } else {
            charIndex = 0;  // Consider null character for strings shorter than pos
        }
        count[charIndex]++;
    }

    // Accumulate the count
    for (i = 1; i < MAX_CHARS; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        int charIndex;
        if ((int)strlen(arr[i]) > pos) {
            charIndex = (unsigned char)arr[i][strlen(arr[i]) - pos - 1];
        } else {
            charIndex = 0;
        }
        output[count[charIndex] - 1] = arr[i];
        count[charIndex]--;
    }

    // Copy the sorted strings back to the original array
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function that sorts the array of strings using Radix Sort
void radixSort(char *arr[], int n) {
    int maxLength = getMaxStringLength(arr, n);

    // Perform counting sort for each character position
    for (int pos = 0; pos < maxLength; pos++) {
        countingSort(arr, n, pos);
    }
}

// A utility function to print an array of strings
void printArray(char *arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
}

int main() {
    char *arr[] = {"word", "category", "apple", "quest", "balloon", "race", "dog"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}
