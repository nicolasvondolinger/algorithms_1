#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back

vector<int> face;
vector<vector<int>> faces;

/**
 * @brief Calculate the relative inclination between two points
 * 
 * @param x1 X coordinate of the first point
 * @param x2 X coordinate of the second point
 * @param y1 Y coordinate of the first point
 * @param y2 Y coordinate of the second point
 * @return The angle in radians between the line connecting the two points and the horizontal axis
 */

double relativeInclination(double x1, double x2, double y1, double y2){
    return atan2(y1 - y2, x1 - x2);
}

/**
 * @brief Sort connections of a node based on their relative inclinations
 * 
 * @param i Index of the reference node
 * @param connections List of connections to be sorted
 * @param pos Positions of all nodes
 * @return Sorted list of connections based on their relative inclinations
 */

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

/**
 * @brief Print all the faces found
 */

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

/**
 * @brief Depth First Search to find faces in the graph
 * 
 * @param b Start node of the current face
 * @param i Current node being visited
 * @param j Current connection being followed
 * @param n Next node to visit
 * @param graph Adjacency list of the graph
 * @param visited Matrix to track visited edges
 * @param positions Positions of all nodes
 */
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
    int small = INT_MAX, p = 0;
    vector<vector<int>> graph(n);
    vector<vector<bool>> visited(n);
    vector<pair<double, double>> positions(n); 
    vector<pair<int, int>> orderToVisit;

    for(int i = 0; i < n; i++){
        double x, y; cin >> x >> y;

        pair<double, double> v; v.ff = x, v.ss = y;
        positions[i] = v;

        int k; cin >> k;
        orderToVisit.pb(make_pair(k, i));
        while(k--){
            int a; cin >> a; a--;
            graph[i].pb(a); visited[i].pb(false);
        }
        
    }
    
    sort(orderToVisit.begin(), orderToVisit.end());
    
    for(int i = 0; i < n; i++){
        graph[i] = sort_connections(i, graph[i], positions);
    }

    for(int i = 0; i < visited.size(); i++){
        for(int j = 0; j < visited[orderToVisit[i].ss].size(); j++){
            if(!visited[orderToVisit[i].ss][j]) {
                face.pb(orderToVisit[i].ss);
                dfs(orderToVisit[i].ss, orderToVisit[i].ss, j, graph[orderToVisit[i].ss][j], graph, visited, positions);
            }
        }
    }

    printFaces();

    return 0;
}