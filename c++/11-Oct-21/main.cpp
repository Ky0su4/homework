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

double fourth(double prec, int &n){
    n = 2;
    double previous=4,  current=4./3;
    bool neg = false;
    int i=5;
    while(abs(previous-current)>prec){
        previous = current;
        if (neg) {
            current-=1./i;
            neg = true;
        } else {
            current+=1./i;
            neg = false;
        }
        i+=2;
        n++;
    }
    return current;
}

double fifth(int n){
    double c = 0;
    for (int i = 0; i < n; ++i) {
        int x=rand()%100, y=rand()%100;
        if (x*x+y*y<=10000) c+=1;
    }
    return c/(n-c)*4;
}

int main(){
    std::cout << first() << std::endl << "________" << std::endl;
    second(11);
    int n = 0;
    std::cout << "________" << std::endl << third(1000, 10) << std::endl << "________" << std::endl;
    std::cout << fourth(0.0001, n);
    std::cout << std::endl << "________" << std::endl   << fifth(n);
    return 0;
}
