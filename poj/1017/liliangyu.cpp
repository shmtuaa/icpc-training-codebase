#include <cstdio>

using namespace std;

int ans = 0;

int main() {
    int one, two, three, four, five, six;
    scanf("%d%d%d%d%d%d", &one, &two, &three, &four, &five, &six);

    while (one != 0 || two != 0 || three != 0 || four != 0 || five != 0 || six != 0) {
        ans = 0;

        ans += six;
        six = 0;

        for (int i = 0; i < five; i++) {
            ans++;
            one -= 11;
        }

        for (int i = 0; i < four; i++) {
            ans++;
            if (two >= 5) two -= 5;
            else {
                one -= (5 - two) * 4;
                two = 0;
            }
        }

        ans += three / 4;
        three %= 4;
        switch (three) {
            case 3: {
                ans++;
                if (two > 0) {
                    two -= 1;
                    one -= 5;
                } else {
                    one -= 9;
                }
                break;
            }
            case 2: {
                ans++;
                if (two >= 3) {
                    two -= 3;
                    one -= 6;
                } else if (two == 2) {
                    two -= 2;
                    one -= 10;
                } else if (two == 1) {
                    two -= 1;
                    one -= 14;
                } else one -= 18;
                break;
            }
            case 1: {
                ans++;
                if (two >= 5) {
                    two -= 5;
                    one -= 7;
                } else {
                    one -= (7 + (5 - two) * 4);
                    two = 0;
                }
                break;
            }
            default: {
                break;
            }

        }

        if (two < 0) two = 0;
        ans += two / 9;
        two %= 9;
        if (two > 0) {
            ans++;
            one -= (9 - two) * 4;
            two = 0;
        }

        if (one < 0) one = 0;
        ans += one / 36;
        one %= 36;
        if (one > 0) ans++;

        printf("%d\n", ans);
        scanf("%d%d%d%d%d%d", &one, &two, &three, &four, &five, &six);
    }

    return 0;
}