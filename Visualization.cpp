#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
#include <queue>

class Edge {
public:
    int to; // 终点的编号
    int cost; // 路径长度
    Edge(int to, int cost) : to(to), cost(cost){}
    ~Edge() {}
};

class Node {
public:
    std::vector<Edge> edges; // 记录所有出边
    Node() {
        edges.clear();
    }
    ~Node() {}
};

class DAG{
private:
    int n, m; // 节点个数 边的个数
    int Pmin, Pmax; // 压力最小值 & 加压后的压力
    std::vector<Node> nodes; // 节点
public:
    DAG(){
        std::cin >> n >> m >> Pmax;
        Pmin = 0;
        nodes.clear(); 
        // 初始化元素
        for (int i = 0; i <= n; ++i) nodes.push_back(Node());
        // 读入m条边
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            nodes[u].edges.emplace_back(v, w); 
        }
    }
    ~DAG() {}
    void output() {
        std::ofstream out("1.dot");
        out << "digraph g {\n";
        for (int i = 1; i < nodes.size(); i++) {
            out << i;
            out << "[label=\"node" << i << "\",style=filled, fillcolor=white];\n";
        }
        for (auto i = 1; i <= n; ++i) {
            for (auto& edge : nodes[i].edges) {
                out << i << "->" << edge.to << "[label=\"cost=" << edge.cost << "\"];\n";
            }
        }
        out << "}\n";
        out.close();
        system("dot -Tjpg 1.dot -o solve1.jpg");
    }
};

int main() {
    DAG graph;
    graph.output();
    return 0;
}