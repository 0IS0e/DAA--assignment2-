#include "tree.h"

int main()
{
    Tree<int> t;

    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    cout << "Inorder Traversal: ";
    cout << t;

    if(t.search(60))
        cout << "60 Found\n";
    else
        cout << "60 Not Found\n";

    if(t.search(100))
        cout << "100 Found\n";
    else
        cout << "100 Not Found\n";

    return 0;
}