# 📚 Book Store Management System (C++)

Book Store Management System is a simple console-based application built using **C++ and Object-Oriented Programming (OOP)** concepts.

This program allows users to **manage books in a store, handle sales, process returns, and store book data using file handling**. All book information is saved in a text file so that data remains available even after the program is closed.

---

# ✨ Features

➕ **Add new books**

📖 **Display all available books**

🔍 **Search books by**

* Book ID
* Book Name
* Author Name

💰 **Sales system with bill generation**

🔄 **Return books and update stock**

💾 **File handling** to save and load data automatically

📊 Track:

* Available stock
* Sold quantity
* Returned quantity

---

# 🧠 Concepts Used

This project demonstrates several important **C++ programming concepts**:

* Object-Oriented Programming (OOP)
* Classes and Objects
* Vectors
* File Handling (`fstream`)
* String Streams
* Data Persistence
* Menu Driven Programs

---

# 📂 Project Structure

```id="5b9glo"
Book-Store-Management-System
│
├── main.cpp
├── books.txt
├── README.md
└── LICENSE
```

---

# 📄 File Description

| File      | Description                              |
| --------- | ---------------------------------------- |
| main.cpp  | Main source code of the bookstore system |
| books.txt | Stores book data permanently             |
| README.md | Project documentation                    |
| LICENSE   | Project license                          |

---

# ⚙️ How Data is Stored

All book data is saved in **books.txt** using the following format:

```id="v4yq9t"
BookID|BookName|Author|Quantity|Sold|Returned|Rate
```

Example:

```id="8ne6nt"
101|C++ Programming|Bjarne Stroustrup|20|5|1|500
102|Data Structures|Mark Allen Weiss|15|3|0|450
```

---

# 🖥️ How to Run the Program

## Step 1 — Compile the Program

Using **g++ compiler**

```id="qu0rqp"
g++ main.cpp -o bookstore
```

---

## Step 2 — Run the Program

Linux / Mac:

```id="12msf6"
./bookstore
```

Windows:

```id="y9vnyl"
bookstore.exe
```

---

# 📋 Menu Options

When the program starts, the following menu will appear:

```
BOOK STORE MANAGEMENT SYSTEM

1. Add Book
2. Show All Books
3. Search Book
4. Sales
5. Return Book
6. Exit
```

---

## 1️⃣ Add Book

Allows the user to add a new book with details such as:

* Book ID
* Book Name
* Author
* Quantity
* Price

---

## 2️⃣ Show All Books

Displays all books currently available in the store.

---

## 3️⃣ Search Book

Search for books using:

* Book ID
* Book Name
* Author Name

---

## 4️⃣ Sales

Allows the user to sell books and generate a **bill while updating the stock**.

---

## 5️⃣ Return Book

Updates stock when a customer returns a book.

---

## 6️⃣ Exit

Safely closes the program.

---

# 💡 Example Bill Output

```
========== BILL ==========

Book: C++ Programming
Qty: 2
Amount: 1000

TOTAL BILL = 1000
==========================
```

---

# 👨‍💻 Author

**Sam Wilson**

🌐 GitHub
https://github.com/rsamwilson2323-cloud

💼 LinkedIn
https://www.linkedin.com/in/sam-wilson-14b554385

---

# 📜 License

This project is licensed under the **MIT License**.
