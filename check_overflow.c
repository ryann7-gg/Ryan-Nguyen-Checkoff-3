#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // Simulate a 32-bit unsigned integer limit.
    // Using uint32_t makes the overflow behavior predictable.
    uint32_t capacity = 100;
    uint32_t offset = UINT32_MAX - 49;
    uint32_t length = 100;

    char buffer[100];
    char data[100];

    memset(buffer, 'A', sizeof(buffer));
    memset(data, 'B', sizeof(data));

    printf("Buffer capacity: %u\n", capacity);
    printf("Offset: %u\n", offset);
    printf("Length: %u\n\n", length);

    // -----------------------------------
    // ORIGINAL: VULNERABLE BOUNDS CHECK
    // -----------------------------------

    printf("--- Original version ---\n");

    // This looks like if (50 <= 100), which passes
    if (offset + length <= capacity) {
        printf("Check passed! Copying data...\n");

        // In a real vulnerable program, this could
        // write outside the buffer and corrupt memory.
        // We deliberately do NOT perform the copy here.
    } else {
        printf("Check failed. Copy rejected.\n");
    }

    // -----------------------------------
    // FIXED: SAFE BOUNDS CHECK
    // -----------------------------------

    printf("\n--- Fixed version ---\n");

    if (offset <= capacity && length <= capacity - offset) {
        printf("Check passed! Copy would be safe.\n");

        // The copy is safe only if the actual buffer
        // and source data are at least the checked sizes.
    } else {
        printf("Check failed. Copy rejected.\n");
    }

    return 0;
}
