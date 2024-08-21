#include <stdio.h>
#include <stdbool.h>

int main() {
    int target;
    int array[100]; // Fixed array size

    printf("Enter target value between the range of 0 - 100: ");
    scanf("%i", &target);

    if (target < 0 || target > 100) {
        printf("Target out of bounds!\n");
        return 1; // Indicate an error
    }

    // Create a sorted array (0 to 99)
    for (int i = 0; i < 100; i++) {
        array[i] = i;
    }

    // Binary search logic within the main function
    int left = 0, right = 99;
    int index = -1; // Initialize index to -1 (not found)

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            index = mid; // Target found
            break; // Exit the loop
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (index != -1) {
        printf("Target found at index %d\n", index);
    } else {
        printf("Target not found.\n");
    }

    return 0; // Indicate successful execution
}
