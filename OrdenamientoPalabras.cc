#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Función para crear un mapa de orden basado en la permutación
unordered_map<char, int> createOrderMap(const string& permutation) {
    unordered_map<char, int> orderMap;
    for (size_t i = 0; i < permutation.size(); i++) {
        orderMap[permutation[i]] = i; // Mapeamos cada letra a su índice en la permutación
    }
    // Añadir letras mayúsculas con un valor mayor
    for (size_t i = 0; i < permutation.size(); i++) {
        orderMap[toupper(permutation[i])] = i + 26; // Mapeamos letras mayúsculas con un índice mayor
    }
    return orderMap;
}

// Función de comparación para ordenar las cadenas
bool customCompare(const string& a, const string& b, const unordered_map<char, int>& orderMap) {
    size_t len = min(a.size(), b.size());
    for (size_t i = 0; i < len; i++) {
        char charA = a[i];
        char charB = b[i];

        // Comparamos según el orden en el mapa
        if (orderMap.at(charA) != orderMap.at(charB)) {
            return orderMap.at(charA) < orderMap.at(charB);
        }
    }
    // Si son iguales hasta el tamaño más corto, la cadena más corta es "menor"
    return a.size() < b.size();
}

int main() {
    string permutation;
    cin >> permutation; // Leer la permutación
    int N;
    cin >> N; // Leer el número de cadenas
    vector<string> strings(N); // Vector para almacenar las cadenas

    // Leer las cadenas
    for (int i = 0; i < N; i++) {
        cin >> strings[i];
    }

    // Crear el mapa de orden
    unordered_map<char, int> orderMap = createOrderMap(permutation);

    // Ordenar las cadenas utilizando la función de comparación personalizada
    sort(strings.begin(), strings.end(), [&orderMap](const string& a, const string& b) {
        return customCompare(a, b, orderMap);
    });

    // Imprimir las cadenas ordenadas
    for (const string& str : strings) {
        cout << str << endl;
    }

    return 0;
}
