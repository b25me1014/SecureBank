# 💳 SecureBank - Multi User Banking System in C

---

## 👥 Team Members & Responsibilities

| Member       | Role                          | Responsibility                                    |
| ------------ | ----------------------------- | ------------------------------------------------- |
| Leader (You) | System Architect & Integrator | main.c, overall flow, module integration          |
| Member 2     | Account Module Developer      | account.c / account.h (account creation, search)  |
| Member 3     | Transaction Module Developer  | transaction.c / transaction.h (deposit, withdraw) |
| Member 4     | UI Module Developer           | ui.c / ui.h (menus, display)                      |
| Member 5     | History Module Developer      | history.c / history.h (transaction logs)          |
| Member 6     | Validation Module Developer   | validation.c / validation.h (input safety)        |

---

## 📌 Project Overview

SecureBank is a modular, console-based multi-user banking system built using C.
Each user has an independent account with secure access, and all operations are stored using file-based persistence.

This project follows a modular architecture where each team member works on independent files that integrate into a single system.

---

## 🚀 Features

* Multi-user account system
* Unique account ID
* Password-based authentication
* Deposit money
* Withdraw money
* Check balance
* Transaction history logging
* Persistent storage using files
* Modular team-based design

---

## 🧩 Complete Project Structure

SecureBank/
│
├── main.c                → Core system (Leader)
│
├── validation.c          → Input validation (Member 6)
├── validation.h
│
├── account.c             → Account creation & search (Member 2)
├── account.h
│
├── transaction.c         → Deposit & withdraw (Member 3)
├── transaction.h
│
├── ui.c                  → Menu & display (Member 4)
├── ui.h
│
├── history.c             → Transaction logs (Member 5)
├── history.h
│
├── storage.c             → File handling (Leader/Shared)
├── storage.h
│
├── accounts.dat          → Stores user data (auto-generated)
├── history.dat           → Stores logs (auto-generated)
│
├── README.md
└── .gitignore

---

## ⚙️ How the System Works

1. Program starts and loads data from file
2. User selects:

   * Create Account
   * Login
3. After login:

   * Deposit
   * Withdraw
   * Check Balance
   * Logout
4. All operations are saved to file immediately

---

## 💾 Data Storage

* accounts.dat → Stores user ID, password, and balance
* history.dat → Stores transaction logs

---

## 🧠 System Design Principles

* Modular architecture
* Separation of concerns
* Independent module development
* Single integration point (main.c)
* Safe input validation

---

## ⚠️ Team Rules

* Only ONE main() function (in main.c)
* Each member must work ONLY on their assigned files
* No duplicate function names
* Do NOT modify other modules
* Follow defined function interfaces
* Data files must NOT be uploaded to GitHub

---

## 📂 GitHub Workflow

* Leader uploads base system
* Team members add their modules
* Each member pushes only their files
* Final integration handled by Leader

---

## ❌ Files Not to Upload

accounts.dat
history.dat
bank.exe

---

## 🎯 Learning Outcomes

* C Programming (structures, file handling)
* Modular system design
* Team collaboration
* Debugging and integration
* Real-world project structure

---

## 🔥 Final Status

✔ Multi-user system
✔ Modular architecture
✔ File persistence
✔ Team integration ready
✔ Submission ready

---

## 📌 Note

This is an academic project designed for clarity, modularity, and correctness.
It can be extended with advanced features like encryption, database storage, and graphical UI.
