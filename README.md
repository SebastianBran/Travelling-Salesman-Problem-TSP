# **Travelling Salesman Problem - Matemática Computacional**

### Universidad Peruana de Ciencias Aplicadas | 2021-1

### Integrantes:

* Bran Zapata, Estefano Sebastian
* Bravo Lliuya, Sayda Nayeli
* Medina Cortez, Alexander Fausto
* Porras Tarifeño, Luis Alfredo
* Velarde Cupe, Daniel


## 1. Introducción

En el presente trabajo, abordaremos la solución del problema del agente viajero (TSP). Para eso, mostraremos los conceptos necesarios para construir una solución óptima y eficiente que resuelva el problema. También, se presentará el proceso de desarrollo para la solución, aplicando el enfoque de programación dinámica.

Para ello, construiremos un programa utilizando algunas tecnologías escogidas por el equipo como el lenguaje de programación C++, Windows Forms para la parte visual y el IDE Visual Studio 2019. Asimismo, nos apoyaremos en conceptos matemáticos como la distancia entre dos puntos y teoría de grafos, y conceptos computacionales como la programación dinámica, el algoritmo de Held-Karp, bitmask y manejo de bits.

Por último, se presentarán 4 ejemplos resueltos sobre el problema del agente viajero para un mejor entendimiento sobre el tema. Además, se mostrarán los resultados que obtuvo el equipo durante todo el proceso de desarrollo del programa, desde la implementación inicial del algoritmo de Held-Karp, hasta el programa final. También, se expondrán las conclusiones del equipo luego de la resolución del problema y se adjuntará todas las fuentes de información utilizadas, para la realización del presente informe, en formato APA.

## 2. Problema del Agente Viajero (Travelling Salesman Problem)

El problema del agente viajero o Travelling Salesman Problem (TSP) es clasificado como un problema de optimización combinatoria, es decir intervienen cierta cantidad de variables donde cada variable puede tener distintos valores y cuyo número de combinaciones aumenta exponencialmente. (Fuentes, 2014) 

El problema en general consiste en la ruta que quiere realizar un viajero, donde debe visitar N cantidad de ciudades con las siguiente únicas dos condiciones: Puede empezar por cualquiera, pero debe terminar en la misma ciudad que comenzó y no puede ir por una ciudad dos o más veces.

<img src="./images/representacion_tsp.png" width="300px" heigh="300px"><br>
Figura 1: Se muestra una representación gráfica al problema del agente viajero, creada por el grupo.

## 3. Algoritmo de Held-Karp

Según Bouman, Agatz & Schmidt (2017), el algoritmo de Held-Karp es un enfoque de programación dinámica para resolver el problema del agente viajero (TSP). El cual consiste en calcular todos los subproblemas posibles empezando por los subproblemas más pequeños. Por ello el equipo planteó un enfoque recursivo que nos permita hallar la solución óptima representado de la siguiente manera:

### 3.1. Enfoque recursivo

Teniendo en cuenta las ciudades 1, 2, 3, …, N, asumimos que empezamos desde la ciudad 1 y la distancia entre la ciudad i y j es d_ij. El subconjunto de ciudades no visitadas S ⊆ { 2, 3, …, N } y D(S, C), la distancia mínima de empezar en la ciudad 1 y terminar en la ciudad C. Por lo tanto, obtenemos la siguiente fórmula matemática:

<img src="https://latex.codecogs.com/png.latex?\bg_white&space;D(\left&space;\{2,&space;3,&space;...&space;,&space;N\right&space;\},&space;1)&space;=&space;min_{C\&space;\in&space;\&space;\left&space;\{&space;2,&space;3,&space;...&space;,&space;N&space;\right&space;\}}\left&space;\{&space;D(\left&space;\{2,&space;3,&space;...&space;,&space;N\right&space;\}&space;-&space;\left&space;\{C&space;\right&space;\},&space;C)&space;&plus;&space;d_{KC}&space;\right&space;\}" title="D(\left \{2, 3, ... , N\right \}, 1) = min_{C\ \in \ \left \{ 2, 3, ... , N \right \}}\left \{ D(\left \{2, 3, ... , N\right \} - \left \{C \right \}, C) + d_{KC} \right \}" />

De manera general:

<img src="https://latex.codecogs.com/png.latex?\bg_white&space;D(S,&space;K)&space;=&space;min_{C\&space;\in&space;\&space;S}\left&space;\{&space;D(S&space;-&space;\left&space;\{C&space;\right&space;\},&space;C)&space;&plus;&space;d_{KC}&space;\right&space;\}" title="D(S, K) = min_{C\ \in \ S}\left \{ D(S - \left \{C \right \}, C) + d_{KC} \right \}" /> <br>
<img src="https://latex.codecogs.com/png.latex?\bg_white&space;D(\left&space;\{&space;\right&space;\},&space;K)&space;=&space;d_{KI}" title="D(\left \{ \right \}, K) = d_{KI}" />

## 4. Optimización del algoritmo de Held-Karp usando bitmask

Debido a que el algoritmo de Held-Karp necesita recorrer todo el conjunto de estados posibles para poder elegir la solución más óptima, es probable que este enfoque requiera más tiempo y recursos para su ejecución cuando la complejidad del problema aumente. Por eso, el grupo decidió implementar a la solución las bitmask.  Las cuales nos facilitan la toma de decisiones cuando estas se basan en conjuntos.

