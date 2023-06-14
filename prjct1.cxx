#include <stdio.h>

int main() {
    int reg;
    float edad, cantM, pesoM;
    float base, eqp, rec, desc, tot;

    printf("Ingrese la región de destino: ");
    scanf("%d", &reg);

    printf("Ingrese la edad del pasajero: ");
    scanf("%f", &edad);

    printf("Ingrese la cantidad de maletas: ");
    scanf("%f", &cantM);

    printf("Ingrese el peso total del equipaje (kg): ");
    scanf("%f", &pesoM);

    // Cálculo del precio base
    if (reg == 1) {
        base = 600000.00;
    } else if (reg == 2) {
        base = 450000.00;
    } else if (reg == 3) {
        base = 700000.00;
    } else {
        printf("Destino seleccionado no encontrado. Ingrese un destino comprendido entre 1 y 3.\n");
        return 0;
    }

    // Cálculo del precio por equipaje
    if (cantM >= 0 && cantM <= 1) {
        eqp = 0.00;
    } else if (cantM >= 2 && cantM <= 3) {
        eqp = 2500.00;
    } else {
        printf("Cantidad de maletas no permitida.\n");
        return 0;
    }

    // Cálculo del recargo por sobrepeso
    if (pesoM > 90) {
        rec = 2000.00;
    } else {
        rec = 0.00;
    }

    // Cálculo del descuento por edad
    if (edad <= 14 || edad >= 65) {
        desc = (base + eqp + rec) * 0.15;
    } else {
        desc = 0.00;
    }

    // Cálculo del total a pagar
    tot = base + eqp + rec - desc;

    // Impresión de los resultados
    printf("Precio base del boleto: %.2f\n", base);
    printf("Precio a pagar por el equipaje: %.2f\n", eqp);
    printf("Recargo por sobrepeso: %.2f\n", rec);
    printf("Descuento por edad: %.2f\n", desc);
    printf("Total a pagar por el viaje: %.2f\n", tot);

    return 0;
}
