#include <stdio.h>
#include <math.h>

int main() {
    int x, n;
    long long sum;

    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Enter value of n: ");
    scanf("%d", &n);

    if (x == 1)
        sum = n + 1;
    else
        sum = (pow(x, n + 1) - 1) / (x - 1);

    printf("Sum of series = %lld\n", sum);
    return 0;
}
