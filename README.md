📚 Book Store Management System (C++)

A simple Book Store Management System built using C++ and Object-Oriented Programming (OOP) concepts.
This program allows users to manage books in a store, handle sales, process returns, and store data using file handling.

The system stores book information in a text file so that the data remains saved even after the program is closed.

🚀 Features

➕ Add new books

📖 Display all available books

🔍 Search books by:

Book ID

Book Name

Author Name

💰 Sales system with bill generation

🔄 Return books and update stock

💾 File handling to save and load data automatically

📊 Track:

Available stock

Sold quantity

Returned quantity

🧠 Concepts Used

This project demonstrates several important C++ programming concepts:

Object Oriented Programming (OOP)

Classes and Objects

Vectors

File Handling (fstream)

String Streams

Data Persistence

Menu Driven Programs

📂 Project Structure
Book-Store-Management-System
│
├── main.cpp
├── books.txt
├── README.md
└── LICENSE

File Description
File	Description
main.cpp	Main source code of the bookstore system
books.txt	Stores book data permanently
README.md	Project documentation
LICENSE	Project license

⚙️ How the Data is Stored

All book data is saved inside books.txt in the following format:

BookID|BookName|Author|Quantity|Sold|Returned|Rate

Example:

101|C++ Programming|Bjarne Stroustrup|20|5|1|500
102|Data Structures|Mark Allen Weiss|15|3|0|450

🖥️ How to Run the Program
Step 1: Compile the Program

Using g++ compiler

g++ main.cpp -o bookstore
Step 2: Run the Program
./bookstore

On Windows:

bookstore.exe

📋 Menu Options

When the program runs, you will see the following menu:

BOOK STORE MANAGEMENT SYSTEM

1. Add Book
2. Show All Books
3. Search Book
4. Sales
5. Return Book
6. Exit

1️⃣ Add Book

Allows the user to add a new book with details like ID, name, author, quantity, and rate.

2️⃣ Show All Books

Displays all books available in the store.

3️⃣ Search Book

Search a book by:

ID

Name

Author

4️⃣ Sales

Generate a bill by selling books and updating stock.

5️⃣ Return Book

Update stock when a customer returns a book.

6️⃣ Exit

Exit the program safely.

💡 Example Bill Output
========== BILL ==========

Book: C++ Programming
Qty: 2
Amount: 1000

TOTAL BILL = 1000
==========================


👨‍💻 Author

Sam Wilson
🔗 GitHub: https://github.com/rsamwilson2323-cloud

🔗 LinkedIn: https://www.linkedin.com/in/sam-wilson-14b554385
