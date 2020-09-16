#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Node{
    public:
        Node* next;
        int value;

        Node(Node* n, int v){
            next = n;
            value = v;
        }

        string to_str(){
            if(next != nullptr){
                return to_string(value) + "->" + next->to_str();
            }
            return to_string(value);
        }
};


int AddTwoList(Node* l1, Node* l2){
    if (l1 == nullptr && l2 == nullptr){
        return 0;
    } else if (l1 == nullptr && l2 != nullptr){
        return l2->value + 10*AddTwoList(nullptr, l2->next);
    } else if (l2 == nullptr && l1 != nullptr){
        return l1->value + 10*AddTwoList(l1->next, nullptr);
    } else {
        return l1->value + l2->value + 10*AddTwoList(l1->next, l2->next);
    }
}

int main(){
    Node* l1 = new Node(nullptr, 2);    
    l1->next = new Node(nullptr, 4);
    l1->next->next = new Node(nullptr, 3);

    Node* l2 = new Node(nullptr, 5);    
    l2->next = new Node(nullptr, 6);
    l2->next->next = new Node(nullptr, 4);

    printf("%s\n+\n", l1->to_str().c_str());
    printf("%s\n=\n", l2->to_str().c_str());

    printf("%d", AddTwoList(l1, l2));    
}
