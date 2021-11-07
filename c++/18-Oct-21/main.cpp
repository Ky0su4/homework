#include "iostream"
#include "string"
#include "map"

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

std::string second(int x, int base){
    std::string answer;
    for (char tmp=x%base; x!=0 ; x/=base, tmp=x%base) {
        if (tmp<=9) tmp +='0';
        else tmp+='A'-10;
        answer = tmp+answer;
    }
    return answer;
}


std::string Rim[]={
        "I",    "V",    // 1        5
        "X",    "L",    // 10       50
        "C",    "D",    // 100      500
        "M",    "V^",   // 1000     5000
        "X^",   "L^",   // ...      ...
        "C^",   "D^",
        "M^",   "V^^",
        "X^^",  "L^^",
        "C^^",  "D^^",
        "M^^",  "V^^^",
        "X^^^", "L^^^",
        "C^^^", "D^^^",
        "M^^^", "V^^^^",
        "X^^^^", "L^^^^",
        "C^^^^", "D^^^^",
        "M^^^^", "V^^^^^",
        "X^^^^^", "L^^^^^",
        "C^^^^^", "D^^^^^",
        "M^^^^^", "V^^^^^^",
        "X^^^^^^"
};

std::string third(unsigned long long int x, int power = 0){
    std::string answer;
    int flag = 0;
    int tmp = x % 10;
    if ((tmp > 4)) {
        tmp -=5;
        flag = 1;
    }
    if (tmp<4){
        if (flag) answer+=Rim[power*2+1];
        for (int i = 0; i < tmp; ++i) answer += Rim[power*2];
    }
    else answer += Rim[power*2] + Rim[power*2+1+flag];
    if(x/10!=0) answer = third(x/10, power+1) + answer;
    return answer;
}


int main(){
    std::cout << "\nMax:\t" << first(27) << std::endl;
    std::cout << second(11, 16) << std::endl;
    std::cout << ULLONG_MAX << ' ' << third(ULLONG_MAX) << "\t";

    return 0;
}

