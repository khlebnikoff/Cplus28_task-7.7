#include <cassert> 
#include <iostream>
#include<exception>
#include<climits>
#include<array>
using namespace std;

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    int pr = 0;
    IntArray() = default;
    IntArray(int length);
    IntArray(const IntArray& a);
    ~IntArray();
    void erase();
    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength() const;
    int& operator[](int index);
    IntArray& operator=(const IntArray& a);
    //
    void printResult();
    void getElementbyIndex(int index);
    void findElementbyValue(int value);
    };

class SH :public exception
{
    int _e;
public:
    SH(int e = 0) : _e(e) {};
    
    void ShowThrow();

};