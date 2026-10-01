#include "Supply.h"

// Member initializer list sets each data member before the constructor body runs
Supply::Supply(const std::string& name, int quantity, int minimum)
    : name(name), quantity(quantity), minimum(minimum) {
}

// Increases the quantity only when the amount is positive
void Supply::add(int amount) {
    if (amount > 0) {
        quantity += amount;
    }
}

// Decreases the quantity only when the amount is positive
// and no more than what is available, so it never goes below zero
void Supply::use(int amount) {
    if (amount > 0 && amount <= quantity) {
        quantity -= amount;
    }
}

// Returns true when the quantity is below the minimum required
bool Supply::isLow() const {
    return quantity < minimum;
}

std::string Supply::getName() const {
    return name;
}

int Supply::getQuantity() const {
    return quantity;
}

int Supply::getMinimum() const {
    return minimum;
}

