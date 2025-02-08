#include <iostream>
#include <iomanip>
using namespace std;

class StationeryShop {
private:
    string items[100];  // Array to store item names
    double prices[100]; // Array to store item prices
    int itemCount;      // Total number of items in the shop

public:
    // Constructor
    StationeryShop() {
        itemCount = 0;
    }

    // 1. Add items and their prices
    void addItem(string itemName, double price) {
        if (itemCount < 100) {
            items[itemCount] = itemName;
            prices[itemCount] = price;
            itemCount++;
            cout << "Item added successfully!\n";
        } else {
            cout << "Cannot add more items. Inventory full!\n";
        }
    }

    // 2. Fetch the list of items
    void fetchItems() {
        if (itemCount == 0) {
            cout << "No items available in the shop.\n";
            return;
        }
        cout << "\nList of Items Available:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }

    // 3. Edit item price
    void editPrice(string itemName, double newPrice) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i] == itemName) {
                prices[i] = newPrice;
                cout << "Price updated successfully!\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }

    // 4. View all items and their prices
    void viewItems() {
        if (itemCount == 0) {
            cout << "No items available in the shop.\n";
            return;
        }
        cout << "\nItems and Their Prices:\n";
        cout << setw(20) << left << "Item Name" << setw(10) << "Price" << endl;
        cout << "-----------------------------\n";
        for (int i = 0; i < itemCount; i++) {
            cout << setw(20) << left << items[i] << "$" << fixed << setprecision(2) << prices[i] << endl;
        }
    }

    // 5. Generate Receipt
    void generateReceipt() {
        if (itemCount == 0) {
            cout << "No items available to generate receipt.\n";
            return;
        }

        double total = 0;
        int numPurchases;
        cout << "Enter the number of different items purchased: ";
        cin >> numPurchases;

        string purchasedItems[numPurchases];
        int purchasedQuantities[numPurchases];

        for (int i = 0; i < numPurchases; i++) {
            cout << "Enter item name: ";
            cin >> ws;  // To ignore newline characters
            getline(cin, purchasedItems[i]);

            cout << "Enter quantity: ";
            cin >> purchasedQuantities[i];
        }

        cout << "\n===== Receipt =====\n";
        cout << setw(20) << left << "Item" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Total\n";
        cout << "------------------------------------------------\n";

        for (int i = 0; i < numPurchases; i++) {
            for (int j = 0; j < itemCount; j++) {
                if (purchasedItems[i] == items[j]) {
                    double itemTotal = prices[j] * purchasedQuantities[i];
                    total += itemTotal;
                    cout << setw(20) << left << items[j] 
                         << setw(10) << purchasedQuantities[i] 
                         << setw(10) << prices[j] 
                         << setw(10) << itemTotal << endl;
                }
            }
        }

        cout << "------------------------------------------------\n";
        cout << setw(30) << left << "Grand Total: $" << fixed << setprecision(2) << total << endl;
        cout << "====================\n";
    }
};

int main() {
    StationeryShop shop;
    int choice;

    while (true) {
        cout << "\n=== Stationery Shop Menu ===\n";
        cout << "1. Add Items & Prices\n";
        cout << "2. Fetch List of Items\n";
        cout << "3. Edit Item Price\n";
        cout << "4. View All Items & Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting program. Have a great day!\n";
            break;
        }

        string itemName;
        double price;
        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> ws;
            getline(cin, itemName);
            cout << "Enter item price: ";
            cin >> price;
            shop.addItem(itemName, price);
            break;
        case 2:
            shop.fetchItems();
            break;
        case 3:
            cout << "Enter item name to edit price: ";
            cin >> ws;
            getline(cin, itemName);
            cout << "Enter new price: ";
            cin >> price;
            shop.editPrice(itemName, price);
            break;
        case 4:
            shop.viewItems();
            break;
        case 5:
            shop.generateReceipt();
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
