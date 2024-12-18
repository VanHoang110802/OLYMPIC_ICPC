**assigns()**: assigns values to the container
```cpp
#include <list>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    list<char> characters;

    auto print_list = [&]()
    {
        for (char c : characters)
            cout << c << ' ';
        cout << '\n';
    };

    characters.assign(5, 'a');
    print_list();

    const string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print_list();

    characters.assign({'C', '+', '+', '1', '1'});
    print_list();
}

```

##
**assign_range**: assigns a range of values to the container
