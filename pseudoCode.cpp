#include <iostream>

class Persona {
protected:  // 🔹 `protected` permite acceso en clases hijas
    int edad;

public:
    Persona(int _edad) : edad(_edad) {}
};

class EstudianteProtegido : protected Persona {
public:
    EstudianteProtegido(int _edad) : Persona(_edad) {}

    void mostrarEdad() {
        std::cout << "Edad en EstudianteProtegido: " << edad << std::endl;
    }
};

class EstudianteSuperProtegido : protected EstudianteProtegido {
public:
    EstudianteSuperProtegido(int _edad) : EstudianteProtegido(_edad) {}

    void mostrarEdadSuper() {
        std::cout << "Edad en EstudianteSuperProtegido: " << edad << std::endl;  // ✅ Se puede acceder a `edad`
    }
};

int main() {
    EstudianteSuperProtegido estudiante(25);
    EstudianteProtegido estudiante1(25);

    estudiante.mostrarEdadSuper();  // ✅ Funciona porque `mostrarEdadSuper()` está dentro de la clase hija

    // estudiante.edad; ❌ ERROR: `edad` sigue siendo `protected` y no es accesible desde `main()`

    return 0;
}