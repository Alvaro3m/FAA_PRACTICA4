// Main.cpp
#include "Algoritmos.h"
#include <iostream>
#include <iomanip>
#include <fstream>

// Función para ejecutar pruebas básicas de corrección
void ejecutarPruebasBasicas() {
    std::cout << "=== Ejecutando pruebas básicas ===" << std::endl;

    // Caso 1: Vector vacío
    std::vector<int> vacio;
    if (Algoritmos::busquedaBinaria1(vacio, 0, -1, 5) != -1) {
        std::cout << "Error en busquedaBinaria1: vector vacío" << std::endl;
    }
    if (Algoritmos::busquedaBinaria2(vacio, 0, -1, 5) != -1) {
        std::cout << "Error en busquedaBinaria2: vector vacío" << std::endl;
    }
    if (Algoritmos::busquedaBinariaInterpolacion(vacio, 0, -1, 5) != -1) {
        std::cout << "Error en busquedaBinariaInterpolacion: vector vacío" << std::endl;
    }

    // Caso 2: Vector con un solo elemento
    std::vector<int> unico = { 5 };
    if (Algoritmos::busquedaBinaria1(unico, 0, 0, 5) != 0) {
        std::cout << "Error en busquedaBinaria1: vector con un elemento" << std::endl;
    }
    if (Algoritmos::busquedaBinaria2(unico, 0, 0, 5) != 0) {
        std::cout << "Error en busquedaBinaria2: vector con un elemento" << std::endl;
    }
    if (Algoritmos::busquedaBinariaInterpolacion(unico, 0, 0, 5) != 0) {
        std::cout << "Error en busquedaBinariaInterpolacion: vector con un elemento" << std::endl;
    }

    // Caso 3: Vector normal
    std::vector<int> normal = { 1, 3, 5, 7, 9 };
    if (Algoritmos::busquedaBinaria1(normal, 0, 4, 3) != 1) {
        std::cout << "Error en busquedaBinaria1: vector normal" << std::endl;
    }
    if (Algoritmos::busquedaBinaria2(normal, 0, 4, 3) != 1) {
        std::cout << "Error en busquedaBinaria2: vector normal" << std::endl;
    }
    if (Algoritmos::busquedaBinariaInterpolacion(normal, 0, 4, 3) != 1) {
        std::cout << "Error en busquedaBinariaInterpolacion: vector normal" << std::endl;
    }

    // Caso 4: Elemento no presente
    if (Algoritmos::busquedaBinaria1(normal, 0, 4, 4) != -1) {
        std::cout << "Error en busquedaBinaria1: elemento no presente" << std::endl;
    }
    if (Algoritmos::busquedaBinaria2(normal, 0, 4, 4) != -1) {
        std::cout << "Error en busquedaBinaria2: elemento no presente" << std::endl;
    }
    if (Algoritmos::busquedaBinariaInterpolacion(normal, 0, 4, 4) != -1) {
        std::cout << "Error en busquedaBinariaInterpolacion: elemento no presente" << std::endl;
    }

    // Caso 5: Vector con elementos repetidos
    std::vector<int> repetidos = { 1, 3, 3, 3, 5, 7, 9 };
    int pos1 = Algoritmos::busquedaBinaria1(repetidos, 0, 6, , 3);
    if (pos1 != 1 && pos1 != 2 && pos1 != 3) {
        std::cout << "Error en busquedaBinaria1: vector con repetidos, devolvió " << pos1 << std::endl;
    }

    int pos2 = Algoritmos::busquedaBinaria2(repetidos, 0, 6, 3);
    if (pos2 != 1) {
        std::cout << "Error en busquedaBinaria2: vector con repetidos, devolvió " << pos2 << std::endl;
    }

    int posI = Algoritmos::busquedaBinariaInterpolacion(repetidos, 0, 6, 3);
    if (posI != 1 && posI != 2 && posI != 3) {
        std::cout << "Error en busquedaBinariaInterpolacion: vector con repetidos, devolvió " << posI << std::endl;
    }

    // Verificar versiones iterativas
    if (Algoritmos::busquedaBinaria1Iterativa(repetidos, 0, 6, 3) == -1) {
        std::cout << "Error en busquedaBinaria1Iterativa: vector con repetidos" << std::endl;
    }

    if (Algoritmos::busquedaBinaria2Iterativa(repetidos, 0, 6, 3) != 1) {
        std::cout << "Error en busquedaBinaria2Iterativa: vector con repetidos" << std::endl;
    }

    if (Algoritmos::busquedaBinariaInterpolacionIterativa(repetidos, 0, 6, 3) == -1) {
        std::cout << "Error en busquedaBinariaInterpolacionIterativa: vector con repetidos" << std::endl;
    }

    std::cout << "Pruebas básicas completadas." << std::endl << std::endl;
}

