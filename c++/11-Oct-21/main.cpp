#include <iostream>
#include <math.h>

int first(){
    int c = 0;
    for (int i = 0; i < 1000000; ++i) {
        for (int j = 0; j < 1000000; ++j) {
            if (i*i+j*j<1000000) c++;
            else break;
        }
    }
    return c;
}

void second(int n){
    for (int i = 0; i <= n/2; ++i) {
        std::cout << n-(i*2) << "\t" << i << std::endl;
    }
}


double SSin(double x, int n){
    for (int i = 0; i < n; ++i) {
        x = sin(x);
    }
    return x;
}

double third(double x, int n){
    double r=0;
    for (int i = 0; i < n; ++i) {
        r+= SSin(x, i);
    }
    return r;
}

int main(){
    std::cout << first() << std::endl << "________" << std::endl;
    second(11);
    std::cout << "________" << std::endl << third(1000, 10) << std::endl;
    return 0;
}
