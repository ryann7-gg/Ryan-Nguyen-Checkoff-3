#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t n;

    printf("Enter array size: ");
    scanf("%zu", &n);

    int* arr = malloc(n * sizeof(int));

    for (size_t i = 0; i < n; i++) {
        arr[i] = (int)i;
    }

    free(arr);

    return 0;
}