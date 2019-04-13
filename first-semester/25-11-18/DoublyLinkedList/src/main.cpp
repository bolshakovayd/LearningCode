#include <iostream>
#include "DoublyLinkedList.h"
#include "Commands.h"
#include <map>

int main() {
    DoublyLinkedList test_list;
    std::map<std::string, Command> commands{
            {"push_back",     PUSH_BACK},
            {"push_front",    PUSH_FRONT},
            {"print",         PRINT},
            {"clear",         CLEAR},
            {"empty",         EMPTY},
            {"insert_after",  INSERT_AFTER},
            {"insert_before", INSERT_BEFORE},
            {"front",         FRONT},
            {"back",          BACK},
            {"get",           GET},
            {"set",           SET},
            {"exist",         EXIT}
    };

    std::string input;
    while (std::cin >> input) {
        switch (commands[input]) {
            case PUSH_BACK: {
                float val;
                std::cin >> val;
                test_list.push_back(val);
                break;
            }
            case PUSH_FRONT: {
                float val;
                std::cin >> val;
                test_list.push_front(val);
                break;
            }
            case PRINT: {
                print_doubly_linked_list(test_list);
                break;
            }
            case CLEAR: {
                test_list.clear();
                break;
            }
            case EMPTY: {
                if (test_list.empty()) {
                    std::cout << "List is empty" << std::endl;
                } else {
                    std::cout << "List is not empty" << std::endl;
                }
                break;
            }
            case INSERT_AFTER: {
                unsigned idx;
                float val;
                std::cin >> idx >> val;
                test_list.insert_after(idx, val);
                break;
            }
            case INSERT_BEFORE: {
                unsigned idx;
                float val;
                std::cin >> idx >> val;
                test_list.insert_before(idx, val);
                break;
            }
            case FRONT: {
                std::cout << test_list.front() << std::endl;
                break;
            }
            case BACK: {
                std::cout << test_list.back() << std::endl;
                break;
            }
            case GET: {
                unsigned idx;
                std::cin >> idx;
                std::cout << test_list[idx] << std::endl;
                break;
            }
            case SET: {
                unsigned idx;
                float val;
                std::cin >> idx >> val;
                test_list.set(idx, val);
                break;
            }
            case EXIT: {
                std::cout << "End of testing" << std::endl;
                return 0;
            }
            default: {
                break;
            }
        }
    }

    return 0;
}
