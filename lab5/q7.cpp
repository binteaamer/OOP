/*Implement a restaurant ordering system that holds information about the restaurant’s menus, menu
items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in
mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and
remove items, or display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. Theorder class
consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is
generated when the order is placed.*/

#include <iostream>
using namespace std;

class MenuItem {
    string foodName;
    double foodPrice;

public:
    MenuItem() : foodName(""), foodPrice(0.0) {} 
    MenuItem(string name, double price) : foodName(name), foodPrice(price) {}

    string getName() const { return foodName; }
    double getPrice() const { return foodPrice; }

    void display() const {
        cout << foodName << " - Rs. " << foodPrice << endl;
    }
};

class Menu {
    MenuItem menuItems[3]; 
    int itemCount;

public:
    Menu() {
        itemCount = 3;
        menuItems[0] = MenuItem("Burger", 120.25);
        menuItems[1] = MenuItem("Shake", 50.0);
        menuItems[2] = MenuItem("Fries", 80.0);
    }

    void displayMenu() const {
        cout << "\n--- Menu ---\n";
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". ";
            menuItems[i].display();
        }
    }

    MenuItem getItem(int index) const {
        if (index >= 0 && index < itemCount) {
            return menuItems[index];
        }
        return MenuItem("", 0.0); 
    }

    int getMenuSize() const {
        return itemCount;
    }
};


class Payment {
    double amount;

public:
    Payment() : amount(0.0) {}

    void setAmount(double amt) {
        amount = amt;
    }

    void displayPayment() const {
        cout << "Total Amount to Pay: Rs. " << amount << endl;
    }
};


class Order {
    MenuItem orderedItems[5]; 
    int itemCount;
    Payment payment;

public:
    Order() : itemCount(0) {}

    void addItem(const MenuItem& item) {
        if (itemCount < 5) {
            orderedItems[itemCount] = item;
            itemCount++;
        } else {
            cout << "Order limit reached!\n";
        }
    }

    void finalizeOrder() {
        double totalAmount = 0;
        for (int i = 0; i < itemCount; i++) {
            totalAmount += orderedItems[i].getPrice();
        }
        payment.setAmount(totalAmount);
    }

    void displayOrder() const {
        cout << "\n--- Order Summary ---\n";
        for (int i = 0; i < itemCount; i++) {
            orderedItems[i].display();
        }
        payment.displayPayment();
    }
};

class Restaurant {
    Menu menu;

public:
    void takeOrder() {
        menu.displayMenu();
        Order order;
        int choice;

        cout << "Enter the item numbers to order (-1 to finish):\n";
        while (true) {
            cout << "Item number: ";
            cin >> choice;
            if (choice == -1) break;
            if (choice >= 1 && choice <= menu.getMenuSize()) {
                order.addItem(menu.getItem(choice - 1));
            } else {
                cout << "Invalid choice! Try again.\n";
            }
        }

        order.finalizeOrder();
        order.displayOrder();
    }
};

int main() {
    Restaurant myRestaurant;
    myRestaurant.takeOrder();
    return 0;
}
