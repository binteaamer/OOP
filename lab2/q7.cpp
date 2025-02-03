/*You are tasked with building a simple product management system for an online
store.
1. Create a function that allows the addition of a new product to the system. The
function should
take parameters such as product name, price, quantity, and any other relevant
details.
2. Implement a function that takes a product ID as input and displays detailed
information about the
product, including its name, price, quantity in stock, and any other relevant
details.
3. Design a function that enables the update of product information. It should
take a product ID as
well as the new details (e.g., updated price, quantity, etc.) and modify the
existing product&amp;#39;s
information accordingly.

4. Create a function that removes a product from the system based on its product
ID. Ensure that
the inventory is updated after the removal.*/

#include<iostream>
#include<string>
using namespace std;

struct Product {
int id;
string name;
double price;
int quantity;
};

const int MAX = 100;
int count = 0;

void add_product(Product product[], int id, string name, double price, int
quantity) {
if (count &lt; MAX) {
product[count].id = id;
product[count].name = name;
product[count].price = price;
product[count].quantity = quantity;
count++;
cout <<"Product added successfully<<endl;
} else {
cout &lt;&lt; &quot;Max limit for products reached\n&quot;;
}
}

void display(Product product[], int id) {
bool found = false;

for (int i = 0; i &lt; count; i++) {
if (product[i].id == id) {
cout &lt;&lt; &quot;Displaying product information\n&quot;;
cout &lt;&lt; &quot;Product ID: &quot; &lt;&lt; product[i].id &lt;&lt; &quot;, &quot;
&lt;&lt; &quot;Product Name: &quot; &lt;&lt; product[i].name &lt;&lt; &quot;, &quot;
&lt;&lt; &quot;Price: $ &quot; &lt;&lt; product[i].price &lt;&lt; &quot;, &quot;
&lt;&lt; &quot;Quantity: &quot; &lt;&lt; product[i].quantity &lt;&lt; endl;
found = true;
break;
}
}
if (!found) {
cout<<"Product ID not found"<<endl;
}
}

void update(Product product[], int id, double newprice, int newquantity) {
bool found = false;
for (int i = 0; i &lt; count; i++) {
if (product[i].id == id) {
product[i].price = newprice;
product[i].quantity = newquantity;
cout<<"Product updated successfully<<endl;
found = true;
break;
}

}
if (!found) {
cout<<"Product ID not found<<endl;
}
}

void remove(Product product[], int id) {
bool found = false;
for (int i = 0; i &lt; count; i++) {
if (product[i].id == id) {
found = true;
for (int j = i; j &lt; count - 1; j++) {
product[j] = product[j + 1];
}
count--;
cout<<"Product removed successfully"<<endl;
break;
}
}
if (!found) {
cout<< "Product ID not found"<<endl;
}
}

int main() {
Product product[MAX];

add_product(product, 1, "Laptop&quot", 991.99, 10);
add_product(product, 2, "Smartphone", 499.99, 20);
add_product(product, 3, "Tablet&quot", 299.99, 15);

int searchID;
cout <<"Enter ID to search: ";
cin>> searchID;
display(product, searchID);

int removeID;
cout<<"Enter ID to remove: ";
cin<< removeID;
remove(product, removeID);

return 0;
}
