#include "iostream"
#include "string"

int first(int x){
    static int max = x;
    std::cout << x << "\t";
    if (max<x) max = x;
    if (x==1) return 1;
    if (x%2==0) x/=2;
    else x=x*3+1;
    int result = first(x);
    return max;
}

//std::string

int main(){
    std::cout << "\nMax:\t" << first(27);
    return 0;
}

