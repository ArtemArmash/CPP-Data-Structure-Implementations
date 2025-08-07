# C++ Data Structure Implementations: Linked List and Stack

This repository contains C++ implementations of two fundamental, node-based data structures: a generic Singly Linked List and a generic Stack. These projects are excellent for understanding dynamic memory management, templates, and the core logic behind these structures.

---

## 1. Generic Singly Linked List (`Singly_linked_list.cpp`)

This file contains a feature-rich implementation of a generic, singly linked list class named `List<T>`.

### Features

*   **Generic (`template<class T>`)**: Can store elements of any data type.
*   **Full CRUD Functionality**:
    *   `push_front()` and `push_back()`: Add elements to the beginning or end.
    *   `pop_front()` and `pop_back()`: Remove elements from the beginning or end.
    *   `Insert()`: Add an element at a specific index.
    *   `removeAT()`: Remove an element from a specific index.
    *   `clear()`: Deletes all nodes in the list.
*   **Operator Overloading**:
    *   `operator[]`: Provides direct access to elements by index (note: this is an O(n) operation for a linked list).
    *   `operator+`: Concatenates two lists into a new list.
    *   `operator*`: Creates a new list containing the intersection (common elements) of two lists.
*   **Resource Management**: Includes a destructor that properly deallocates all nodes to prevent memory leaks.

### Critical Implementation Issues

This implementation contains **serious memory management bugs** in its overloaded operators, which are important to understand.

1.  **Memory Leak in `operator+` and `operator*`**:
    *   **The Problem**: These methods create a new, combined list by cloning the nodes of the original lists. However, the `List` object they return is a temporary one with its `size` member uninitialized (it remains 0). When this temporary object is destroyed, its `clear()` method does nothing because it thinks the list is empty, **leaking all the newly allocated memory**.
    *   **The Fix**: A proper implementation would require the `List` class to have a copy constructor and copy assignment operator (fulfilling the Rule of Five/Three) or for the operator functions to correctly set the `size` of the `result` list and manage its memory.

### How to Compile and Run
```sh
# Rename the file to avoid conflicts if you use both
mv Singly_linked_list.cpp list_main.cpp

# Compile
g++ list_main.cpp -o list_app

# Run
./list_app
```

---

## 2. Generic Stack (`Stack.cpp`)

This file provides a classic LIFO (Last-In-First-Out) Stack data structure, implemented using a linked list as its underlying container.

### Features

*   **Generic (`template<class T>`)**: Can store elements of any data type.
*   **Standard Stack Operations**:
    *   `push()`: Adds an element to the top of the stack.
    *   `pop()`: Removes and returns the element from the top.
    *   `top()`: Returns a reference to the top element without removing it.
    *   `Empty()`: Checks if the stack is empty.
    *   `getSize()`: Returns the number of elements.
*   **Efficient Swapping**: Includes a `Swap` method for constant-time swapping of two stacks.
*   **Resource Management**: The destructor safely deallocates all nodes.

### Critical Implementation Issues

1.  **Crash in `top()` on Empty Stack**:
    *   **The Problem**: If the `top()` method is called when the stack is empty, it prints a message but then proceeds to execute `return top_node->datas;`. Since `top_node` is `nullptr`, this causes a **segmentation fault and crashes the program**.
    *   **The Fix**: The method should throw an exception or terminate gracefully instead of attempting to dereference a null pointer.

    **Corrected `top()` method:**
    ```cpp
    T& top() {
        if (Empty()) {
            throw std::runtime_error("Error: Attempted to call top() on an empty stack.");
        }
        return top_node->datas;
    }
    ```

### How to Compile and Run
```sh
# Rename the file
mv Stack.cpp stack_main.cpp

# Compile
g++ stack_main.cpp -o stack_app

# Run
./stack_app
```
```
