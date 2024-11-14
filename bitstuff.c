#include <stdio.h>
#include <string.h>

#define MAX 100

void bit_stuffing(char *input, char *stuffed) {
    int count = 0;
    int j = 0;
    int i;  // Declare variable here

    // Traverse through each bit in input
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        
        // Add the bit to stuffed array
        stuffed[j++] = input[i];

        // If there are 5 consecutive 1's, stuff a 0
        if (count == 5) {
            stuffed[j++] = '0';
            count = 0;
        }
    }

    stuffed[j] = '\0';  // Null terminate the string
}

int main() {
    char input[MAX], stuffed[MAX * 2];  // Define input and stuffed arrays

    printf("Enter the input bit string: ");
    scanf("%s", input);

    bit_stuffing(input, stuffed);

    printf("Bit-stuffed output: %s\n", stuffed);

    return 0;
}
