#include <stdio.h>
#define PI 3.14F

void areaEsfera(int r) {
    float area;

    area = (4*PI*(r*r));
    printf("area: %.2f m^2\n", area);
}

void volumeEsfera(int r) {
    float volume;

    volume = (4*PI*(r*r*r)) / 3;
    printf("volume: %.2f m^3\n", volume);
}

int main() {
    int r = 5;

    areaEsfera(r);
    volumeEsfera(r);

    return 0;
}