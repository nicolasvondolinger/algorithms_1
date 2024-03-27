#include <bits/stdc++.h>

using namespace std;

int recursiveFib(int n){
    if (n <= 1) return n;
    return recursiveFib(n - 1) + recursiveFib(n - 2);
}

int iterativeFib(int n){
    
    /*
    vector<int> ans; ans.push_back(1), ans.push_back(1);
    for(int i = 2; i < n; i++){
        ans.push_back(ans[i - 1] + ans[i - 2]);
    }
    return ans[n - 1];
    */

    int a = 1, b = 1, c;
    if(n == 0) return a;
    for (int i = 2; i < n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return b;
    
}

int main (){

    const vector<int> time_limits = {15, 30, 45, 60, 75, 90, 105, 120};

    cout << "Tempo Limite (s)\t| Recursivo\t| Iterativo\n";
    cout << "------------------------------------------------\n";

    for (int t : time_limits) {
        auto inicio = std::chrono::steady_clock::now();

        unsigned long long n_recursivo = 0;
        unsigned long long fib_recursivo = 0;

        while (true) {
            auto agora = std::chrono::steady_clock::now();
            auto diferenca = std::chrono::duration_cast<std::chrono::seconds>(agora - inicio).count();
            
            if (diferenca >= t) break;

            fib_recursivo = recursiveFib(n_recursivo);
            
            ++n_recursivo;
            
        }

        inicio = std::chrono::steady_clock::now();

        unsigned long long n_iterativo = 0;
        unsigned long long fib_iterativo = 0;

        while (true) {
            auto agora = std::chrono::steady_clock::now();
            auto diferenca = std::chrono::duration_cast<std::chrono::seconds>(agora - inicio).count();
            
            if (diferenca >= t) break;
            
            fib_iterativo = iterativeFib(n_iterativo);

            ++n_iterativo;
        }

        

        std::cout << t << "\t\t\t| " << n_recursivo << "\t\t| " << n_iterativo << "\n";
    }

    /*
    int n; cin >> n;

    cout << recursiveFib(n) << endl;
    cout << iterativeFib(n) << endl;
    */

    return 0;
}