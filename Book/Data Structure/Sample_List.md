## Sample
Input:
```
In the first line the N number of commands is given. (1 ≤ N ≤ 1,000,000)
From the second line over N number of lines one of the following commands is entered.
push x: Add x to the end of the list.
get x: Output the xth element in the list.
size: Output the list size.
count x: Output the number of x on the list.
clear: Empty the list.

10
size
push 1
push 2
get 0
size
push 1
get 2
count 1
clear
count 1

```

Output:
```
According to each command express the output value in one line.

0
1
2
1
2
0
```

## C
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* next;
    int value;
} node;

typedef struct list
{
    node* head;
    node* last;
    int size;
} list;

void Init_list(list* mylist);
void Push_back(list* mylist, int value);
int Get_idx(list* mylist, int idx);
int Count_target(list* mylist, int target);
void Clear_list(list* mylist);
void Free_node(node* current_node);

int main()
{
    int n;
    scanf("%d", &n);

    list mylist;
    Init_list(&mylist);
    while(n--)
    {
        char command[10];
        scanf("%s", command);

        // push, get, size, count, clear
        if(command[0] == 'p')
        {
            int value;
            scanf("%d", &value);
            Push_back(&mylist, value);
        }
        else if(command[0] == 'g')
        {
            int idx;
            scanf("%d", &idx);
            printf("%d\n", Get_idx(&mylist, idx));
        }
        else if(command[0] == 's')
        {
            printf("%d\n", mylist.size);
        }
        else if(command[1] == 'o')
        {
            int target;
            scanf("%d", &target);
            printf("%d\n", Count_target(&mylist, target));
        }
        else
        {
            Clear_list(&mylist);
        }
    }

    return 0;
}

void Init_list(list* mylist)
{
    mylist->head = (node*)malloc(sizeof(node));
    mylist->head->next = NULL;
    mylist->last = mylist->head;
    mylist->size = 0;
}

void Push_back(list* mylist, int value)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    mylist->last->next = new_node;
    mylist->last = new_node;
    mylist->size++;
}

int Get_idx(list* mylist, int idx)
{
    node* pre_node = mylist->head;
    while(idx--)
    {
        pre_node = pre_node->next;
    }
    return pre_node->next->value;
}

int Count_target(list* mylist, int target)
{
    int count = 0;
    for(node* pre_node = mylist->head; pre_node->next != NULL; pre_node = pre_node->next)
    {
        if(pre_node->next->value == target)
        {
            count++;
        }
    }
    return count;
}

void Clear_list(list* mylist)
{
    Free_node(mylist->head);
    Init_list(mylist);
}

void Free_node(node* current_node)
{
    if(current_node->next != NULL)
    {
        Free_node(current_node->next);
    }
    free(current_node);
}

```

## C++
```cpp
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    list<int> mylist;
    for(int i = 1; i <= n; ++i)
    {
        string command;
        cin >> command;

        // push, get, size, count, clear
        if(command[0] == 'p')
        {
            int value;
            cin >> value;
            mylist.push_back(value);
        }
        else if(command[0] == 'g')
        {
            int idx;
            cin >> idx;
            list<int>::iterator it = mylist.begin();
            while(idx--)
            {
                it++;
            }
            cout << (*it) << "\n";
        }
        else if(command[0] == 's')
        {
            cout << mylist.size() << "\n";
        }
        else if(command[1] == 'o')
        {
            int target, cnt = 0;
            cin >> target;
            for(list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
            {
                if(*it == target)
                {
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
        else
        {
            mylist.clear();
        }
    }

    return 0;
}
```
