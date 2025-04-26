
// Algoritmos.h
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <string>

class Algoritmos {
public:
    // Algoritmos de búsqueda recursivos
    static int busquedaBinaria1(const std::vector<int>& A, int izq, int der, int x);
    static int busquedaBinaria2(const std::vector<int>& A, int izq, int der, int x);
    static int busquedaBinariaInterpolacion(const std::vector<int>& A, int izq, int der, int x);

    // Versiones iterativas
    static int busquedaBinaria1Iterativa(const std::vector<int>& A, int izq, int der, int x);
    static int busquedaBinaria2Iterativa(const std::vector<int>& A, int izq, int der, int x);
    static int busquedaBinariaInterpolacionIterativa(const std::vector<int>& A, int izq, int der, int x);

    // Generadores de datos para pruebas
    static std::vector<int> generarVectorOrdenado(int size, bool uniforme = true);
    static std::vector<int> generarVectorConRepetidos(int size, int numRepeticiones);
    static std::vector<int> generarVectorDistribucionNormal(int size, double media, double desviacion);

    // Métodos para medir tiempo de ejecución
    template<typename Func>
    static double medirTiempo(Func func) {
        auto inicio = std::chrono::high_resolution_clock::now();
        func();
        auto fin = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duracion = fin - inicio;
        return duracion.count();
    }

    // Verificación específica para primera ocurrencia
    static bool verificarPrimeraOcurrencia(const std::vector<int>& A);
};

#endif // ALGORITMOS_BUSQUEDA_H
