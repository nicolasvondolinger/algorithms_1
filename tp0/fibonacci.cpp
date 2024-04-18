#include <bits/stdc++.h>

using namespace std;

int recursiveFib(int n){
    if (n <= 1) return n;
    return recursiveFib(n - 1) + recursiveFib(n - 2);
}

int main(){

    vector<int> seconds = {15, 30, 45, 60, 75, 90, 105, 120};

    bool valid = true;
    unsigned long int f1 = 0, f2 = 1, n = 0;
    thread iterative([&](){
        unsigned long int aux;
        while(valid){
            aux = f1; f1 = f2; f2 += aux;
            n++;
        }
    });

    cout << "--------- ITERATIVO ---------" << endl << endl;
    for(int i = 0; i < seconds.size(); i++){
        thread time([&]() {
            auto begin = chrono::steady_clock::now();
            this_thread::sleep_for(chrono::seconds(15));
            auto end = chrono::steady_clock::now();
            chrono::duration<double> elapsed_Time = end - begin;
            cout << "Tempo decorrido: " << elapsed_Time.count() << " segundos" << endl;
            
        });
        
        time.join();
        cout << "Quantidade de números calculados em " << seconds[i] <<" segundos: " << n << endl;
    }
    
    valid = false;
    iterative.join();
    valid = true;
    
    cout << endl << endl;
    cout << "--------- RECURSIVO ---------" << endl << endl;

    unsigned long int a = 0;
    thread recursive([&](){
        int aux = 3;
        while(valid){
            recursiveFib(aux);
            a++;
            aux++;
        }
    });

    for(int i = 0; i < seconds.size(); i++){
        thread time([&]() {
            auto begin = chrono::steady_clock::now();
            this_thread::sleep_for(chrono::seconds(15));
            auto end = chrono::steady_clock::now();
            chrono::duration<double> tempoDecorrido = end - begin;
            cout << "Tempo decorrido: " << tempoDecorrido.count() << " segundos" << endl;
            
        });
        
        time.join();
        cout << "Quantidade de números calculados em " << seconds[i] <<" segundos: " << a << endl;
    }

    valid = false;
    recursive.join();

    return 0;
}
