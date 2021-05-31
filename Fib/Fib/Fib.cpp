#include <iostream>
#include <chrono>

struct Timer {
    std::chrono::time_point<std::chrono::steady_clock> start;
    Timer() :
        start(std::chrono::high_resolution_clock::now()) {};
    ~Timer() {
        std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - start;
        std::cout << "Operation took " << duration.count() * 1000.0f << " milliseconds. \n";
    }
};


int Fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    int a = 1;
    int b = 1;
    int c = 0;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int FibRecursive(int n) {
    if (n <= 1)
        return n;
    return FibRecursive(n - 2) + FibRecursive(n - 1);
}

int main()
{
    int input{ 40 };
    int fib{};

    std::cout << "Fib calc:";
    {
        Timer timer{};
        fib = Fib(input);
    }
    std::cout << "fib(" << input << "): " << fib << "\n";

    std::cout << "Fib calc recursive:";
    {
        Timer timer{};
        fib = FibRecursive(input);
    }
    std::cout << "fib recursive(" << input << "): " << fib << "\n";
}
