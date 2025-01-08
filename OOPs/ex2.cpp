/*
Small Project: Expense Tracker
Description: A simple program to track expenses and calculate totals.

Key Features:
    Add, remove, and display expenses.
    Categorize expenses (e.g., food, travel, utilities).

OOP Concepts Used:
    Encapsulation: Use private data members for expense details (amount, category).
    Static Members: Maintain a static total expense tracker.
    Friend Function: Compare expenses between two categories.
    Operator Overloading: Overload '+' to combine expenses from two categories.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Food {
protected:
    float foodExpenses = 0;

public:
    Food(float previousExpense = 0) : foodExpenses(previousExpense) {}

    void addExpense(float spend) {
        foodExpenses += spend;
    }

    void display() const {
        cout << "Total money spent on food: " << foodExpenses << endl;
    }

    float getExpense() const {
        return foodExpenses;
    }
};

class Travel {
protected:
    float travellingExpenses = 0;

public:
    Travel(float previousExpense = 0) : travellingExpenses(previousExpense) {}

    void addExpense(float spend) {
        travellingExpenses += spend;
    }

    void display() const {
        cout << "Total money spent on travel: " << travellingExpenses << endl;
    }

    float getExpense() const {
        return travellingExpenses;
    }
};

class Utilities {
protected:
    float utilitiesExpenses = 0;

public:
    Utilities(float previousExpense = 0) : utilitiesExpenses(previousExpense) {}

    void addExpense(float payed) {
        utilitiesExpenses += payed;
    }

    void display() const {
        cout << "Total money spent on utilities: " << utilitiesExpenses << endl;
    }

    float getExpense() const {
        return utilitiesExpenses;
    }
};

class TotalExpenses {
private:
    Food food;
    Travel travel;
    Utilities utilities;

public:
    TotalExpenses(float foodExpense = 0, float travelExpense = 0, float utilitiesExpense = 0)
        : food(foodExpense), travel(travelExpense), utilities(utilitiesExpense) {}

    void setData(float foodExpense, float travelExpense, float utilitiesExpense) {
        food = Food(foodExpense);
        travel = Travel(travelExpense);
        utilities = Utilities(utilitiesExpense);
    }

    void display() const {
        food.display();
        travel.display();
        utilities.display();
    }

    void addFoodExpense(float amount) {
        food.addExpense(amount);
    }

    void addTravelExpense(float amount) {
        travel.addExpense(amount);
    }

    void addUtilitiesExpense(float amount) {
        utilities.addExpense(amount);
    }
};

int main() {
    int count;
    cout << "Enter the number of households to calculate: ";
    cin >> count;

    vector<string> householdNames(count);
    vector<TotalExpenses> householdExpenses(count);

    for (int i = 0; i < count; i++) {
        cout << "Enter the name/ID of household " << i + 1 << ": ";
        cin >> householdNames[i];

        float foodExp, travelExp, utilitiesExp;
        cout << "Any previous expenses for food, travel, and utilities: "<<endl;
        cin >> foodExp >> travelExp >> utilitiesExp;
        householdExpenses[i].setData(foodExp, travelExp, utilitiesExp);
    }

    
    system("CLS");

    char exist = 'y';
    while (exist == 'y' || exist == 'Y') {
        system("CLS");
        cout << "Do you want to find/change records? (y/n): ";
        cin >> exist;
        if (exist == 'n' || exist == 'N') {
            cout<<"Existing the Program!!!"<<endl;
            break;
        };

        
        system("CLS");
        for (size_t i = 0; i < householdNames.size(); i++) {
            cout << i + 1 << ") Household: " << householdNames[i] << endl;
        }

        int index;
        cout << "Enter the index of the household you want to access: ";
        cin >> index;
        index--; // Adjust for zero-based indexing

        
        system("CLS");
        if (index >= 0 && index < householdExpenses.size()) {
            char option;
            while (true) {
                cout << "Options: \n"
                     << "T: Display Total Expenses\n"
                     << "F: Add Food Expense\n"
                     << "R: Add Travel Expense\n"
                     << "U: Add Utilities Expense\n"
                     << "E: Exit\n"
                     << "Choose an option: ";
                cin >> option;

                if (option == 'E' || option == 'e') break;

                system("CLS");
                switch (option) {
                case 'T':
                    householdExpenses[index].display();
                    break;
                case 'F': {
                    float amount;
                    cout << "Enter food expense: ";
                    cin >> amount;
                    householdExpenses[index].addFoodExpense(amount);
                    break;
                }
                case 'R': {
                    float amount;
                    cout << "Enter travel expense: ";
                    cin >> amount;
                    householdExpenses[index].addTravelExpense(amount);
                    break;
                }
                case 'U': {
                    float amount;
                    cout << "Enter utilities expense: ";
                    cin >> amount;
                    householdExpenses[index].addUtilitiesExpense(amount);
                    break;
                }
                default:
                    cout << "Invalid option. Try again.\n";
                }
            }
        } else {
            cout << "Invalid index. Try again.\n";
        }
    }

    cout<<"Exist Successfully"<<endl;

    return 0;
}
