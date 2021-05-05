#include <cstdlib>
#include <string>
#include <iostream>
int main() {
    system("g++ main.cpp -o main -g");
    for (int i = 1; i <= 100; i++) {
        std::cout << "正在测试数据" << i << std::endl;
        std::string name = std::to_string(i);
        std::string todo;
        todo = "./main < input/input" + name + ".in > output/" + name + ".out";
        system(todo.c_str());
        todo = "diff output/" + name + ".out outputSTD/" + name + ".out";
        auto ret = system(todo.c_str());
        if (ret) {
            puts("error");
            return 0;
        } else {
            puts("Accept");
        }
    }
    puts("All Accept");
    return 0;
}