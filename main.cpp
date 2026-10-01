#include <iostream>
#include <string>
#include <vector>
#include "Supply.h"

// Prints every supply's name and quantity, marking low supplies
void displaySupplies(const std::vector<Supply>& supplies) {
    for (const Supply& supply : supplies) {
        std::cout << supply.getName() << ": " << supply.getQuantity();
        if (supply.isLow()) {
            std::cout << " [LOW]";
        }
        std::cout << "\n";
    }
}

// Counts how many supplies are below their minimum
int countLow(const std::vector<Supply>& supplies) {
    int count = 0;
    for (const Supply& supply : supplies) {
        if (supply.isLow()) {
            count++;
        }
    }
    return count;
}

// Returns a pointer to the low supply with the greatest shortage,
// or nullptr if no supply is low. The vector is passed by reference
// so the pointer refers to an object in the original vector, not a copy.
Supply* findHighestPriority(std::vector<Supply>& supplies) {
    Supply* best = nullptr;

    for (Supply& supply : supplies) {
        if (supply.isLow()) {
            int shortage = supply.getMinimum() - supply.getQuantity();

            // Strict > keeps the first supply when shortages tie
            if (best == nullptr ||
                shortage > best->getMinimum() - best->getQuantity()) {
                best = &supply;
            }
        }
    }

    return best;
}

// The parameter is a reference so this function changes the original
// Supply object in the vector. Passing by value would only change a
// temporary copy, and the vector would keep the old quantity.
void restock(Supply& supply) {
    supply.add(5);
}

// Prints the supply list, the low count, and the highest-priority supply
void printReport(std::vector<Supply>& supplies, const std::string& title) {
    std::cout << title << "\n";
    displaySupplies(supplies);

    int lowCount = countLow(supplies);
    if (lowCount == 1) {
        std::cout << "\n1 supply needs attention.\n";
    } else {
        std::cout << "\n" << lowCount << " supplies need attention.\n";
    }

    Supply* priority = findHighestPriority(supplies);
    if (priority != nullptr) {
        std::cout << "Highest priority: " << priority->getName() << "\n";
    } else {
        std::cout << "No supplies need attention.\n";
    }
}

int main() {
    std::vector<Supply> supplies;
    supplies.push_back(Supply("Water", 12, 8));
    supplies.push_back(Supply("Food", 4, 6));
    supplies.push_back(Supply("Rope", 2, 1));
    supplies.push_back(Supply("Medical Kits", 1, 3));

    printReport(supplies, "EXPEDITION SUPPLIES");

    supplies[0].use(3);     // Water: 12 -> 9
    restock(supplies[1]);   // Food: 4 -> 9

    std::cout << "\n";
    printReport(supplies, "UPDATED SUPPLIES");

    return 0;
}