
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    size_t n;

    printf("Enter array size: ");
    scanf("%zu", &n);

    // Check for integer overflow before multiplication
    if (n > SIZE_MAX / sizeof(int)) {
        printf("Array size is too large!\n");
        return 1;
    }

    // Allocate memory
    int *arr = malloc(n * sizeof(int));

    // Check if allocation succeeded
    if (arr == NULL && n != 0) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the array
    for (size_t i = 0; i < n; i++) {
        arr[i] = (int)i;
    }

    printf("Successfully allocated and initialized %zu integers!\n", n);

    free(arr);

    return 0;
}
