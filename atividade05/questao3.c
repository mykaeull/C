#include <stdio.h>

void ponto_simetrico(double xa, double ya, double a, double b, double c, double *xb, double *yb) {
    double mr, ms, as, bs, cs, xm, ym, xbv, ybv;

    mr = -a / b;
    ms = b / a;
    as = -ms;
    bs = 1;
    cs = (ms * xa) - ya;

    ym = ((as*c) - (a*cs)) / ((a*bs) - (as*b));
    xm = (-c - (b*ym)) / a;

    xbv = (2*xm) - xa;
    ybv = (2*ym) - ya;

    *xb = xbv;
    *yb = ybv;

}

int main() {
    double xa, ya, a, b, c;
    double xb;
    double yb;

    printf("coordenada xa: ");
    scanf("%lf", &xa);
    printf("coordenada ya: ");
    scanf("%lf", &ya);
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    ponto_simetrico(xa, ya, a, b, c, &xb, &yb);

    printf("xb: %lf\n", xb);
    printf("yb: %lf\n", yb);

    return 0;
}