# CRUD Library

A simple Command Line Interface (CLI) program to manage a library database using a singly linked list in C++.

## Features

This program provides basic CRUD (Create, Read, Update, Delete) operations for managing books in a library.

### 1. Add Book
- Adds a new book to the library.
- Collects details like title, writer, publisher, and year of publication.

### 2. Show Book
- Displays a list of all books in the library in a tabular format.

### 3. Update Book
- Updates the details of an existing book based on the title.
- Allows modifying title, writer, publisher, or year.

### 4. Delete Book
- Removes a book from the library based on the title.

### 5. Exit
- Exits the program.

## Implementation Details

- **Language**: C++
- **Data Structure**: Singly Linked List
- **Libraries**: `iostream`, `string`, `iomanip`

### Program Structure

#### Node Structure
Each book is represented as a node in the linked list with the following attributes:
- `titleBook`: Title of the book
- `writer`: Name of the writer
- `publisher`: Name of the publisher
- `year`: Year of publication
- `next`: Pointer to the next node in the list

#### Functions
- **`addNode`**: Adds a new book to the end of the linked list.
- **`updateNode`**: Updates details of a specific book based on the title.
- **`removeNode`**: Deletes a book from the linked list.
- **`printNode`**: Prints all books in a formatted table.
- **`clearScreen`**: Clears the console screen (supports both Windows and Unix-like systems).
- **`menu`**: Displays the main menu.

## How to Use

1. **Clone or Download the Repository**:
   ```bash
   git clone <repository-url>
   ```

2. **Compile the Program**:
   Use any C++ compiler (e.g., g++):
   ```bash
   g++ -o crud_library main.cpp
   ```

3. **Run the Program**:
   ```bash
   ./crud_library
   ```

4. **Follow the Menu Instructions**:
   Select options from the menu to perform the desired operations.

## Example Output

```plaintext
======================
     CRUD LIBRARY
======================
1. Add Book
2. Show Book
3. Update Book
4. Delete Book
5. Exit
======================
choose (1-5): 1

====================
      ADD BOOK
====================
Title    : C++ Programming
Writer   : Bjarne Stroustrup
Publisher: Addison-Wesley
Year     : 1985

======================
     CRUD LIBRARY
======================
1. Add Book
2. Show Book
3. Update Book
4. Delete Book
5. Exit
======================
choose (1-5): 2

===========================================================
|      Title     |     Writer     |   Publisher  |  Year  |
-----------------------------------------------------------
|C++ Programming |Bjarne Stroustrup|Addison-Wesley|  1985  |
===========================================================
```

## Notes

- Ensure to provide valid inputs when prompted.
- The program handles basic error checking but assumes the user will provide appropriate data.

## License

This project is open-source and free to use.
