/**
 * @file PointerExamples.cpp
 * @brief Implementación de los demos de apuntadores.
 * @date 2025-05-25
 * @author Camilo Duque
 * @details Este archivo contiene la implementación de la clase PointerExamples
 * que agrupa varios demos relacionados con el uso de apuntadores en C++. Cada
 * demo ilustra un concepto diferente relacionado con apuntadores, incluyendo
 * apuntadores básicos, punteros nulos, aritmética de apuntadores, punteros a
 * funciones, punteros a miembros de clase y polimorfismo con apuntadores.
 * @details Se utilizan ejemplos simples y claros para ilustrar cada concepto, y
 * se incluyen comentarios explicativos para facilitar la comprensión. Además,
 * se utilizan aserciones para verificar el correcto funcionamiento de los
 * demos.
 */

#include "PointerExamples.h"

#include <cassert>
#include <iostream>

// Demo 1: Apuntador básico
void PointerExamples::demoBasicPointer() {
    std::cout << "\n--- Demo 1: Apuntador básico ---\n";
    int x = 10;
    int* p = &x;
    std::cout << "Valor de x: " << x << "\n";
    std::cout << "Dirección de x (&x): " << &x << "\n";
    std::cout << "Valor de p (debe ser &x): " << p << "\n";
    std::cout << "Desreferencia *p: " << *p << "\n";
}

// Demo 2: Puntero nulo
void PointerExamples::demoNullPointer() {
    std::cout << "\n--- Demo 2: Puntero nulo ---\n";
    int* p = nullptr;
    if (p) {
        std::cout << "*p = " << *p << "\n";
    } else {
        std::cout << "p es nullptr, no se puede desreferenciar.\n";
    }
}

// Demo 3: Aritmética de apuntadores
void PointerExamples::demoPointerArithmetic() {
    std::cout << "\n--- Demo 3: Aritmética de apuntadores ---\n";
    int arr[5] = {5, 10, 15, 20, 25};
    int* p = arr;  // &arr[0]
    for (int i = 0; i < 5; ++i) {
        std::cout << "arr[" << i << "] = " << *(p + i) << "\n";
    }
}

// Función auxiliar para Demo 4
static int suma(int a, int b) { return a + b; }

// Demo 4: Puntero a función
void PointerExamples::demoFunctionPointer() {
    std::cout << "\n--- Demo 4: Puntero a función ---\n";
    int (*op)(int, int) = &suma;
    int resultado = op(3, 4);
    std::cout << "resultado = suma(3,4) vía puntero: " << resultado << "\n";
    assert(resultado == 7);
}

// Clase auxiliar para Demo 5
class DemoClass {
   public:
    void greet(const char* name) {
        std::cout << "Hola, " << name << " desde DemoClass!\n";
    }
};

// Demo 5: Puntero a miembro de clase
void PointerExamples::demoMemberPointer() {
    std::cout << "\n--- Demo 5: Puntero a miembro de clase ---\n";
    DemoClass obj;
    void (DemoClass::*pm)(const char*) = &DemoClass::greet;
    (obj.*pm)("C++ Developer");
}

// Clases para Demo 6
struct Base {
    virtual void whoAmI() { std::cout << "Soy Base\n"; }
    virtual ~Base() = default;
};

struct Derived : Base {
    void whoAmI() override { std::cout << "Soy Derived\n"; }
};

// Demo 6: Polimorfismo con apuntadores
void PointerExamples::demoPolymorphism() {
    std::cout << "\n--- Demo 6: Polimorfismo con apuntadores ---\n";
    Base* b = new Derived();
    b->whoAmI();  // debe invocar Derived::whoAmI()
    delete b;
}
