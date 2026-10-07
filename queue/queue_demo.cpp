#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    Queue<int> q(10);

    q + 10;
    q + 20;
    q + 30;

    q.print_Queue();

    -q;

    q.print_Queue();

    cout << "\nFront Element: " << q.peek();

    return 0;
}