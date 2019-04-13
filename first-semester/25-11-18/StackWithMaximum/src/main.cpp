#include <iostream>
#import "StackWithMax.h"

using namespace std;

int main() {
    StackWithMax s;
    cout << s.getMax() << std::endl;
    s.push(2);
    cout << s.getMax() << std::endl;
    s.push(3);
    cout << s.getMax() << std::endl;
    s.push(2);
    cout << s.getMax() << std::endl;
    s.push(4);
    cout << s.getMax() << std::endl;
    s.push(4);
    cout << s.getMax() << std::endl;
    s.push(4);
    cout << s.getMax() << std::endl;
    s.pop();
    cout << s.getMax() << std::endl;
    s.pop();
    cout << s.getMax() << std::endl;
    s.pop();
    cout << s.getMax() << std::endl;
    s.pop();
    cout << s.getMax() << std::endl;
    s.pop();
    cout << s.getMax() << std::endl;
    s.pop();
    cout << s.getMax() << std::endl;
    return 0;
}
