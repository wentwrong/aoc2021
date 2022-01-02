#include <stdio.h>
#include <assert.h>

int main() {
    int prev = 0;
    int items = scanf("%d", &prev);
    assert(items == 1);

    int ans = 0, cur = 0;

    while(scanf("%d", &cur) == 1) {
        if (cur - prev > 0)
            ans++;
        prev = cur;
    }

    printf("%d\n", ans);

    return 0;
}
