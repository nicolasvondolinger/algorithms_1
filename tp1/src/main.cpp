#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back

/*
double originDitance(int a){
    return sqrt(a.x*a.x + a.y*a.y);
}

double distance(int a, int b){
    double x = (a.x - b.x), y = (a.y - b.y);
    return sqrt(x*x + y*y);
}

double inclination(int p){
    return atan2(p.y, p.x);
}

int curve(int a, int b, int c){
    double v = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
    if(v < 0) return -1; //esquerda
    if(v > 0) return 1; //direita
    return 0;
}
*/

vector<int> face;
vector<vector<int>> faces;

double relativeInclination(double x1, double x2, double y1, double y2){
    return atan2(y1 - y2, x1 - x2);
}

vector<int> sort_connections(int i, vector<int>& connections, vector<pair<double, double>> pos){
    double x_ref = pos[i].first;
    double y_ref = pos[i].second;
    sort(connections.begin(), connections.end(), [&](double a, double b) {
        double incl_a = relativeInclination(pos[a].first, x_ref, pos[a].second, y_ref);
        double incl_b = relativeInclination(pos[b].first, x_ref, pos[b].second, y_ref);
        return incl_a < incl_b;
    });

    return connections;
}

void printFaces(){
    cout << faces.size() << endl;
    for(int i = 0; i < faces.size(); i++){
        cout << faces[i].size() << " ";
        for(int j = 0;  j < faces[i].size(); j++){
            cout << faces[i][j]+1 << " ";
        }
        cout << endl;
    }
}

void isBridge(int n, vector<vector<int>>& graph, vector<bool>& v){
    v[n] = true;
    for(auto w: graph[n]) if(!v[w]){
        isBridge(w, graph, v);
    }
}

void dfs(int b, int i, int j, int n, vector<vector<int>>& graph, vector<vector<bool>>& visited, vector<pair<double, double>>& positions){

    visited[i][j] = true;

    if (b == n) {
        face.pb(b);
        faces.push_back(face);
        face.clear();
        return;
    }

    int k = 0;
    while(true){
        if(graph[n][k] == i){
            k++; 
            break;
        }
        k++;
    }

    for(; k <= graph[n].size(); k++){
        if(k == graph[n].size()) k = 0;
        if(!visited[n][k]) break;
    }
            
    face.pb(n);
    dfs(b, n, k, graph[n][k], graph, visited, positions);
    
}

int main (){

    int n, m; cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<vector<bool>> visited(n);
    vector<pair<double, double>> positions(n); 

    for(int i = 0; i < n; i++){
        double x, y; cin >> x >> y;

        pair<double, double> v; v.ff = x, v.ss = y;
        positions[i] = v;

        int k; cin >> k;
        while (k--){
            int a; cin >> a; a--;
            graph[i].pb(a); visited[i].pb(false);
        }
        
    }
    
    vector<int> orderToVisit, bridges, nonBridges;

    for(int i = 0; i < graph.size(); i++) {
        bool done = false;
        for(int j = 0; j < graph[i].size(); j++){
            vector<bool> v(n, false);
            vector<vector<int>> aux = graph;
            int a = aux[i][j];
            auto it = find(aux[i].begin(), aux[i].end(), a); aux[i].erase(it);
            it = find(aux[a].begin(), aux[a].end(), i); aux[a].erase(it);

            int count = 0; 
            for(int k = 0; k < n; k++) if(!v[k]){
                if(count == 1) {
                    done = true;
                    break;
                }
                isBridge(k, aux, v); count++;
            }
            
            if(done) break;

        }

        if(done) bridges.pb(i);
        else nonBridges.pb(i);
    }

    for (int vertex : nonBridges) orderToVisit.pb(vertex);
    for (int vertex : bridges) orderToVisit.pb(vertex);
    
    for(int i = 0; i < n; i++){
        graph[i] = sort_connections(i, graph[i], positions);
    }


    for(int i = 0; i < visited.size(); i++){
        for(int j = 0; j < visited[orderToVisit[i]].size(); j++){
            if(!visited[orderToVisit[i]][j]) {
                face.pb(orderToVisit[i]);
                dfs(orderToVisit[i], orderToVisit[i], j, graph[orderToVisit[i]][j], graph, visited, positions);
            }
        }
    }

    printFaces();

    return 0;
}