// Función para ejecutar pruebas exhaustivas
void ejecutarPruebasExhaustivas() {
    std::cout << "=== Ejecutando pruebas exhaustivas ===" << std::endl;

    // Prueba con diferentes tamaños
    for (int size : {10, 100, 1000}) {
        std::cout << "\nPruebas con vector de tamaño " << size << std::endl;

        // Vector con distribución uniforme
        std::vector<int> vectorUniforme = Algoritmos::generarVectorOrdenado(size, true);

        // Vector con distribución exponencial
        std::vector<int> vectorExponencial = Algoritmos::generarVectorOrdenado(size, false);

        // Vector con distribución normal
        std::vector<int> vectorNormal = Algoritmos::generarVectorDistribucionNormal(size, 0, size / 3);

        // Vector con elementos repetidos
        std::vector<int> vectorRepetidos = Algoritmos::generarVectorConRepetidos(size, 3);

        // Buscar elemento al principio
        int valorPrincipio = vectorUniforme[0];
        std::cout << "Buscando " << valorPrincipio << " (inicio): " << std::endl;
        std::cout << "  BB1: " << Algoritmos::busquedaBinaria1(vectorUniforme, 0, size - 1, valorPrincipio) << std::endl;
        std::cout << "  BB2: " << Algoritmos::busquedaBinaria2(vectorUniforme, 0, size - 1, valorPrincipio) << std::endl;
        std::cout << "  BBI: " << Algoritmos::busquedaBinariaInterpolacion(vectorUniforme, 0, size - 1, valorPrincipio) << std::endl;

        // Buscar elemento en medio
        int valorMedio = vectorUniforme[size / 2];
        std::cout << "Buscando " << valorMedio << " (medio): " << std::endl;
        std::cout << "  BB1: " << Algoritmos::busquedaBinaria1(vectorUniforme, 0, size - 1, valorMedio) << std::endl;
        std::cout << "  BB2: " << Algoritmos::busquedaBinaria2(vectorUniforme, 0, size - 1, valorMedio) << std::endl;
        std::cout << "  BBI: " << Algoritmos::busquedaBinariaInterpolacion(vectorUniforme, 0, size - 1, valorMedio) << std::endl;

        // Buscar elemento al final
        int valorFinal = vectorUniforme[size - 1];
        std::cout << "Buscando " << valorFinal << " (final): " << std::endl;
        std::cout << "  BB1: " << Algoritmos::busquedaBinaria1(vectorUniforme, 0, size - 1, valorFinal) << std::endl;
        std::cout << "  BB2: " << Algoritmos::busquedaBinaria2(vectorUniforme, 0, size - 1, valorFinal) << std::endl;
        std::cout << "  BBI: " << Algoritmos::busquedaBinariaInterpolacion(vectorUniforme, 0, size - 1, valorFinal) << std::endl;

        // Buscar elemento inexistente
        int valorInexistente = vectorUniforme[size - 1] + 100;
        std::cout << "Buscando " << valorInexistente << " (inexistente): " << std::endl;
        std::cout << "  BB1: " << Algoritmos::busquedaBinaria1(vectorUniforme, 0, size - 1, valorInexistente) << std::endl;
        std::cout << "  BB2: " << Algoritmos::busquedaBinaria2(vectorUniforme, 0, size - 1, valorInexistente) << std::endl;
        std::cout << "  BBI: " << Algoritmos::busquedaBinariaInterpolacion(vectorUniforme, 0, size - 1, valorInexistente) << std::endl;

        // Verificar primera ocurrencia en vectorRepetidos
        std::cout << "\nVerificando primera ocurrencia en vector con repetidos... ";
        if (Algoritmos::verificarPrimeraOcurrencia(vectorRepetidos)) {
            std::cout << "Correcto!" << std::endl;
        }
    }

    std::cout << "\nPruebas exhaustivas completadas." << std::endl << std::endl;
}

