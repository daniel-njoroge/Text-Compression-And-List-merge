#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
int* mergeSortedLists(int* list1, int size1, int* list2, int size2, int* mergedSize) {
    int* mergedList = (int*)malloc((size1 + size2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (list1[i] <= list2[j]) {
            mergedList[k++] = list1[i++];
        } else {
            mergedList[k++] = list2[j++];
        }
    }

    while (i < size1) {
        mergedList[k++] = list1[i++];
    }

    while (j < size2) {
        mergedList[k++] = list2[j++];
    }

    *mergedSize = k;
    return mergedList;
}

// Main function to test the merge function
int main() {
    int list1[] = {1, 3, 5, 7};
    int list2[] = {2, 4, 6, 8};
    int size1 = sizeof(list1) / sizeof(list1[0]);
    int size2 = sizeof(list2) / sizeof(list2[0]);
    int mergedSize;

    
    int* mergedList = mergeSortedLists(list1, size1, list2, size2, &mergedSize);

    
    printf("Merged List: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedList[i]);
    }
    printf("\n");

    
    free(mergedList);

    return 0;
}


//Merging the two sorted lists of size 𝑛 and 𝑚 T(n,m)=T(n−1,m)+O(1) 
//Time complexity = T(n,m)=O(n+m)
//Space complexity O(n+m)