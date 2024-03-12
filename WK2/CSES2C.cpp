/* soluion to: https://www.cses.fi/problemset/task/1671/
 * Shortest Routes I
*/

#include <vector>
#include <iostream>
#include <queue>
#include <functional>

class Connection {
public:
    City* c2;
    long cost;

    Connection(City* city2, long connectionCost) : c2(city2), cost(connectionCost) {}

    long getCost() const {
        return cost;
    }

    City* getCity() const {
        return c2;
    }

    void incrementCost(long add) {
        cost += add;
    }
};


class City {
public:
    bool visited;
    std::vector<Connection> connections;
    long cost;

    City() : visited(false), cost(0) {}

    long getCost() const {
        return cost;
    }

    void setCost(long newCost) {
        cost = newCost;
    }

    bool isVisited() const {
        return visited;
    }

    void setVisited() {
        visited = true;
    }

    void addConnection(City* c2, long cost) {
        connections.emplace_back(c2, cost);
    }

    std::vector<Connection> getConnections(long additionalCost) {
        for (Connection& c : connections) {
            c.incrementCost(additionalCost);
        }
        return connections;
    }
};

// Comparator function
auto ConnectionComparator = [](const Connection& c1, const Connection& c2) {
    if (c1.getCost() > c2.getCost()) {
        return 1;
    } else if (c1.getCost() < c2.getCost()) {
        return -1;
    }
    return 0;
};

int main() {
    long n, m;
    std::cin >> n >> m;
    std::vector<City> cities(static_cast<size_t>(n) + 1);
    std::priority_queue<Connection, std::vector<Connection>, ConnectionComparator> priority;
    for (int i = 1; i < n + 1; i++) {
        // Assuming City class has a default constructor
    }
    int counter = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        long c;
        std::cin >> a >> b >> c;
        cities[a].addConnection(&cities[b], c);
        if (a == 1 && c == 1) {
            cities[b].setCost(1);
        }
    }
    priority.push(Connection(&cities[1], 0));
    while (counter <= n) {
        Connection a = priority.top();
        priority.pop();
        City* b = a.getCity();
        if (b->isVisited()) continue;
        b->setVisited();
        counter++;
        b->setCost(a.getCost());
        std::vector<std::pair<City*, long>> connections = b->getConnections(a.getCost());
        for (const auto& conn : connections) {
            priority.push(Connection(conn.first, conn.second));
        }
    }

    for (int i = 1; i < n + 1; i++) {
        std::cout << cities[i].getCost() << " ";
    }
    std::cout << std::endl;

    return 0;
}







// #include <stdio.h>
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <list>


// struct City{
//     bool _visited;
//     std::vector<struct Connection> _connections;
//     long _cost;
// };

// struct Connection{
//     City _c2;
//     long _cost;

//     bool operator<(const Connection& c1) const{
//         return c1._cost < _c2._cost;
//     }
// };

// // struct CompareConnection {
// //     bool operator()(Connection const& c1, Connection const& c2)
// //     {
// //         return c1._cost < c2._cost;
// //     }
// // };



// int main(){
//     int n, m;
//     std::cin >> n >> m;

//     std::vector<City> cities;

//     for (int i = 1; i < n + 1; i++){
//         struct City cit;
//         cities[i] = cit;
//     }

//     for (int i = 0; i < m; i++){
//         int a, b;
//         long c;
//         std::cin >> a;
//         std::cin >> b;
//         std::cin >> c;
//         struct Connection _connect;
//         _connect._c2 = cities.at(b);
//     }

//     //std::priority_queue<Connection> pq;
//     std::list<Connection> _pq;
//     struct Connection start;
//     start = {cities.at(1), 0};
//     //std::list<int>::iterator it = _pq.begin();
//     //pq.push(start);
//     _pq.push_front(start);
    

//     while (!_pq.empty()){
//         struct Connection popped = _pq.front();
//         _pq.pop_front();
//         struct City poppedCity = popped._c2;
//         if (poppedCity._visited) continue;
//         poppedCity._visited = true;
//         poppedCity._cost = popped._cost;
//         std::vector<struct Connection> newConnect = poppedCity._connections;
//         for (Connection connects : newConnect){
//             connects._cost += popped._cost;
//             _pq.push_front(connects);
//         }
//         _pq.sort();
        
//     }

//     for (int i = 1; i < n+1; i++){
//         std::cout << cities.at(i)._cost << " ";
//     }
// };