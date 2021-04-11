#include <iostream>
#include "HeldKarp.h"

int main() {
    vector<pair<int, int>> nodes = { {1, 0}, {1, 3}, {4, 0}, {4, 3} };
    HeldKarp* TSP = new HeldKarp(4, 0, nodes);

    cout << "Minima distancia: " << TSP->getMinimunDistance() << endl;
    cout << "Ruta: ";
    for (auto it : TSP->getRoute()) cout << it << " -> ";
    cout << endl;
    cout << "Tiempo de ejecucion: " << TSP->getExecutionTime() << endl;
    cout << "Cantidad de iteraciones: " << TSP->getCantIterations() << endl;

    return 0;
}