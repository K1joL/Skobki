#include <iostream> 
#include <stack> 
#include <string> 
using namespace std;


bool is_correct_sequence(string line) 
{
    stack <char> steck;
    for (char& n : line) 
    {
        switch (n) 
        {
        case '{':
            steck.push('}');
            break;
        case '(':
            steck.push(')');
            break;
        case '[':
            steck.push(']');
            break;
        case '}':
        case ')':
        case ']':
            if (steck.top() != n)
            {
                return false;
            }
            steck.pop();
        }
    }
    return steck.empty();
}

int main() 
{
    setlocale( LC_ALL, "rus" );
    string str;
    cout << "Введите строку: ";
    cin >> str;
    cout << (is_correct_sequence(str) ? "Правильно" : "Неправильно");
}