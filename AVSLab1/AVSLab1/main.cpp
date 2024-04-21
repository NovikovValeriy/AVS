#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include "GraphMaker.h"

double calculateY(double x) {
    double result;
    double eight = 8;
    double four = 4;
    x = abs(x);
    
    //pi^2/8
    __asm {
        finit
        fldpi
        fmul st, st(0)
        fdiv eight
    }

    //pi/4*x
    __asm {
        fldpi
        fdiv four
        fmul x
    }

    //pi^2/8-pi/4*x
    __asm {
        fsubr st, st(1)
        fstp result
    }

    return result;
}

double calculateX(double x, int n) {
    double result = 0;
    double two = 2;
    double one = 1;
    double temp = 0;

    //2k - 1
    __asm {
        finit
        fild n
        fmul two
        fsub one
        fst temp
    }

    //cos[(2k - 1) * x]
    __asm {
        fmul x
        fcos
    }
    //(2k - 1)^2
    __asm {
        fld temp
        fmul temp
    }

    //cos[(2k - 1)] * x / (2k - 1)^2
    __asm {
        fdivr st, st(1)
    }

    __asm {
        fstp result
    }

    return result;
}

int main() {
    double eps = 0.00000000001;
    double a = -3.1, b = 3.2, h = 0.1;
    std::vector<double> iterations;
    std::vector<double> time;
    GraphMaker<double> graph = GraphMaker<double>();
    std::cin.get();
    for (; a <= b; a += h) {
        if (a > 0 && a < 0.01) continue;
        auto start = std::chrono::high_resolution_clock::now();
        int i = 1;
        double X = calculateX(a, i);
        double Y = calculateY(a);
        double ans = X - Y;
        while (abs(ans) > eps)
        {
            i++;
            X += calculateX(a, i);
            ans = X - Y;
            if (i > 500000) break;
        }
        auto end = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        iterations.push_back(i);
        time.push_back(duration);
        std::cout << "\n\na = " << a << "\nY = " << Y << "\nX = " << X << "\ni = " << i << "\nDuration: " << duration << " microseconds";
    }
    graph.yPoints = time;
    graph.xPoints = iterations;
    graph.PrintGraph("Header");
    return 0;
}