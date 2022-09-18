#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_INP_LENGTH 1024

char bits[MAX_INP_LENGTH] = {0};

int main() {
    size_t* one_bits = NULL, bits_count = 0;
    size_t lines_count = 1;

    fgets(bits, MAX_INP_LENGTH, stdin);
    size_t input_length = strlen(bits);
    assert(input_length > 0);

    bits_count = strcspn(bits, "\n");
    assert(bits_count != input_length);

    one_bits = (size_t*)malloc(bits_count * sizeof(size_t));

    for(size_t i = 0; i < bits_count; i++) {
        one_bits[i] = 0;
    }

    for (size_t i = 0; i < bits_count; i++) {
        one_bits[i] += bits[i] - '0';
    }

    while(fgets(bits, MAX_INP_LENGTH, stdin) != NULL) {
        lines_count++;
        for (size_t i = 0; i < bits_count; i++) {
            one_bits[i] += bits[i] - '0';
        }
    }

    size_t gamma = 0, epsilon = 0;

    for (size_t i = 0; i < bits_count; i++) {
        int most_common_bit = one_bits[i] > (size_t)(lines_count / 2) ? 1 : 0;
        int least_common_bit = one_bits[i] > (size_t)(lines_count / 2) ? 0 : 1;

        if (most_common_bit) {
            size_t two_powers = 1;
            for (size_t j = bits_count - i - 1; j > 0; j--)
                two_powers *= 2;
            gamma += two_powers;
        }

        if (least_common_bit) {
            size_t two_powers = 1;
            for (size_t j = bits_count - i - 1; j > 0; j--)
                two_powers *= 2;
            epsilon += two_powers;
        }
    }

    free(one_bits);

    printf("\nGamma: %lu, epsilon: %lu. Answer: %lu\n", gamma, epsilon, gamma * epsilon);

    return 0;
}
