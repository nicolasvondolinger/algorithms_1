#include <bits/stdc++.h>
    using namespace std;
     
    #define _ ios_base::sync_with_stdio(0);cin.tie(0);
    #define rep(i,x,n) for(int i=x;i<n;i++)
    #define repr(i,n,x) for(int i=n;i>=x;i--)
    #define forr(v) for(auto& x: v)
    #define all(a) (a).begin(), (a).end()
    #define endl '\n'
    #define ff first
    #define ss second
    #define pb push_back
     
    typedef long long ll;
    typedef pair<int,int> ii;
    typedef vector<int> vi;
    typedef vector<ll> vl;
     
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3fll;
     
    void DBG() {
        cerr << "]" << endl;
    }
     
    void DBGC() {
        cerr << "]" << endl;
    }
     
    template<class H, class... T> void DBG(H h, T... t) {
        cerr << to_string(h);
        if(sizeof...(t)) cerr << ", ";
        DBG(t...);
    }
     
    template<class H, class... T> void DBGC(H h, T... t) {
        for(auto& x: h) cerr << x << " ";
        if(sizeof...(t)) cerr << "], [ ";
        DBGC(t...);
    }
     
    #ifndef _DEBUG
    #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
    #else
    #define dbg(...) 0
    #define dbgc(...) 0
    #endif
     

    int partition(vector<int>& v, int low, int high){
        int pivot = v[high];
        int i = (low - 1);

        for(int j = low; j <= high; j++){
            if(v[j] < pivot){
                i++;
                swap(v[i], v[j]);
            }
        }
        swap(v[i+1], v[high]);
        return i+1;
    }

    void quickSort(vector<int>& v, int low, int high){
        if(low < high){
            int p = partition(v, low, high);

            quickSort(v, low, p -1);
            quickSort(v, p+1, high);
        }
    }

    void insertionSort(vector<int>& v, int low, int high) {
        for (int i = low + 1; i <= high; ++i) {
            int key = v[i];
            int j = i - 1;

            while (j >= low && v[j] > key) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = key;
        }
    }

    void quickSortWithInsertion(vector<int>& v, int low, int high) {
        if (low < high) {
            if (high - low + 1 <= 30) {
                insertionSort(v, low, high);
            } else {
                int p = partition(v, low, high);

                quickSortWithInsertion(v, low, p - 1);
                quickSortWithInsertion(v, p + 1, high);
            }
        }
    }

    void iterativeQuickSort(vector<int>& arr, int low, int high) {
        stack<pair<int, int>> stk;
        stk.push(make_pair(low, high));

        while (!stk.empty()) {
            low = stk.top().first;
            high = stk.top().second;
            stk.pop();

            int pivot = partition(arr, low, high);

            // Se existem elementos à esquerda do pivô, empilhe a submatriz esquerda
            if (pivot - 1 > low)
                stk.push(make_pair(low, pivot - 1));

            // Se existem elementos à direita do pivô, empilhe a submatriz direita
            if (pivot + 1 < high)
                stk.push(make_pair(pivot + 1, high));
        }
    }

    void iterativeQuickSortWithInsertion(vector<int> arr, int low, int high) {
        stack<pair<int, int>> stk;
        stk.push(make_pair(low, high));

        while (!stk.empty()) {
            low = stk.top().first;
            high = stk.top().second;
            stk.pop();

            // Se a submatriz tem no máximo 30 elementos, usa ordenação por inserção
            if (high - low + 1 <= 30) {
                insertionSort(arr, low, high);
                continue;
            }

            int pivot = partition(arr, low, high);

            // Se existem elementos à esquerda do pivô, empilhe a submatriz esquerda
            if (pivot - 1 > low)
                stk.push(make_pair(low, pivot - 1));

            // Se existem elementos à direita do pivô, empilhe a submatriz direita
            if (pivot + 1 < high)
                stk.push(make_pair(pivot + 1, high));
        }
    }

    int main (){

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000); // Altere os limites conforme necessário

        // Gerar 50 conjuntos de 10000 números aleatórios
        const int num_sets = 50;
        const int set_size = 10000;

        vector<vector<int>> sets(num_sets, vector<int>(set_size));
        vector<double> times_recursive, times_recursive_insertion, times_iterative, times_iterative_insertion;

        for (int i = 0; i < num_sets; ++i) {
            for (int j = 0; j < set_size; ++j) {
                sets[i][j] = dis(gen);
            }
        }

        for (int i = 0; i < num_sets; ++i) {
        vector<int> temp = sets[i];
        
        auto start = chrono::high_resolution_clock::now();
        quickSort(temp, 0, set_size - 1);
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        times_recursive.push_back(time_taken);

        temp = sets[i];
        start = chrono::high_resolution_clock::now();
        quickSortWithInsertion(temp, 0, set_size - 1);
        end = chrono::high_resolution_clock::now();
        time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        times_recursive_insertion.push_back(time_taken);

        temp = sets[i];
        start = chrono::high_resolution_clock::now();
        iterativeQuickSort(temp, 0, set_size - 1);
        end = chrono::high_resolution_clock::now();
        time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        times_iterative.push_back(time_taken);

        temp = sets[i];
        start = chrono::high_resolution_clock::now();
        iterativeQuickSortWithInsertion(temp, 0, set_size - 1);
        end = chrono::high_resolution_clock::now();
        time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        times_iterative_insertion.push_back(time_taken);
    }

    // Calcular média e desvio padrão para cada estratégia de ordenação
    auto calculate_statistics = [](vector<double>& times) {
        double mean = accumulate(times.begin(), times.end(), 0.0) / times.size();
        double sq_sum = inner_product(times.begin(), times.end(), times.begin(), 0.0);
        double stdev = sqrt(sq_sum / times.size() - mean * mean);
        return make_pair(mean, stdev);
    };

    double mean_recursive, stdev_recursive;
    tie(mean_recursive, stdev_recursive) = calculate_statistics(times_recursive);

    double mean_recursive_insertion, stdev_recursive_insertion;
    tie(mean_recursive_insertion, stdev_recursive_insertion) = calculate_statistics(times_recursive_insertion);

    double mean_iterative, stdev_iterative;
    tie(mean_iterative, stdev_iterative) = calculate_statistics(times_iterative);

    double mean_iterative_insertion, stdev_iterative_insertion;
    tie(mean_iterative_insertion, stdev_iterative_insertion) = calculate_statistics(times_iterative_insertion);


    // Imprimir os resultados
    cout << "Resultados:\n";
    cout << "(i) Quicksort recursivo puro:\n";
    cout << "   Média de tempo: " << mean_recursive << " ms\n";
    cout << "   Desvio padrão: " << stdev_recursive << " ms\n";
    cout << "(ii) Quicksort recursivo & Ordenação por inserção:\n";
    cout << "   Média de tempo: " << mean_recursive_insertion << " ms\n";
    cout << "   Desvio padrão: " << stdev_recursive_insertion << " ms\n";
    cout << "(iii) Quicksort não recursivo puro:\n";
    cout << "   Média de tempo: " << mean_iterative << " ms\n";
    cout << "   Desvio padrão: " << stdev_iterative << " ms\n";
    cout << "(iv) Quicksort não recursivo & Ordenação por inserção:\n";
    cout << "   Média de tempo: " << mean_iterative_insertion << " ms\n";
    cout << "   Desvio padrão: " << stdev_iterative_insertion << " ms\n";



        return 0;
    }