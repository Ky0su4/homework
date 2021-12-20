#include <iostream>
#include <map>
#include "string"
#include "vector"

struct date{
    int day;
    int month;
    int year;
};

int dday(date dt){
    int a = (14-dt.month)/12;
    int y = dt.year;
    int m = dt.month+12*a-3;
    return (dt.day+(153*m+2)/5+365*y+y/4-32083)%7;
}

int first(date dt, int lookingFor){
    for (int tmp = -1; lookingFor!=tmp; dt.year=dt.year+1) tmp = dday(dt);
    return dt.year;
}

int second(int day, int lookingfor){
    int c = 0;
    for (date i = {day, 1, 1901}; i.year < 2001; ) {
        if (dday(i)==lookingfor) c++;
        i.month++;
        if (i.month>12) {
            i.month-=12;
            i.year++;
        }
    }
    return c;
}

int third(int room){
    int i = 1;
    for (int sum = 0;  room>=sum; ++i) sum += i;
    return i-1;
}


std::map<int, std::string> russian{
        {0,     "ноль"},
        {1,     "один"},
        {2,     "два"},
        {3,     "три"},
        {4,     "четыре"},
        {5,     "пять"},
        {6,     "шесть"},
        {7,     "семь"},
        {8,     "восемь"},
        {9,     "девять"},

        {10,    "десять"},
        {11,    "одиннадцать"},
        {12,    "двенадцать"},
        {13,    "тринадцать"},
        {14,    "четырнадцать"},
        {15,    "пятнадцать"},
        {16,    "шестнадцать"},
        {17,    "семнадцать"},
        {18,    "восемнадцать"},
        {19,    "девятнадцать"},

        {20,    "двадцать"},
        {30,    "тридцать"},
        {40,    "сорок"},
        {50,    "пятьдесят"},
        {60,    "шестьдесят"},
        {70,    "семьдесят"},
        {80,    "восемьдесят"},
        {90,    "девяносто"},

        {100,    "сто"},
        {200,    "двести"},
        {300,    "тристо"},
        {400,    "четыреста"},
        {500,    "пятьсот"},
        {600,    "шестьсот"},
        {700,    "семьсот"},
        {800,    "восемьсот"},
        {900,    "девятьсот"}
};

std::string genPart(int input, bool f=false){
    std::string answer;
    if (input/100!=0){
        answer += russian[input/100*100] + " ";
    }
    if ((input%100>10)&&(input%100<20)){
        answer += russian[input%100] + " ";
    } else {
        if (input/10%10!=0)
        {
            answer += russian[input/10%10*10] + " ";
        }

        if ((input%10==1)&&f) answer += "одна ";
        else
        if ((input%10==2)&&f) answer += "две ";
        else
        if (input%10!=0)
        {

            answer += russian[input%10] + " ";
        }
    }
    answer.erase(answer.end()-1);
    return answer;
}

std::string fourth(int input) {
    int a[3];
    std::string answer;
    for (int i = 0; i < 3; ++i) {
        a[i] = input%1000;
        input/=1000;
    }

    // По-хорошему, нужно выделить в отдельную функцию (повтор кода)

    if (a[2]!=0){
        answer+=genPart(a[2]);
        if ((a[2]%100>10)&&(a[2]%100<20)) answer+=" миллионов ";
        else if (a[2]%10==1) answer+=" миллион ";
        else if ((a[2]%10>1)&&(a[2]%10<5)) answer+=" миллиона ";
        else answer+=" миллионов ";
    }

    if (a[1]!=0){
        answer+=genPart(a[1], true);
        if ((a[1]%100>10)&&(a[1]%100<20)) answer+=" тысяч ";
        else if (a[1]%10==1) answer+=" тысяча ";
        else if ((a[1]%10>1)&&(a[1]%10<5)) answer+=" тысячи ";
        else answer+=" тысяч ";
    }

    if (a[0]!=0){
        answer+=genPart(a[0]);
    } else if ((a[1]==0)&&(a[2]==0)) answer+=russian[0];
    return answer;
}

int fifth(std::vector<int> vector){
    int N = vector.size();
    for (int i = 0; i < N; ++i) {
        if (vector[i]!=N){
            std::swap(vector[vector[i]], vector[i]);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (vector[i]!=i) return i;
    }
    return N;


}

int main() {
    std::cout << first({25, 02, 2072}, 1) << std::endl;
    std::cout << second(13, 4) << std::endl;
    std::cout << third(420) << std::endl;
    std::cout << fourth(420609301) << std::endl;
    std::cout << fifth({0,1,2,3,5,4,9,8,7});
    return 0;
}
