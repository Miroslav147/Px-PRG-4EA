#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    int diskriminant;

    printf("Program zacal\n");

    printf("Napis koeficient a: ");
    if (scanf("%d", &a) != 1) {
        printf("Error: Neplatny koeficient a\n");
        exit(1);
    }

    printf("Napis koeficient b: ");
    if (scanf("%d", &b) != 1) {
        printf("Error: Neplatny koeficient b\n");
        exit(1);
    }

    printf("Napis koeficient c: ");
    if (scanf("%d", &c) != 1) {
        printf("Error: Neplatny koeficient c\n");
        exit(1);
    }

    printf("Koeficienty: a = %d, b = %d, c = %d\n", a, b, c);

    diskriminant = b * b - 4 * a * c;

    printf("Diskriminant: %d\n", diskriminant);

    if (diskriminant < -999 || diskriminant > 999) {
        printf("Error: Diskriminant mimo hranici\n");
        exit(1);
    }

    printf("+-------+-------+-------+-------+\n");
    printf("| %5d | %5d | %5d | %5d |\n", a, b, c, diskriminant);
    printf("+-------+-------+-------+-------+\n");

    if (diskriminant > 0) {
        printf("|                Two real roots |\n");
    } else if (diskriminant == 0) {
        printf("|                      One root |\n");
    } else {
        printf("|               Imaginary roots |\n");
    }

    printf("+-------------------------------+\n");

    return 0;
}