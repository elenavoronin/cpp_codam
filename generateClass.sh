#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 ClassName"
    exit 1
fi

CLASS_NAME=$1
HEADER_FILE="$CLASS_NAME.hpp"
SOURCE_FILE="$CLASS_NAME.cpp"

# Create the header file
cat <<EOF > $HEADER_FILE
#pragma once

#include <string>
#include <exception>
#include <iostream>

class $CLASS_NAME {
    private:
        const std::string   _name;
        int                 _value;
    public:
        $CLASS_NAME();
        $CLASS_NAME(const std::string& name, int value);
        $CLASS_NAME(const $CLASS_NAME& copy);
        $CLASS_NAME& operator=(const $CLASS_NAME& copy);
        ~$CLASS_NAME();

        std::string getName() const;
        int getValue() const;
        void setValue(int value);
        void increment();
        void decrement();

        class ValueTooHighException: public std::exception {
            public:
                const char* what() const throw() {
                    return "Value too high";
                }
        };
        
        class ValueTooLowException: public std::exception {
            public:
                const char* what() const throw() {
                    return "Value too low";
                }
        };
};

std::ostream& operator<<(std::ostream& os, const $CLASS_NAME& obj);
EOF

# Create the source file
cat <<EOF > $SOURCE_FILE
#include "$HEADER_FILE"

$CLASS_NAME::$CLASS_NAME() : _name("Default"), _value(0) {}

$CLASS_NAME::$CLASS_NAME(const std::string& name, int value) : _name(name), _value(value) {}

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME& copy) : _name(copy._name), _value(copy._value) {}

$CLASS_NAME& $CLASS_NAME::operator=(const $CLASS_NAME& copy) {
    if (this != &copy) {
        const_cast<std::string&>(_name) = copy._name;
        _value = copy._value;
    }
    return *this;
}

$CLASS_NAME::~$CLASS_NAME() {}

std::string $CLASS_NAME::getName() const {
    return _name;
}

int $CLASS_NAME::getValue() const {
    return _value;
}

void $CLASS_NAME::setValue(int value) {
    _value = value;
}

void $CLASS_NAME::increment() {
    if (_value >= 100) throw ValueTooHighException();
    _value++;
}

void $CLASS_NAME::decrement() {
    if (_value <= 0) throw ValueTooLowException();
    _value--;
}

std::ostream& operator<<(std::ostream& os, const $CLASS_NAME& obj) {
    os << obj.getName() << " has value " << obj.getValue();
    return os;
}
EOF

echo "Files $HEADER_FILE and $SOURCE_FILE created successfully."