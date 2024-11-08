#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    // Constructor to initialize book details
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    // Getters for accessing private members
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }

    // Function to display book details
    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "THE CHOICES ARE AS FOLLOWS:" << endl;
    }
};

class Library {
private:
    vector<Book> books; // Vector to store books

public:
    // Function to add a new book to the library
    void addBook(const Book &book) {
        books.push_back(book);
        cout << "Book added successfully!" << endl;
    }

    // Function to display all books in the library
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
        } else {
            cout << "Library Books:" << endl;
            cout << "MY BOOK'S DETAILS ARE AS FOLLOWS:" << endl;
            for (const auto &book : books) {
                book.displayBookDetails();
            }
        }
    }

    // Function to search for a book by title
    void searchBookByTitle(const string &title) const {
        bool found = false;
        for (const auto &book : books) {
            if (book.getTitle() == title) {
                cout << "Book found:" << endl;
                book.displayBookDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book with title \"" << title << "\" not found." << endl;
        }
    }
};

// Main function
int main() {
    Library library;
    int choice;
    while(choice!=4){
        cout << "Library Management System" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search for a Book by Title" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle newline after choice input

        if (choice == 1) {
            string title, author, isbn;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            cout << "Enter ISBN number: ";
            getline(cin, isbn);
            Book newBook(title, author, isbn);
            library.addBook(newBook);
        } else if (choice == 2) {
            library.displayAllBooks();
        } else if (choice == 3) {
            string searchTitle;
            cout << "Enter book title to search: ";
            getline(cin, searchTitle);
            library.searchBookByTitle(searchTitle);
        } else if (choice == 4) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
