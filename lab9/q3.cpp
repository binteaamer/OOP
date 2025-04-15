//book.cpp
#include "Book.h"


Book::Book(string t, string a, string isbn) 
    : title(t), author(a), ISBN(isbn) {}


string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return ISBN;
}
//book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
    string title;
    string author;
    string ISBN;
    
public:
    // Constructor to initialize book details
    Book(string t, string a, string isbn);
   
    // Const-correct getter methods
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
};

#endif
//library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library {
private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library();
    bool addBook(const Book& book);
    bool removeBook(const std::string& ISBN);
    const Book* searchBook(const std::string& query) const;
    int getBookCount() const;
};

#endif

//library.cpp
#include "Library.h"
#include <string>

Library::Library() : bookCount(0) {}

bool Library::addBook(const Book& book) {
    if (bookCount >= MAX_BOOKS) return false;
    books[bookCount++] = book;
    return true;
}

bool Library::removeBook(const std::string& ISBN) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getISBN() == ISBN) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            return true;
        }
    }
    return false;
}

const Book* Library::searchBook(const std::string& query) const {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getTitle().find(query) != std::string::npos || 
            books[i].getAuthor().find(query) != std::string::npos ||
            books[i].getISBN() == query) {
            return &books[i];
        }
    }
    return nullptr;
}

int Library::getBookCount() const {
    return bookCount;
}
//main.cpp
#include <iostream>
#include "Book.h"
#include "Library.h"

using namespace std;

int main() {

    Book book1("The C++ Programming Language", "Bjarne Stroustrup", "9780321563842");
    Book book2("Effective Modern C++", "Scott Meyers", "9781491903995");
    Book book3("Clean Code", "Robert C. Martin", "9780132350884");

    Library myLibrary;
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    myLibrary.addBook(book3);
   
    cout << "Library contains " << myLibrary.getBookCount() << " books:\n";
    
    
    const Book* found = myLibrary.searchBook("Effective");
    if (found) {
        cout << "\nFound book:\n";
        cout << "Title: " << found->getTitle() << "\n";
        cout << "Author: " << found->getAuthor() << "\n";
        cout << "ISBN: " << found->getISBN() << "\n";
    }

   
    if (myLibrary.removeBook("9780132350884")) {
        cout << "\nBook removed successfully\n";
        cout << "Now library has " << myLibrary.getBookCount() << " books\n";
    }

    return 0;
}





