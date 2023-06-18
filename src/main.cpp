#include <iostream>
#include <iomanip>
#include <cmath>

double funcion(double x) {
    return pow(x, 3) - 2*x - 5;
}

void metodoSecante(double x0, double x1, double tolerancia, int iterMax) {
    double x2, f0, f1, f2;
    int iter = 0;
    
    // Encabezado de la tabla
    std::cout << "Iteracion" << std::setw(12) << "x0" << std::setw(12) << "x1" << std::setw(12) << "f(x0)" << std::setw(12) << "f(x1)" << std::setw(12) << "x2" << std::setw(15) << "f(x2)" << std::endl;
    
    do {
        f0 = funcion(x0);
        f1 = funcion(x1);
        
        if (fabs(f0 - f1) < tolerancia) {
            std::cout << "La diferencia entre las aproximaciones sucesivas es menor que la tolerancia especificada." << std::endl;
            break;
        }
        
        x2 = x1 - (f1*(x1 - x0))/(f1 - f0);
        f2 = funcion(x2);
        
        // Imprimir fila de la tabla
        std::cout << std::setw(6) << iter << std::setw(12) << x0 << std::setw(12) << x1 << std::setw(12) << f0 << std::setw(12) << f1 << std::setw(12) << x2 << std::setw(15) << f2 << std::endl;
        
        x0 = x1;
        x1 = x2;
        
        iter++;
    } while (iter < iterMax);
    
    if (iter == iterMax) {
        std::cout << "El metodo de las secantes no converge despues de " << iterMax << " iteraciones." << std::endl;
    } else {
        std::cout << "La raiz aproximada es: " << x2 << std::endl;
    }
}

int main() {
    double x0, x1, tolerancia;
    int iterMax;
    
    std::cout << "Ingrese el valor inicial x0: ";
    std::cin >> x0;
    
    std::cout << "Ingrese el valor inicial x1: ";
    std::cin >> x1;
    
    std::cout << "Ingrese la tolerancia: ";
    std::cin >> tolerancia;
    
    std::cout << "Ingrese el numero maximo de iteraciones: ";
    std::cin >> iterMax;
    
    metodoSecante(x0, x1, tolerancia, iterMax);
    
    return 0;
}