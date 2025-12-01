# 🚀 42 C++ Modules Repository

This repository documents my progression through the intensive C++ Modules curriculum (CPP 00 to CPP 09) at **École 42 / [Your Campus Name]**. This project series serves as a deep dive into **Object-Oriented Programming (OOP)**, memory management, and advanced C++ features, primarily adhering to the C++98 standard.

---

## 🎯 Key Learning Focus

The exercises in this repository focus on building a strong foundation in C++ by mastering:

* **OOP Fundamentals:** Comprehensive implementation of **Encapsulation**, **Inheritance**, and **Polymorphism**.
* **Memory Management:** Detailed understanding and practice with manual dynamic allocation (`new`/`delete`) and the **RAII** principle (Resource Acquisition Is Initialization).
* **Orthodox Canonical Class Form (OCCF):** Correct implementation of the Copy Constructor, Copy Assignment Operator, and Destructor in accordance with C++98.
* **Advanced Features:** Practical usage of **Exception Handling**, various **Casting** operators, **Templates** for generic programming, and the **Standard Template Library (STL)**.

---

## 📁 Modules Overview

| Module | Core Concept | Key Exercises / Skills |
| :--- | :--- | :--- |
| **CPP 00** | Basic Classes | Namespaces, Constructors, Member Functions, `const`. |
| **CPP 01** | Memory & References | Pointers, References, Stack vs. Heap, `new`/`delete`. |
| **CPP 02** | Canonical Form | Operator Overloading, OCCF implementation. |
| **CPP 03** | Inheritance | Base/Derived classes, Constructor Chaining. |
| **CPP 04** | Polymorphism | Virtual Functions, Abstract Classes, Interfaces. |
| **CPP 05** | Exception Handling | Custom Exception Classes, `try`/`catch`/`throw`. |
| **CPP 06** | C++ Casting | `static_cast`, `dynamic_cast`, `reinterpret_cast`. |
| **CPP 07** | Templates | Function and Class Templates for Generic Code. |
| **CPP 08** | STL | Containers, Iterators, Algorithms (`std::vector`, `std::map`, etc.). |
| **CPP 09** | Final Project | Application of all concepts (e.g., RPN calculator, complex container manipulation). |

---

## ⚙️ Compilation & Usage

Each module is self-contained within its respective directory (`cpp00/`, `cpp01/`, etc.).

1.  Navigate to the desired module directory:
    ```bash
    cd cpp0X
    ```

2.  Build the project using the provided `Makefile`:
    ```bash
    make
    ```

3.  Run the resulting executable (name varies per exercise, often `main` or a specific program name):
    ```bash
    ./[executable_name]
    ```

**Required Compiler:** GCC or Clang supporting the C++98/C++03 standards.

---
