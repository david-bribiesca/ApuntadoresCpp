# Apuntadores o Punteros en C++: 
# Definiciones y Casos de Uso Esenciales

## 1. ¿Qué es un apuntador?
- Un **apuntador** es una variable cuyo valor es la **dirección de memoria** de otra variable.
- Sintaxis básica:
  ```cpp
  int x = 42;
  int* p = &x;    // p almacena la dirección de x
  ```
- Operadores:
  - `&` → obtiene la dirección de una variable.
  - `*` → desreferencia el apuntador, accediendo al valor apuntado.

---

## 2. Punteros y tipos de datos
Cada apuntador tiene un **tipo** que indica el tipo de dato al que apunta:
```cpp
double d = 3.14;
double* pd = &d;      // apuntador a double

char c = 'A';
char* pc = &c;        // apuntador a char
```
La desreferenciación (`*pd`) devolverá un `double`, y (`*pc`) un `char`.

---

## 3. Null Pointer (puntero nulo)
- Un puntero puede no apuntar a ningún objeto válido:
  ```cpp
  int* p = nullptr;   // desde C++11
  ```
- Antes de usar `*p`, siempre verifica `p != nullptr` para evitar **accesos inválidos**.

---

## 4. Aritmética de apuntadores
Permite recorrer bloques contiguos (como arrays):
```cpp
int arr[3] = {1,2,3};
int* p = arr;        // equivale a &arr[0]

for (int i = 0; i < 3; ++i) {
    std::cout << *(p + i) << "\n";  // apunta a arr[i]
}
```

---

## 5. Casos de uso fundamentales

### 5.1. Paso por referencia “manual”
```cpp
void incrementar(int* p) {
    if (p) *p += 1;
}
int n = 5;
incrementar(&n);   // n ahora vale 6
```
Equivalente al paso por referencia con `int&`.

### 5.2. Arreglos y memoria dinámica
```cpp
int* arreglo = new int[10];   // reserva 10 enteros
// … usar arreglo[i] o *(arreglo + i)
delete[] arreglo;             // liberar memoria
```

### 5.3. Punteros a función
```cpp
int sumar(int a, int b) { return a + b; }
int (*op)(int,int) = &sumar;
std::cout << op(2,3);  // imprime 5
```

### 5.4. Punteros a miembros de clase
```cpp
struct Punto {
    int x, y;
    void mover(int dx, int dy) { x += dx; y += dy; }
};

void (Punto::*pm)(int,int) = &Punto::mover;
Punto p{0,0};
(p.*pm)(5, 7);   // ahora p.x=5, p.y=7
```

### 5.5. Polimorfismo y herencia
```cpp
struct Base { virtual void f() { std::cout<<"Base\n"; } };
struct Der  : Base { void f() override { std::cout<<"Der\n"; } };

Base* b = new Der();
b->f();    // invoca Der::f() gracias a virtual
delete b;
```

---

## 6. Smart Pointers (C++11 en adelante)
Para gestionar memoria de forma segura:
- `std::unique_ptr<T>` → propietario único
- `std::shared_ptr<T>` → propietario compartido
- `std::weak_ptr<T>`   → referencia no propietaria

**Ejemplo**:
```cpp
#include <memory>
std::unique_ptr<int> up(new int(10));
*up = 20;  // se libera al salir de alcance
```

---

## Resumen de lo esencial
1. **Declaración y desreferencia**: `T* p = &x; *p = …;`
2. **Null checks**: evita desreferenciar `nullptr`.
3. **Pointer arithmetic** para arrays y buffers.
4. **new/delete** (mejor usar smart pointers).
5. **Punteros a función** para callbacks.
6. **Polimorfismo** mediante punteros a base.
7. **Smart pointers** para RAII y seguridad.


## Proyecto de Ejemplo de uso de apuntadores
¿Cómo usar en tu proyecto?
1. **Copia los archivos:**
    - include/PointerExamples.h
    - src/PointerExamples.cpp y src/main.cpp
    - tests/test_PointerExamples.cpp

2. **Verifica tus task.json**
Asegúrate de que tu Makefile o tasks.json compile todos los .cpp y enlace correctamente
3. **Ejecuta**
Verás en consola la salida de cada demo.
