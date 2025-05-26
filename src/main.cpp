/**
 * @file main.cpp
 * @brief Punto de entrada para ejecutar los demos de apuntadores.
 * @date 2025-05-25
 * @author Camilo Duque
 * @details Este archivo contiene la función main que ejecuta los demos de
 * apuntadores.
 * @details Los demos incluyen ejemplos de apuntadores básicos, punteros nulos,
 * aritmética de apuntadores, punteros a funciones, punteros a miembros de clase
 * y polimorfismo con apuntadores.
 * @details Cada demo se encuentra en la clase PointerExamples y se ejecuta de
 * forma secuencial.
 * @details Se utiliza la biblioteca estándar de C++ para la entrada/salida y
 * aserciones.
 */

#include "PointerExamples.h"

int main() {
    PointerExamples::demoBasicPointer();
    PointerExamples::demoNullPointer();
    PointerExamples::demoPointerArithmetic();
    PointerExamples::demoFunctionPointer();
    PointerExamples::demoMemberPointer();
    PointerExamples::demoPolymorphism();
    return 0;
}
