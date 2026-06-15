# 1. Library Book Management System (Single Inheritance)

## Problem Statement

Develop a Library Book Management System to maintain information about books issued to students.

The system should store basic book information such as Book ID, Book Title, and Author Name. When a book is issued, additional details including Student Name and Issue Date should also be recorded.

Use Single Inheritance where the `IssuedBook` class inherits the properties of the `Book` class.

## Class Structure

### Class: Book

| Attribute | Method |
|-----------|----------|
| Book ID | Constructor |
| Book Title | displayBook() |
| Author Name | - |

### Class: IssuedBook

| Attribute | Method |
|-----------|----------|
| Student Name | Constructor |
| Issue Date | displayIssuedBook() |

## Concepts Covered

- Single Inheritance
- Constructor Chaining
- Member Functions
- Data Initialization using Constructors
