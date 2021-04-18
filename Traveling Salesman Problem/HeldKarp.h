#pragma once
#include <tuple>
#include <vector>
#include <stack>
#include <ctime>
#include <math.h>

using namespace std;

const double INF = 1e9;

class HeldKarp {
private:
    int MAXN; //numero de ciudades
    int NODE_INI; //nodo inicial
    int cant_iterations; //cantidad de iteraciones
    double minimun_distance; //respuesta a al problema (minuma distancia)

    unsigned t0, t1; //punteros de tiempo
    double execution_time; //tiempo de ejecucion en segundos

    vector<pair<int, int>> nodes;
    vector<vector<pair<double, stack<int>>>> dp;
    vector<vector<double>> distance;
    vector<int> route; //ruta para la minima distancia
public:
    HeldKarp(int MAXN, int NODE_INI, vector<pair<int, int>>& nodes) {
        cant_iterations = 0;
        this->MAXN = MAXN;
        this->NODE_INI = NODE_INI;
        this->nodes = nodes;
        dp.resize((1 << MAXN), vector<pair<double, stack<int>>>(MAXN));
        distance.resize(MAXN, vector<double>(MAXN));
        init_dp(); //inicializa la matriz para el DP
        calculate_distance(); //calcula la distancia entre todos los nodos

        t0 = clock();
        pair<double, stack<int>> answer = TSP((1 << NODE_INI), NODE_INI, stack<int>()); //se calcula la minima distancia y la mejor ruta para el problema
        answer.second.push(NODE_INI); //se añade el nodo de inicio a la respuesta final
        t1 = clock();
        execution_time = (double(t1 - t0) / CLOCKS_PER_SEC); //convierte el tiempo a segundo

        minimun_distance = answer.first; //se guarda la minima distancia
        stack<int> aux = answer.second; //se copia la ruta a una variable auxiliar
        while (!aux.empty()) { //se translada el contenido del auxiliar al vector ruta
            route.push_back(aux.top());
            aux.pop();
        }
    }
    ~HeldKarp() {
        nodes.clear();
        dp.clear();
        distance.clear();
        route.clear();
    }

    double getExecutionTime() { return execution_time; } //devuelve el tiempo de ejecucion
    int getCantIterations() { return cant_iterations; } //devuelve la cantidad de iteraciones
    double getMinimunDistance() { return minimun_distance; } //devuelve la minima distancia
    vector<int> getRoute() { return route; } //devuelve la mejor ruta
private:
    void init_dp() {
        for (int i = 0; i < (1 << MAXN); i++) {
            for (int j = 0; j < MAXN; j++) {
                dp[i][j] = { -INF, stack<int>() }; //se inicializa el DP con un valor infinito y una pila vacia
            }
        }
    }

    void calculate_distance() {
        for (int i = 0; i < MAXN; i++) {
            for (int j = i; j < MAXN; j++) {
                if (i == j) distance[i][j] = -1; //si el nodo es el mismo se guarda como -1 por defecto
                else {
                    double d = sqrt(pow(nodes[i].first - nodes[j].first, 2) + pow(nodes[i].second - nodes[j].second, 2)); //distancia entre dos puntos
                    distance[i][j] = distance[j][i] = d; //se almacena la distancia de manera simetrica en la matriz por ser un grafo no dirigido
                }
            }
        }
    }

    pair<double, stack<int>> TSP(int mask, int i, stack<int> route) {
        cant_iterations++; //se contabiliza las iteraciones

        if (mask == ((1 << MAXN) - 1)) { //si ya se visitaron todas las ciudades, devolver la distancia entre la ciudad inicial y la ciudad de consulta
            route.push(NODE_INI);
            return dp[mask][i] = { distance[NODE_INI][i], route };
        }
        if (dp[mask][i].first != -INF) return dp[mask][i]; //si ya se calculo el estado, devolverlo

        double min_dis = INF, curr_dis; //minima distancia y distancia actual del estado respectivamente
        pair<int, stack<int>> curr; //resuesta del estado actual
        stack<int> best_route; //mejor ruta del estado

        for (int j = 0; j < MAXN; j++) {
            if ((mask & (1 << j)) == 0) { //se verifica que la ciudad no ha sido visitada
                curr = TSP(mask | (1 << j), j, route); //se recibe los resultados del estado en consulta
                curr.second.push(j); //se añade la ciudad actual a la ruta del estado calculado
                curr_dis = curr.first + distance[j][i]; //se guarda la respuesta para la distancia del estado consultado y se añade la distancia de la ciudad actual y la del estado consultado
                if (curr_dis < min_dis) { //se verifica si la distacia actual es menor que la minima distancia calculada
                    min_dis = curr_dis; //se actualiza el valor de la minima distancia
                    best_route = curr.second; //se actualiza la mejor ruta del estado actual
                }
                curr.second.pop(); //se remueve a la ciudad añadida previamente para realizar una nueva consulta
            }
        }

        return dp[mask][i] = { min_dis, best_route }; //se actualiza el DP del estado consultado y se devuelve la respuesta
    }
};