// Función para comparar versiones recursivas e iterativas
void compararRecursivoVsIterativo() {
    std::cout << "=== Comparación Recursivo vs Iterativo ===" << std::endl;
    std::ofstream archivo("comparacion_recursivo_iterativo.csv");
    archivo << "Tamaño,BB1_Recursivo,BB1_Iterativo,BB2_Recursivo,BB2_Iterativo,BBI_Recursivo,BBI_Iterativo" << std::endl;

    // Tamaños de vector a probar (desde 10^3 hasta 10^7)
    std::vector<int> tamanios = { 1000, 10000, 100000, 1000000, 10000000 };

    for (int n : tamanios) {
        std::cout << "Probando con tamaño n = " << n << std::endl;

        // Generar vector ordenado
        std::vector<int> vector = Algoritmos::generarVectorOrdenado(n, true);

        // Elegir elementos a buscar (inicio, 25%, medio, 75%, final)
        std::vector<int> elementosABuscar = {
            vector[0],
            vector[n / 4],
            vector[n / 2],
            vector[3 * n / 4],
            vector[n - 1]
        };

        double tiempoRecursivoBB1 = 0.0;
        double tiempoIterativoBB1 = 0.0;
        double tiempoRecursivoBB2 = 0.0;
        double tiempoIterativoBB2 = 0.0;
        double tiempoRecursivoInterpolacion = 0.0;
        double tiempoIterativoInterpolacion = 0.0;

        // Realizar múltiples búsquedas y promediar tiempo
        for (int x : elementosABuscar) {
            // Medir tiempo de BB1 Recursivo
            tiempoRecursivoBB1 += Algoritmos::medirTiempo([&]() {
                Algoritmos::busquedaBinaria1(vector, 0, n - 1, x);
                });

            // Medir tiempo de BB1 Iterativo
            tiempoIterativoBB1 += Algoritmos::medirTiempo([&]() {
                Algoritmos::busquedaBinaria1Iterativa(vector, 0, n - 1, x);
                });

            // Medir tiempo de BB2 Recursivo
            tiempoRecursivoBB2 += Algoritmos::medirTiempo([&]() {
                Algoritmos::busquedaBinaria2(vector, 0, n - 1, x);
                });

            // Medir tiempo de BB2 Iterativo
            tiempoIterativoBB2 += Algoritmos::medirTiempo([&]() {
                Algoritmos::busquedaBinaria2Iterativa(vector, 0, n - 1, x);
                });

            // Medir tiempo de BBI Recursivo
            tiempoRecursivoInterpolacion += Algoritmos::medirTiempo([&]() {
                Algoritmos::busquedaBinariaInterpolacion(vector, 0, n - 1, x);
                });

            // Medir tiempo de BBI Iterativo
            tiempoIterativoInterpolacion += Algoritmos::medirTiempo([&]() {
                Algoritmos::busquedaBinariaInterpolacionIterativa(vector, 0, n - 1, x);
                });
        }

        // Promediar tiempos
        tiempoRecursivoBB1 /= elementosABuscar.size();
        tiempoIterativoBB1 /= elementosABuscar.size();
        tiempoRecursivoBB2 /= elementosABuscar.size();
        tiempoIterativoBB2 /= elementosABuscar.size();
        tiempoRecursivoInterpolacion /= elementosABuscar.size();
        tiempoIterativoInterpolacion /= elementosABuscar.size();

        // Imprimir resultados
        std::cout << "Tiempos promedio (ms):" << std::endl;
        std::cout << "  BB1 Recursivo: " << std::fixed << std::setprecision(6) << tiempoRecursivoBB1 << std::endl;
        std::cout << "  BB1 Iterativo: " << std::fixed << std::setprecision(6) << tiempoIterativoBB1 << std::endl;
        std::cout << "  BB2 Recursivo: " << std::fixed << std::setprecision(6) << tiempoRecursivoBB2 << std::endl;
        std::cout << "  BB2 Iterativo: " << std::fixed << std::setprecision(6) << tiempoIterativoBB2 << std::endl;
        std::cout << "  BBI Recursivo: " << std::fixed << std::setprecision(6) << tiempoRecursivoInterpolacion << std::endl;
        std::cout << "  BBI Iterativo: " << std::fixed << std::setprecision(6) << tiempoIterativoInterpolacion << std::endl;

        // Guardar en archivo CSV
        archivo << n << ","
            << tiempoRecursivoBB1 << ","
            << tiempoIterativoBB1 << ","
            << tiempoRecursivoBB2 << ","
            << tiempoIterativoBB2 << ","
            << tiempoRecursivoInterpolacion << ","
            << tiempoIterativoInterpolacion << std::endl;
    }

    archivo.close();
    std::cout << "Resultados guardados en 'comparacion_recursivo_iterativo.csv'" << std::endl << std::endl;
}
