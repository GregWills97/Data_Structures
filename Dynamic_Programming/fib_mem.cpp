#include <iostream>

using namespace std;

long long int fib(int n, long long int mem[]);

int main(){
    int n = 1000;
    long long int mem[10000] = {0};
    long long int result = fib(n, mem);

    for(int i = 1; i < n; i++){
        cout << fib(i, mem) << endl;
    }
    return 0;
}

long long int fib(int n, long long int mem[]){

    if(mem[n] != 0){
        return mem[n];
    }
    if(n <= 2){
        return 1;
    }
    else{
        mem[n] = fib(n-1, mem) + fib(n-2, mem);
        return mem[n];
    }
}
