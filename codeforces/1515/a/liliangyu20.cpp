#include <cstdio>
#include <algorithm>

using namespace std;

int num[200];

int main() {
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- > 0) {
        int n, explode, sum = 0;
        scanf("%d%d", &n, &explode);
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
            sum += num[i];
        }

        if (sum == explode) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        sort(num, num + n);

        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (sum > explode) printf("%d ", num[i]);
            else {
                if (num[i] + sum == explode) {
                    swap(num[i - 1], num[i]);
                    i++;
                    continue;
                }
                printf("%d ", num[i]);
                sum += num[i];
            }
        }

        printf("\n");
    }

    return 0;
}