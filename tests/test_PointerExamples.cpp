/**
 * @file test_PointerExamples.cpp
 * @brief Test de humo para asegurar que los demos compilan y corren.
 * @date 2025-05-25
 * @author Camilo Duque
 * @details Este archivo contiene un test de humo que invoca todos los demos de
 * la clase PointerExamples. El objetivo es asegurar que todos los demos
 * compilan y corren sin errores. No se realizan pruebas exhaustivas de los
 * resultados, solo se verifica que no haya errores de compilación o ejecución.
 */

#include "../include/PointerExamples.h"

int main() {
    // Simple smoke test: invocar todas las demos
    PointerExamples::demoBasicPointer();
    PointerExamples::demoNullPointer();
    PointerExamples::demoPointerArithmetic();
    PointerExamples::demoFunctionPointer();
    PointerExamples::demoMemberPointer();
    PointerExamples::demoPolymorphism();
    return 0;
}
