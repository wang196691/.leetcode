#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main()
{
    cout << "hello" << endl;
    unordered_set<char> u_set;
    unordered_multiset <char> u_mulset;
    unordered_map<int, int> u_map;
    // u_map.count();
    char a = 'a';
    u_set.find(a);
    cout << u_set.count(a) << endl;
    u_set.insert(a);
    if (u_set.contains(a))
        cout << u_set.count(a) << endl;
    u_set.insert(a);
    cout << u_set.count(a) << endl;
    return 0;
}