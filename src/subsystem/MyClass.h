#pragma once

template <typename T>
class MyClass {
public:
    MyClass(T&& value) : _value(value) {}
    inline const T& get() const { return _value; }

private:
    T _value;
};