#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

// ================= BOOK CLASS =================
class Book {
public:
    int id;
    string name;
    string author;
    int quantity;
    int sold;
    int returned;
    double rate;

    Book() {
        quantity = 0;
        sold = 0;
        returned = 0;
        rate = 0;
    }

    void input() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(1000, '\n');

        cout << "Enter Book Name: ";
        getline(cin, name);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Rate: ";
        cin >> rate;

        sold = 0;
        returned = 0;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAuthor: " << author;
        cout << "\nStock: " << quantity;
        cout << "\nSold: " << sold;
        cout << "\nReturned: " << returned;
        cout << "\nRate: " << rate;
        cout << "\n---------------------------\n";
    }

    string saveFormat() {
        stringstream ss;
        ss << id << "|" << name << "|" << author << "|"
           << quantity << "|" << sold << "|" << returned << "|" << rate;
        return ss.str();
    }

    static Book loadFormat(string line) {
        Book b;
        string temp;
        stringstream ss(line);

        getline(ss, temp, '|');
        b.id = atoi(temp.c_str());

        getline(ss, b.name, '|');
        getline(ss, b.author, '|');

        getline(ss, temp, '|');
        b.quantity = atoi(temp.c_str());

        getline(ss, temp, '|');
        b.sold = atoi(temp.c_str());

        getline(ss, temp, '|');
        b.returned = atoi(temp.c_str());

        getline(ss, temp, '|');
        b.rate = atof(temp.c_str());

        return b;
    }
};

// ================= LIBRARY CLASS =================
class Library {
    vector<Book> books;

public:

    void load() {
        books.clear();
        ifstream file("books.txt");
        string line;

        while (getline(file, line)) {
            if (!line.empty())
                books.push_back(Book::loadFormat(line));
        }
        file.close();
    }

    void save() {
        ofstream file("books.txt");

        for (int i = 0; i < books.size(); i++) {
            file << books[i].saveFormat() << endl;
        }

        file.close();
    }

    void addBook() {
        Book b;
        b.input();
        books.push_back(b);
        save();
        cout << "\nBook Added Successfully!\n";
    }

    void showBooks() {
        if (books.empty()) {
            cout << "\nNo Books Available!\n";
            return;
        }

        for (int i = 0; i < books.size(); i++) {
            books[i].display();
        }
    }

    int searchMenu() {
        cout << "\nSearch By:\n";
        cout << "1. ID\n";
        cout << "2. Name\n";
        cout << "3. Author\n";
        cout << "Enter Choice: ";
        int ch;
        cin >> ch;
        cin.ignore(1000, '\n');
        return ch;
    }

    int searchBook() {
        int option = searchMenu();

        if (option == 1) {
            int id;
            cout << "Enter ID: ";
            cin >> id;

            for (int i = 0; i < books.size(); i++)
                if (books[i].id == id)
                    return i;
        }

        else if (option == 2) {
            string name;
            cout << "Enter Name: ";
            getline(cin, name);

            for (int i = 0; i < books.size(); i++)
                if (books[i].name == name)
                    return i;
        }

        else if (option == 3) {
            string author;
            cout << "Enter Author: ";
            getline(cin, author);

            for (int i = 0; i < books.size(); i++)
                if (books[i].author == author)
                    return i;
        }

        return -1;
    }

    void sales() {
        double total = 0;
        char choice;

        cout << "\n========== BILL ==========\n";

        do {
            int index = searchBook();

            if (index == -1) {
                cout << "Book Not Found!\n";
            } else {
                int qty;
                cout << "Enter Quantity: ";
                cin >> qty;

                if (qty > books[index].quantity) {
                    cout << "Not Enough Stock!\n";
                } else {
                    books[index].quantity -= qty;
                    books[index].sold += qty;

                    double amount = qty * books[index].rate;
                    total += amount;

                    cout << "\nBook: " << books[index].name;
                    cout << "\nQty: " << qty;
                    cout << "\nAmount: " << amount << "\n";
                }
            }

            cout << "\nAdd More Books to Bill? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << "\nTOTAL BILL = " << total << endl;
        cout << "==========================\n";

        save();
    }

    void returnBook() {
        int index = searchBook();

        if (index == -1) {
            cout << "Book Not Found!\n";
            return;
        }

        int qty;
        cout << "Enter Quantity to Return: ";
        cin >> qty;

        books[index].quantity += qty;
        books[index].returned += qty;

        save();

        cout << "Book Returned Successfully!\n";
    }

    void menu() {
        load();
        int choice;

        do {
            cout << "\n====================================\n";
            cout << "   BOOK STORE MANAGEMENT SYSTEM\n";
            cout << "====================================\n";
            cout << "1. Add Book (New)\n";
            cout << "2. Show All Books\n";
            cout << "3. Search Book\n";
            cout << "4. Sales\n";
            cout << "5. Return Book\n";
            cout << "6. Exit\n";
            cout << "Enter Choice: ";

            cin >> choice;

            switch (choice) {
            case 1: addBook(); break;
            case 2: showBooks(); break;
            case 3: {
                int index = searchBook();
                if (index == -1)
                    cout << "Book Not Found!\n";
                else
                    books[index].display();
                break;
            }
            case 4: sales(); break;
            case 5: returnBook(); break;
            case 6: cout << "\nThank You!\n"; break;
            default: cout << "Invalid Choice!\n";
            }

        } while (choice != 6);
    }
};

// ================= MAIN =================
int main() {
    Library lib;
    lib.menu();
    return 0;
}
