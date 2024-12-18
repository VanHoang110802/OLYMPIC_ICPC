## assign()
assigns values to the container
```cpp
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<char> characters;

    auto print_vector = [&]()
    {
        for (char c : characters)
            cout << c << ' ';
        cout << '\n';
    };

    characters.assign(5, 'a');
    print_vector();

    const string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print_vector();

    characters.assign({'C', '+', '+', '1', '1'});
    print_vector();
}

```

## at()
Returns a reference to the element at specified location pos, with bounds checking. If pos is not within the range of the container, it reports errors that are consequence of attempt to access elements out of defined range.
```cpp
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<char> characters{'a', 'b', 'c', 'd', 'e'};
    int pos = 10;
    if(pos >= characters.size())
    {
        cout << "error";
    }
    else
    {
        characters.at(pos) = 'z';
        cout << characters.at(pos) << "\n"; /// <=> cout << *(characters.begin() + pos) << "\n";
    }
}

```

## operator [ ]
Returns a reference to the element at specified location pos. No bounds checking is performed.
```cpp
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<char> characters{'a', 'b', 'c', 'd', 'e'};
    int i = 1, j = 10;
    cout << characters[i] << "\n" << characters[j];
}

```

## front
Returns a reference to the first element in the container. Calling front on an empty container causes undefined behavior.

```cpp
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<char> characters{'a', 'b', 'c', 'd', 'e'};
    vector<char> characters_2;
    cout << characters.front() << "\n";
    cout << characters_2.front() << "\n"; /// error
}
```
