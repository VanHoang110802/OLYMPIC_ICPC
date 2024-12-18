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

## front()
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

## back()
Returns a reference to the last element in the container. Calling back on an empty container causes undefined behavior.
```cpp
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<char> characters{'a', 'b', 'c', 'd', 'e'};
    vector<char> characters_2;
    cout << characters.back() << "\n";
    cout << characters_2.back() << "\n";
}
```

## begin()
Returns an iterator to the first element of the vector. If the vector is empty, the returned iterator will be equal to end().
```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums{1, 2, 4, 8, 16};
    vector<string> fruits{"orange", "apple", "raspberry"};
    vector<char> empty;

    for_each(nums.begin(), nums.end(), [](const int n)
    {
        cout << n << ' ';
    });
    cout << '\n';

    cout << "Sum of nums: " << accumulate(nums.begin(), nums.end(), 0) << '\n';

    if (!fruits.empty())
    {
        cout << "First fruit: " << *fruits.begin() << '\n';
    }

    if (empty.begin() == empty.end())
    {
        cout << "vector 'empty' is indeed empty.\n";
    }
}
```

## end()
Returns an iterator to the element following the last element of the vector. This element acts as a placeholder; attempting to access it results in undefined behavior.
```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums{1, 2, 4, 8, 16};
    vector<string> fruits{"orange", "apple", "raspberry"};
    vector<char> empty;

    for_each(nums.begin(), nums.end(), [](const int n)
    {
        cout << n << ' ';
    });
    cout << '\n';

    cout << "Sum of nums: " << accumulate(nums.begin(), nums.end(), 0) << '\n';

    if (!fruits.empty())
    {
        cout << "First fruit: " << *fruits.begin() << '\n';
    }

    if (empty.begin() == empty.end())
    {
        cout << "vector 'empty' is indeed empty.\n";
    }
}
```

## empty()
Checks if the container has no elements, i.e. whether begin() == end().
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

    numbers.push_back(42);
    cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}
```

## size()
Returns the number of elements in the container, i.e. std::distance(begin(), end()).
```cpp
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;
    if(nums.size()) cout << "vector not empty!";
    else cout << "vector empty!";
}
```

## clear()
Erases all elements from the container. After this call, size() returns zero. Invalidates any references, pointers, and iterators referring to contained elements. Any past-the-end iterators are also invalidated.
```cpp
#include <iostream>
#include <vector>
using namespace std;

void print_info(string s, const vector<int>& v)
{
    cout << s << "{ ";
    for (const auto& value : v)
        cout << value << ' ';
    cout << "}\n";
    cout << "Size=" << v.size() << ", Capacity=" << v.capacity() << '\n';
}

int main()
{
    vector<int> container{1, 2, 3};
    print_info("Before clear: ", container);
    container.clear();
    print_info("After clear: ", container);
}
```

## insert()
Inserts elements at the specified location in the container.
```cpp
#include <iostream>
#include <vector>
using namespace std;

#define var auto

void print_info(const vector<int>& v)
{
    cout << "[ ";
    for (var value : v)
        cout << value << " ";
    cout << "]\n";
}

int main()
{
    vector<int> ner(1, 1);
    var pos = ner.begin();
    print_info(ner);

    ner.insert(pos, 2);
    print_info(ner);

    ner.insert(next(ner.begin(), ner.size()), 3); /// next: Return the nth successor (or -nth predecessor if n is negative) of iterator it.
    print_info(ner);
}
```

## emplace()

## erase()

## push_back

## emplace_back()

## pop_back()

## resize()

## swap()

