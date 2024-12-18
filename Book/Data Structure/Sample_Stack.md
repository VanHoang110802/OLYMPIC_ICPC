## Sample
Input:
```
In the first line the N number of commands is given. (1 ≤ N ≤ 1,000,000)
From the second line over N number of lines enter the commands below.
push x: Insert x into the stack.
pop: Delete the element that was inserted last.
size: Output the queue size.
top: Output the foremost factor value of the queue.

8
size
push 4
push 3
top
size
pop
top
size
```

output
```
Output the value depending on the order of each command.

0
3
2
4
1
```

## C
```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
struct stack_node
{
    int data;
    struct stack_node* next;
};

struct stack
{
    struct stack_node* top;
    int sz;
};
void stack_init(struct stack *st)
{
    st->sz = 0;
    st->top = 0;
}
int stack_size(struct stack *st)
{
    return st->sz;
}
bool stack_empty(struct stack *st)
{
    return stack_size(st) == 0;
}
void stack_push(struct stack *st,int val)
{
    struct stack_node *newNode = (struct stack_node*)malloc(sizeof(struct stack_node));
    newNode->data = val;
    newNode->next = st->top;
    st->top = newNode;
    st->sz++;
}
void stack_pop(struct stack *st)
{
    assert(!stack_empty(st));
    struct stack_node *nextHead = st->top->next;
    free(st->top);
    st->top = nextHead;
    st->sz--;
}
int stack_top(struct stack *st)
{
    assert(!stack_empty(st));
    return st->top->data;
}

int N, val;
char cmd[16];
int main()
{
    struct stack st;
    scanf("%d", &N);
    stack_init(&st);
    for (int i = 0; i < N; i++)
    {
        scanf(" %s", cmd);
        if (cmd[0] == 's')
        {
            printf("%d\n", stack_size(&st));
        }
        else if (cmd[0] == 'p')
        {
            if (cmd[1] == 'u')
            {
                scanf("%d", &val);
                stack_push(&st, val);
            }
            else if (cmd[1] == 'o')
            {
                stack_pop(&st);
            }
        }
        else if (cmd[0] == 't')
        {
            printf("%d\n", stack_top(&st));
        }
    }
    return 0;
}
```

## C++
```cpp
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int N, val;
string cmd;
int main()
{
    stack<int> st;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd;
        if (cmd[0] == 's')
        {
            cout << st.size() << endl;
        }
        else if (cmd[0] == 'p')
        {
            if (cmd[1] == 'u')
            {
                cin >> val;
                st.push(val);
            }
            else if (cmd[1] == 'o')
            {
                st.pop();
            }
        }
        else if (cmd[0] == 't')
        {
            cout << st.top() << endl;
        }
    }

    return 0;
}
```
