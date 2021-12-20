#include <iostream>
#include "cmath"
#include "random"

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main(int argc, char *argv[]) {
    int a = argc;
    double prec;
    do {
        if (a == 1) {
            std::cout << "Enter prec (precision)\t";
            std::cin >> prec;
            std::cout << std::endl;
        } else {
            prec = std::stoi(argv[1]);
        }
        a = 0;
    } while (prec<=0);

    double pi_formula, previous = 0;

    pi_formula = 4;
    int i;
    for (i = 1; fabs(previous-pi_formula)>prec; ++i) {
        previous = pi_formula;
        int tmp = -1;
        if (i%2==0) tmp = 1;
        pi_formula += 4. * tmp/(2.*i+1.);
    }
    std::cout << "Formula: \t" << pi_formula << std::endl;

    srand(time(0));
    int points = 0;
    for (int j = 0; j < i; ++j) {
        double x = fRand(0, 1);
        double y = fRand(0, 1);
        if (x*x+y*y<=1) points++;
    }

    double pi_random = 4.*(((double)points)/(i-points));
    std::cout << "Random: \t" << pi_random << std::endl;

    std::cout << "Delta: \t\t" << fabs(pi_formula-pi_random) << std::endl;


    return 0;
}