Por ejemplo, para 5 ciudades la bitmask 11111 representa cuando todas las ciudades han sido visitadas, es decir 31 estados posibles por la representación de la bitmask en decimal. 

Entonces, ya que cada estado puede ser representado por un bitmask, se puede ir puede almacenando la respuesta óptima para cada estado en una matriz bidimensional del tipo DP[mask][k], donde mask es un estado representado por una bitmask y k el nodo desde donde se consulta ese estado.

Finalmente, la representación matemática del algoritmo de Held-karp presentado por el grupo quedaría de la siguiente manera:

<img src="https://latex.codecogs.com/png.latex?\bg_white&space;DP(mask,&space;K)&space;=&space;min_{2^j&space;\&space;\&&space;\&space;mask&space;\&space;=&space;\&space;j}\left&space;\{&space;DP(mask&space;\oplus&space;2^j,&space;j)&space;&plus;&space;d_{Kj}&space;\right&space;\}" title="DP(mask, K) = min_{2^j \ \& \ mask \ = \ j}\left \{ DP(mask \oplus 2^j, j) + d_{Kj} \right \}" /><br>
<img src="https://latex.codecogs.com/png.latex?\bg_white&space;DP(todos-visitados,&space;K)&space;=&space;d_{KI}" title="DP(todos-visitados, K) = d_{KI}" />

## 5. Código principal de la solución

```c++
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
    int MAXN;
    int NODE_INI;
    int cant_iterations;
    double minimun_distance;
    
    unsigned t0, t1;
    double execution_time;

    vector<pair<int,int>> nodes; 
    vector<vector<pair<double, stack<int>>>> dp;
    vector<vector<double>> distance;
    vector<int> route;
public:
    HeldKarp(int MAXN, int NODE_INI, vector<pair<int,int>>& nodes) {
        cant_iterations = 0;
        this->MAXN = MAXN;
        this->NODE_INI = NODE_INI;
        this->nodes = nodes;
        dp.resize((1 << MAXN), vector<pair<double, stack<int>>>(MAXN));
        distance.resize(MAXN, vector<double>(MAXN));
        init_dp();
        calculate_distance();

        t0 = clock();
        pair<double, stack<int>> answer = TSP((1 << NODE_INI), NODE_INI, stack<int>());
        answer.second.push(NODE_INI);
        t1 = clock();
        execution_time = (double(t1 - t0) / CLOCKS_PER_SEC);

        minimun_distance = answer.first;
        stack<int> aux = answer.second;
        while(!aux.empty()) {
            route.push_back(aux.top());
            aux.pop();
        }
    }

    double getExecutionTime() { return execution_time; }
    int getCantIterations() { return cant_iterations; }
    double getMinimunDistance() { return minimun_distance; }
    vector<int> getRoute() { return route; }
private:
    void init_dp() {
        for(int i = 0; i < (1 << MAXN); i++) {
            for(int j = 0; j < MAXN; j++) {
                dp[i][j] = { -INF, stack<int>() };
            }
        }
    }

    void calculate_distance() {
        for(int i = 0; i < MAXN; i++) {
            for(int j = i; j < MAXN; j++) {
                if(i == j) distance[i][j] = -1;
                else {
                    double d = sqrt(pow(nodes[i].first - nodes[j].first, 2) + pow(nodes[i].second - nodes[j].second, 2));
                    distance[i][j] = distance[j][i] = d;
                }
            }
        }
    }

    pair<double, stack<int>> TSP(int mask, int i, stack<int> route) {
        cant_iterations++; 

        if (mask == ((1 << MAXN) - 1)) {
            route.push(NODE_INI);
            return dp[mask][i] = { distance[NODE_INI][i], route };
        }
        if (dp[mask][i].first != -INF) return dp[mask][i];

        double min_dis = INF, curr_dis;
        pair<int, stack<int>> curr;
        stack<int> best_route;

        for (int j = 0; j < MAXN; j++) {
            if ((mask & (1 << j)) == 0) {
                curr = TSP(mask | (1 << j), j, route);
                curr.second.push(j);
                curr_dis = curr.first + distance[j][i];
                if (curr_dis < min_dis) {
                    min_dis = curr_dis;
                    best_route = curr.second;
                }
                curr.second.pop();
            }
        }

        return dp[mask][i] = { min_dis, best_route };
    }
};
```

## 6. Conclusiones

* El TSP es una problemática que se puede observar en diversas situaciones de la vida cotidiana tales como encontrar el camino más corto para realizar un viaje en autobús, reparto de un producto por delivery, inspección a sitios remotos, entre otros.
* La resolución del TSP nos permitió entender cómo funciona la mayoría de aplicativos de ubicación y tránsito tales como Google maps y Waze, y como estos calculan el tiempo estimado de viaje de un punto a otro.
* Gracias al material del aula virtual, lo aprendido en clase, documentación web confiable y videos de Youtube se pudo desarrollar la solución del TSP en un tiempo breve, debido a que nos permitieron comprender de mejor manera el problema y la teoría de grafos.
* Aprendimos a utilizar los grafos para representar las conexiones y trayectorias que existen entre las ciudades del TSP. Siendo los vértices del grafo las ciudades que se desean visitar y las aristas las distancias entre cada ciudad.
* El algoritmo de Help-Karp es uno de los algoritmos más simples para resolver el TSP, debido a que es un algoritmo recursivo y de corta implementación. Sin embargo
