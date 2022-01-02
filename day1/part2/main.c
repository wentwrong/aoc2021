#include <stdio.h>
#include <assert.h>

int main() {
    int prevprev = 0, prev = 0, cur = 0;
    int items = scanf("%d", &prevprev);
    assert(items == 1);

    items = scanf("%d", &prev);
    assert(items == 1);

    items = scanf("%d", &cur);
    assert(items == 1);

    int ans = 0,
        sum = prevprev + prev + cur;

    while(scanf("%d", &cur) == 1) {
        int prevsum = sum;
        int outdated_cur = prevsum - prevprev - prev;

        sum -= prevprev;
        sum += cur;

        if (sum - prevsum > 0)
            ans++;

        prevprev = prev;
        prev = outdated_cur;
        printf("%d %d %d %d\n", prevprev, prev, cur, sum);
    }

    printf("%d\n", ans);

    return 0;
}
