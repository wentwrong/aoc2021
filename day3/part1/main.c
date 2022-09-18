#include <stdio.h>

#define N 13

char bits[N] = {0};
int one_bits[N] = {0};
int powers_of_two[N - 1] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

int main() {
    while(scanf("%12s", bits) != EOF) {
        for (size_t i = 0; i < N - 1; i++) {
            one_bits[i] += bits[i] - '0';
        }
    }

    int gamma = 0, epsilon = 0;

    for (int i = 0; i < N - 1; i++) {
        int most_common_bit = one_bits[i] > 500 ? 1 : 0;
        int least_common_bit = one_bits[i] > 500 ? 0 : 1;

        gamma += powers_of_two[i] * most_common_bit;
        epsilon += powers_of_two[i] * least_common_bit;
    }

    printf("\nGamma: %d, epsilon: %d. Answer: %d\n", gamma, epsilon, gamma * epsilon);

    return 0;
}
