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

## begin()
Returns an iterator to the first element of the list. If the list is empty, the returned iterator will be equal to end().
```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <list>
 
int main()
{
    std::list<int> nums{1, 2, 4, 8, 16};
    std::list<std::string> fruits{"orange", "apple", "raspberry"};
    std::list<char> empty;
 
    std::for_each(nums.begin(), nums.end(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
 
    std::cout << "Sum of nums: " << std::accumulate(nums.begin(), nums.end(), 0) << '\n';
 
    if (!fruits.empty()) std::cout << "First fruit: " << *fruits.begin() << '\n';
 
    if (empty.begin() == empty.end()) std::cout << "list 'empty' is indeed empty.\n";
}
```

## end()
Returns an iterator to the element following the last element of the list. This element acts as a placeholder; attempting to access it results in undefined behavior.
```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <list>
 
int main()
{
    std::list<int> nums{1, 2, 4, 8, 16};
    std::list<std::string> fruits{"orange", "apple", "raspberry"};
    std::list<char> empty;
 
    std::for_each(nums.begin(), nums.end(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
 
    std::cout << "Sum of nums: " << std::accumulate(nums.begin(), nums.end(), 0) << '\n';
 
    if (!fruits.empty()) std::cout << "First fruit: " << *fruits.begin() << '\n';
 
    if (empty.begin() == empty.end()) std::cout << "list 'empty' is indeed empty.\n";
}
```
