#include <bits/stdc++.h>

using namespace std;

class point{
    public:
        double x, y;
        vector<int> connections;
};

double originDitance(point a){
    return sqrt(a.x*a.x + a.y*a.y);
}

double distance(point a, point b){
    double x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x*x + y*y);
}

double inclination(point p){
    return atan2(p.y, p.x);
}

double relativeInclination(point p, point q){
    return atan2(q.y - p.y, q.x - p.x);
}

int curve(point a, point b, point c){
    double v = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
    if(v < 0) return -1; //esquerda
    if(v > 0) return 1; //direita
    return 0;
}

void dfs(vector<point> graph, point n){
    for(auto w : graph){
        int i = 0;
        for(int i = 0; i < w.connections.size(); i++){

        }
        dfs(graph, graph[w.connections[]]);
        w.connections[]
    }
}

int main (){

    int n, m; cin >> n >> m;
    vector<point> graph(n);
    //vector<vector<int>> visited(n)(10e6);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        point p; p.x = x, p.y = y;
        int k; cin >> k;
        while (k--){
            int a; cin >> a;
            p.conecctions.push_back(a); 
        }
    }

    //dfs();

    return 0;
}