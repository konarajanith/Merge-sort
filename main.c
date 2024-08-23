#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays
void merge(long theArray[], long workSpace[], int lowPtr, int highPtr, int upperBound) {
    int j = 0; // workspace index
    int lowerBound = lowPtr;
    int mid = highPtr - 1;
    int n = upperBound - lowerBound + 1; // total elements to merge

    while (lowPtr <= mid && highPtr <= upperBound) {
        if (theArray[lowPtr] < theArray[highPtr]) {
            workSpace[j++] = theArray[lowPtr++];
        } else {
            workSpace[j++] = theArray[highPtr++];
        }
    }

    // Copy the rest of the first half
    while (lowPtr <= mid) 
        workSpace[j++] = theArray[lowPtr++];
    
    // Copy the rest of the second half
    while (highPtr <= upperBound) 
        workSpace[j++] = theArray[highPtr++];
    
    // Copy the sorted array into original array
    for (j = 0; j < n; j++) 
        theArray[lowerBound + j] = workSpace[j];
}

// Recursive function to implement Merge Sort
void mergeSort(long theArray[], long workSpace[], int lowerBound, int upperBound) {
    if (lowerBound < upperBound) {
        int mid = (lowerBound + upperBound) / 2;

        // Sort first half
        mergeSort(theArray, workSpace, lowerBound, mid);
        
        // Sort second half
        mergeSort(theArray, workSpace, mid + 1, upperBound);
        
        // Merge the two halves
        merge(theArray, workSpace, lowerBound, mid + 1, upperBound);
    }
}

// Utility function to print the array
void printArray(long theArray[], int size) {
	int i=0;
    for ( i = 0; i < size; i++) {
        printf("%ld ", theArray[i]);
    }
    printf("\n");
}

// Driver code to test the Merge Sort implementation
int main() {
    long theArray[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(theArray) / sizeof(theArray[0]);
    long* workSpace = (long*)malloc(n * sizeof(long)); // Auxiliary workspace array

    printf("Original array:\n");
    printArray(theArray, n);

    mergeSort(theArray, workSpace, 0, n - 1);

    printf("Sorted array:\n");
    printArray(theArray, n);

    free(workSpace); // Free the allocated memory
    return 0;
}

