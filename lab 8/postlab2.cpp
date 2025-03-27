
#include <iostream>
using namespace std;

// Base class Product
class Product {
protected:
    int productID;
    double price;
public:
    Product(int id, double p) : productID(id), price(p) {}
    virtual double calculatePrice() = 0; // Pure virtual function
    virtual void applyDiscount(double discount) {}
    double getPrice() { return price; }
};

// Derived class Electronics
class Electronics : public Product {
public:
    Electronics(int id, double p) : Product(id, p) {}
    double calculatePrice() override {
        return price * 1.15; // 15% tax
    }
};

// Derived class Clothing
class Clothing : public Product {
public:
    Clothing(int id, double p) : Product(id, p) {}
    double calculatePrice() override {
        return price * 1.05; // 5% tax
    }
};

// ShoppingCart class
class ShoppingCart {
    Product* products[10];
    int count;
public:
    ShoppingCart() : count(0) {}
    void addProduct(Product* p) {
        if (count < 10) products[count++] = p;
    }
    void removeProduct(int index) {
        if (index >= 0 && index < count) {
            for (int i = index; i < count - 1; i++)
                products[i] = products[i + 1];
            count--;
        }
    }
    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < count; i++) total += products[i]->calculatePrice();
        return total;
    }
    // Operator Overloading
    ShoppingCart operator+(const ShoppingCart& other) {
        ShoppingCart newCart = *this;
        for (int i = 0; i < other.count && newCart.count < 10; i++)
            newCart.products[newCart.count++] = other.products[i];
        return newCart;
    }
    ShoppingCart operator-(int index) {
        ShoppingCart newCart = *this;
        newCart.removeProduct(index);
        return newCart;
    }
    ShoppingCart operator*(double discount) {
        for (int i = 0; i < count; i++)
            products[i]->applyDiscount(discount);
        return *this;
    }
    double operator/(int users) {
        return calculateTotal() / users;
    }
};

int main() {
    Electronics laptop(101, 1200);
    Clothing tshirt(202, 50);
    
    ShoppingCart cart1, cart2;
    cart1.addProduct(&laptop);
    cart1.addProduct(&tshirt);
    
    cout << "Total price (cart1): $" << cart1.calculateTotal() << endl;
    
    Electronics phone(102, 800);
    cart2.addProduct(&phone);
    
    ShoppingCart mergedCart = cart1 + cart2;
    cout << "Total price (merged cart): $" << mergedCart.calculateTotal() << endl;
    
    cout << "Each user pays: $" << (mergedCart / 2) << endl;
    
    return 0;
}
