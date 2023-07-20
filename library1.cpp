#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool available;

public:
    Book(string title, string author) {
        this->title = title;
        this->author = author;
        available = true;
    }

    string getTitle() const{
        return title;
    }

    string getAuthor() const{
        return author;
    }

    bool isAvailable() const{
        return available;
    }

    void setAvailability(bool availability) {
        available = availability;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
    }

    void removeBook(Book book) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == book.getTitle() && it->getAuthor() == book.getAuthor()) {
                books.erase(it);
                break;
            }
        }
    }

    void displayAvailableBooks() {
        cout << "Available Books:" << endl;
        for (const auto& book : books) {
            if (book.isAvailable()) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << endl;
            }
        }
    }

    void displayAllBooks() {
        cout << "All Books:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << endl;
        }
    }

    void searchBooksByAuthor(string author) {
        cout << "Books by " << author << ":" << endl;
        for (const auto& book : books) {
            if (book.getAuthor() == author) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << endl;
            }
        }
    }

    void searchBooksByTitle(string title) {
        cout << "Books with title \"" << title << "\":" << endl;
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << endl;
            }
        }
    }
};

int main() {
    Library library_object;

    Book book1("Book 1", "Author 1");
    Book book2("Book 2", "Author 2");
    Book book3("Book 3", "Author 3");

    library_object.addBook(book1);
    library_object.addBook(book2);
    library_object.addBook(book3);

    cout << "Library Management System" << endl;

    int choice;
    do {
        cout << "1. Display all books" << endl;
        cout << "2. Display available books" << endl;
        cout << "3. Search books by author" << endl;
        cout << "4. Search books by title" << endl;
        cout << "5. Add a book" << endl;
        cout << "6. Remove a book" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                library_object.displayAllBooks();
                break;
            case 2:
                system("cls");
                library_object.displayAvailableBooks();
                break;
            case 3: {
                system("cls");
                string author;
                cin.ignore();
                cout << "Enter author name: ";
                getline(cin, author);
                library_object.searchBooksByAuthor(author);
                break;
            }
            case 4: {
                system("cls");
                string title;
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, title);
                library_object.searchBooksByTitle(title);
                break;
            }
            case 5: {
                system("cls");
                string title, author;
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                Book newBook(title, author);
                library_object.addBook(newBook);
                cout << "Book added successfully." << endl;
                break;
            }
            case 6: {
                system("cls");
                string title, author;
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                Book removeBook(title, author);
                library_object.removeBook(removeBook);
                cout << "Book removed successfully." << endl;
                break;
            }
            case 7:
                system("cls");
                cout << "Exiting..." << endl;
                break;
            default:
                system("cls");
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
