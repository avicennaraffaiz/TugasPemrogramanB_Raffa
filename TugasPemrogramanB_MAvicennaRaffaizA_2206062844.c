#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 0.0001
#define MAX_ITER 100

double f(double x) {
    return x * x * x + 4 * x * x - 10;
}

double df(double x) {
    return 3 * x * x + 8 * x;
}

int main() {
    double x0 = 1.5, x1, fx, dfx, ea;
    int iter = 0;

    printf("Iter\tx_i\t\tf(x_i)\t\tf'(x_i)\t\tx_next\t\tea(%%)\n");

    do {
        fx = f(x0);
        dfx = df(x0);
        if (dfx == 0) {
            printf("Turunan nol. Tidak bisa lanjut.\n");
            exit(1);
        }

        x1 = x0 - fx / dfx;
        ea = fabs((x1 - x0) / x1) * 100;

        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", iter + 1, x0, fx, dfx, x1, ea);

        x0 = x1;
        iter++;
    } while (ea > EPS && iter < MAX_ITER);

    printf("\nAkar mendekati: %.6f\n", x1);
    return 0;
}
