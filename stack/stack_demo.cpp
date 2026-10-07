#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    Stack<int> st(10);
    st+1;
    st+2;
    st+3;
    st+4;
    st+5;
    st.print_Stack();
    -st;
    -st;
    st.print_Stack();
    return 0;
}