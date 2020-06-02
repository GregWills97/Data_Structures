#include <iostream>

using namespace std;

int bottom_up(int n, long long int bot[]);

int main(){
    int n = 92;
    long long int bot[1000] = {0};
    long long int result = bottom_up(n, bot);

    for(int i = 1; i <= n; i++){
        long long int result = bottom_up(i, bot);
        cout << result << endl;
    }
    
    return 0;
}

int bottom_up(int n, long long int bot[]){
    if(n <= 2){
        return 1;
    }
    else{

        bot[1] = 1;
        bot[2] = 1;

        for(int i = 3; i <= n; i++){
            bot[i] = bot[i-1] + bot[i-2];
        }
        return bot[n];
    }
}
