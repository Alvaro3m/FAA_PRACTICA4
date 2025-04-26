// Algoritmos.cpp
#include "Algoritmos.h"
#include <iostream>

// Implementación de búsqueda binaria recursiva estándar
int Algoritmos::busquedaBinaria1(const std::vector<int>& A, int izq, int der, int x) {
    if (izq > der) {
        return -1;
    } else {
        int medio = izq + (der - izq) / 2; // Evita overflow
        
        if (A[medio] == x) {
            return medio;
        } else if (A[medio] > x) {
            return busquedaBinaria1(A, izq, medio - 1, x);
        } else {
            return busquedaBinaria1(A, medio + 1, der, x);
        }
    }
}

// Implementación de búsqueda binaria con índice de primera ocurrencia
int Algoritmos::busquedaBinaria2(const std::vector<int>& A, int izq, int der, int x) {
    if (izq > der) {
        return -1;
    } else {
        int medio = izq + (der - izq) / 2;
        
        if (A[medio] == x && (medio == izq || A[medio - 1] != x)) {
            return medio;
        } else if (A[medio] >= x) {
            return busquedaBinaria2(A, izq, medio - 1, x);
        } else {
            return busquedaBinaria2(A, medio + 1, der, x);
        }
    }
}

// Implementación de búsqueda binaria con interpolación
int Algoritmos::busquedaBinariaInterpolacion(const std::vector<int>& A, int izq, int der, int x) {
    if (izq > der || (izq < der && (x < A[izq] || x > A[der]))) {
        return -1;
    } else {
        int pos;
        
        if (A[der] == A[izq]) {
            pos = izq;
        } else {
            // Fórmula de interpolación
            pos = izq + ((double)(x - A[izq]) * (der - izq)) / (A[der] - A[izq]));
        }
        
        // Comprobar si la posición calculada está dentro del rango
        if (pos < izq || pos > der) {
            // Fallback a búsqueda binaria estándar si hay problemas numéricos
            pos = izq + (der - izq) / 2;
        }
        
        if (A[pos] == x) {
            return pos;
        } else if (A[pos] > x) {
            return busquedaBinariaInterpolacion(A, izq, pos - 1, x);
        } else {
            return busquedaBinariaInterpolacion(A, pos + 1, der, x);
        }
    }
}

// Implementación de búsqueda binaria estándar iterativa
int Algoritmos::busquedaBinaria1Iterativa(const std::vector<int>& A, int izq, int der, int x) {
    while (izq <= der) {
        int medio = izq + (der - izq) / 2;
        
        // Caso: elemento encontrado
        if (A[medio] == x) {
            return medio;
        }
        // Caso: buscar en la mitad izquierda
        else if (A[medio] > x) {
            der = medio - 1;
        }
        // Caso: buscar en la mitad derecha
        else {
            izq = medio + 1;
        }
    }
    
    return -1; // Elemento no encontrado
}

// Implementación de búsqueda binaria con primera ocurrencia iterativa
int Algoritmos::busquedaBinaria2Iterativa(const std::vector<int>& A, int izq, int der, int x) {
    int resultado = -1; // Para almacenar la última ocurrencia encontrada
    
    while (izq <= der) {
        int medio = izq + (der - izq) / 2;
        
        // Caso: elemento encontrado
        if (A[medio] == x) {
            resultado = medio; // Guardamos esta ocurrencia
            der = medio - 1;   // Seguimos buscando hacia la izquierda
        }
        // Caso: buscar en la mitad izquierda
        else if (A[medio] > x) {
            der = medio - 1;
        }
        // Caso: buscar en la mitad derecha
        else {
            izq = medio + 1;
        }
    }
    
    return resultado;
}

// Implementación de búsqueda binaria con interpolación iterativa
int Algoritmos::busquedaBinariaInterpolacionIterativa(const std::vector<int>& A, int izq, int der, int x) {
    while (izq <= der && x >= A[izq] && x <= A[der]) {
        int pos;
        
        // Evitar división por cero
        if (A[der] == A[izq]) {
            pos = izq;
        } else {
            // Fórmula de interpolación
            pos = izq + ((double)(x - A[izq]) * (der - izq)) / (A[der] - A[izq]));
        }
        
        // Verificar límites y usar fallback si es necesario
        if (pos < izq || pos > der) {
            pos = izq + (der - izq) / 2;
        }
        
        // Caso: elemento encontrado
        if (A[pos] == x) {
            return pos;
        }
        // Caso: buscar en la mitad izquierda
        else if (A[pos] > x) {
            der = pos - 1;
        }
        // Caso: buscar en la mitad derecha
        else {
            izq = pos + 1;
        }
    }
    
    return -1; // Elemento no encontrado
}

// Generación de vector ordenado aleatorio
std::vector<int> Algoritmos::generarVectorOrdenado(int size, bool uniforme) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> result;
    
    if (uniforme) {
        // Distribución uniforme
        std::uniform_int_distribution<> dis(1, size * 2);
        for (int i = 0; i < size; ++i) {
            result.push_back(dis(gen));
        }
    } else {
        // Distribución exponencial
        for (int i = 0; i < size; ++i) {
            result.push_back(1 << (i % 10)); // Valores 2^i
        }
        // Mezclamos para evitar que esté perfectamente ordenado
        std::shuffle(result.begin(), result.end(), gen);
    }
    
    // Ordenamos el vector
    std::sort(result.begin(), result.end());
    return result;
}

// Generación de vector con elementos repetidos
std::vector<int> Algoritmos::generarVectorConRepetidos(int size, int numRepeticiones) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, size / numRepeticiones);
    
    std::vector<int> result;
    for (int i = 0; i < size / numRepeticiones; ++i) {
        int valor = dis(gen);
        for (int j = 0; j < numRepeticiones; ++j) {
            result.push_back(valor);
        }
    }
    
    std::sort(result.begin(), result.end());
    return result;
}

// Generación de vector con distribución normal
std::vector<int> Algoritmos::generarVectorDistribucionNormal(int size, double media, double desviacion) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(media, desviacion);
    
    std::vector<int> result;
    for (int i = 0; i < size; ++i) {
        result.push_back(static_cast<int>(dis(gen)));
    }
    
    std::sort(result.begin(), result.end());
    return result;
}

// Verificación de que busquedaBinaria2 devuelve la primera ocurrencia
bool Algoritmos::verificarPrimeraOcurrencia(const std::vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
        int x = A[i];
        int indice = busquedaBinaria2(A, 0, A.size() - 1, x);
        
        // Verificar que el índice es válido
        if (indice == -1 || A[indice] != x) {
            std::cout << "Error: elemento " << x << " no encontrado correctamente." << std::endl;
            return false;
        }
        
        // Verificar que es la primera ocurrencia
        if (indice > 0 && A[indice - 1] == x) {
            std::cout << "Error: " << indice << " no es la primera ocurrencia de " << x << std::endl;
            return false;
        }
    }
    return true;
}
