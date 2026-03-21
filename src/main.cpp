#include <bits/stdc++.h>
// #include <chrono>
using namespace std;

int main(){
    auto start = chrono::high_resolution_clock::now();

    cout << "Setup working!" << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Execution time: " << duration.count() << " ms" << endl;
    return 0;
}