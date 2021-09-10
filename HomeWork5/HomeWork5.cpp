#include <iostream>
#include <string>
#include "GenericPlayer.h"

template<typename T>
class Pair1 {
private:
    T _first;
    T _second;
public:
    Pair1(const T& first, const T& second) : _first(first), _second(second) {};
    const T& first() const { return _first; };
    const T& second() const { return _second; };
};

template<typename T, typename U>
class Pair {
private:
    T _first;
    U _second;
public:
    Pair(const T& first, const U& second) : _first(first), _second(second) {};
    const T& first() const { return _first; };
    const U& second() const { return _second; };
};

template<typename T>
class StringValuePair : public Pair<std::string, T> {
public:
    StringValuePair(const std::string& first, const T& second) : Pair<std::string, T>(first, second) {};
};

void FirstTask() {
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
};

void SecondTask() {
    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
};

void ThirdTask() {
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
};

int main()
{
    FirstTask();
    SecondTask();
    ThirdTask();
    return 0;
}

