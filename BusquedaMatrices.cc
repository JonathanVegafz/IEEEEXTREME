#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<char>> matrix(N, vector<char>(M));
    vector<vector<int>> dist(N, vector<int>(M, -1));  // -1 indica que la celda no ha sido visitada
    queue<pair<int, int>> q;

    // Leer la matriz de entrada
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Leer las coordenadas de las celdas especiales y configurarlas en la distancia 0
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;  // Convertir a índice 0
        q.push({x, y});
        dist[x][y] = 0;  // Las celdas especiales tienen distancia 0
    }

    // Direcciones para moverse en 4 direcciones (arriba, abajo, izquierda, derecha)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Realizar BFS desde todas las celdas especiales
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            // Verificar límites y que sea una celda vacía sin visitar
            if (newX >= 0 && newX < N && newY >= 0 && newY < M &&
                matrix[newX][newY] == '.' && dist[newX][newY] == -1) {
                
                dist[newX][newY] = dist[x][y] + 1;  // Actualizar la distancia
                q.push({newX, newY});  // Añadir la nueva celda a la cola
            }
        }
    }

    // Sumar todas las distancias de las celdas vacías
    long long sumDistances = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == '.') {
                sumDistances += dist[i][j];
            }
        }
    }

    cout << sumDistances << endl;  // Imprimir la suma total de distancias
    return 0;
}
