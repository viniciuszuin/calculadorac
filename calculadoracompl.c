#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complex;

Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    if (denominator == 0) {
        printf("Erro: Divisão por zero\n");
        exit(EXIT_FAILURE);
    }
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

void printComplex(Complex c) {
    if (c.imag < 0) {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    } else {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    }
}

int main() {
    Complex num1, num2, result;
    char operator;

    printf("Digite o primeiro número complexo (formato: real imag): ");
    scanf("%lf %lf", &num1.real, &num1.imag);

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Digite o segundo número complexo (formato: real imag): ");
    scanf("%lf %lf", &num2.real, &num2.imag);

    switch (operator) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Operador inválido\n");
            return EXIT_FAILURE;
    }

    printf("Resultado: ");
    printComplex(result);

    return 0;
}
