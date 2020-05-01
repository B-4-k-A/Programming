#include <stdio.h>
#include <math.h>

int main(){
    enum Style{
        classic = 1,
        pop,
        rok,
        rap,
        new_age,
        electronic
    };
    struct Obj{ // Object
        float x0, y0, x1, y1;
        float side_value;
        float P;
        float S;
    };
    struct Status{ // Printer status
        unsigned Status_break: 1;
        unsigned Status_ready: 1;
        unsigned Status_toner: 1;
        unsigned Status_paper: 1;
    };
    union State{
        struct Status bitcode;
        int printer;

    };
    printf("------Task - 1------");
    printf("Music style is: \n %d - rok", rok);
    printf("\n\n------Task - 2------");
    printf("\nYour object is square.\n");
    printf("Enter two pairs coordinate of square:\n");
    struct Obj Sq; // Square
    printf("x0 =");
    scanf("%f", &Sq.x0);
    printf("y0 =");
    scanf("%f", &Sq.y0);
    printf("x1 =");
    scanf("%f", &Sq.x1);
    printf("y1 =");
    scanf("%f", &Sq.y1);
    if((Sq.x0 == Sq.x1 || Sq.y0 == Sq.y1) || (Sq.x1 - Sq.x0 != Sq.y1 - Sq.y0)) {
        printf("Error coordinate of square!");
    }
    else {
        Sq.side_value = fabsf(Sq.x1 - Sq.x0);
        Sq.P = 4 * Sq.side_value;
        Sq.S = pow(Sq.side_value, 2);
        printf("Perimetr of square: %.2f\n", Sq.P);
        printf("Area of square: %.2f\n", Sq.S);
    }
    printf("\n\n------Task - 3------");
    printf("Status of printer:\n");
    union State Check;
    printf("Enter code: ");
    scanf("%X", &Check.printer);
    printf("Printer status:\n");
    printf("Printer broke: %d\n", Check.bitcode.Status_break);
    printf("Ready to print: %d\n", Check.bitcode.Status_ready);
    printf("Out of toner: %d\n", Check.bitcode.Status_toner);
    printf("Out of paper: %d\n", Check.bitcode.Status_paper);
}