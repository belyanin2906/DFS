#include <iostream>
#include <vector>

using namespace std;

// Функция для поиска в глубину
bool search(int current, int target, vector<vector<int>>& graph, vector<bool>& visited) {
    // Если текущий город совпадает с нужным, то путь найден
    if (current == target) {
        return true;
    }
    // Помечаем текущий город как посещенный
    visited[current] = true;
    // Перебираем все города, в которые можно попасть из текущего
    for (int i = 0; i < graph.size(); ++i) {
        // Если есть рейс из текущего города в город i и город i еще не посещен
        if (graph[current][i] == 1 && !visited[i]) {
            // Рекурсивно вызываем функцию для города i
            if (search(i, target, graph, visited)) {
                return true;
            }
        }
    }
    // Если путь не найден, возвращаем false
    return false;
}

// Функция для проверки, можно ли попасть из города p в город q
bool check(int p, int q, vector<vector<int>>& graph) {
    // Создаем массив для отслеживания посещенных городов
    vector<bool> visited(graph.size(), false);
    // Вызываем функцию поиска для начального города p
    return search(p, q, graph, visited);
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    // Запрашиваем количество городов
    cout << "Введите количество городов: ";
    cin >> n;

    // Создаем матрицу смежности для хранения рейсов между городами
    vector<vector<int>> graph(n, vector<int>(n));
    // Запрашиваем ввод матрицы смежности
    cout << "Введите матрицу смежности (n x n):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int p, q;
    // Запрашиваем начальный и конечный города
    cout << "Введите начальный город p: ";
    cin >> p;
    cout << "Введите конечный город q: ";
    cin >> q;

    // Проверяем, можно ли попасть из города p в город q
    if (check(p, q, graph)) {
        cout << "Можно попасть из города " << p << " в город " << q << endl;
    }
    else {
        cout << "Нельзя попасть из города " << p << " в город " << q << endl;
    }

    return 0;
}