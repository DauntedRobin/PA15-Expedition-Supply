#ifndef SUPPLY_H
#define SUPPLY_H

#pragma once
#include <string>

class Supply {
private:
    
    std::string name;
    int quantity;
    int minimum;

public:
    Supply(const std::string& name, int quantity, int minimum);

    void add(int amount);
    void use(int amount);
    bool isLow() const;
    std::string getName() const;
    int getQuantity() const;
    int getMinimum() const;
};  

#endif