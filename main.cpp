#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Library
{
public:
    int id;
    char name[100];
    char author[100];
    char student[100];
    int price;
    int pages;
};

Library lib[20];
int count = 0;

void bookDetails(int i)
{
    cout << "Book name: " << lib[i].name << endl;
    cout << "Book name: " << lib[i].name << endl;
    cout << "Book author: " << lib[i].author << endl;
    cout << "Book price: " << lib[i].price << endl;
    cout << "Book pages: " << lib[i].pages << endl;
}

void addBook()
{
    cout << "Enter book id: ";
    cin >> lib[count].id;
    cout << "Enter book name: ";
    cin.ignore();
    cin.getline(lib[count].name, 100);
    cout << "Enter book author: ";
    cin.getline(lib[count].author, 100);
    cout << "Enter book price: ";
    cin >> lib[count].price;
    cout << "Enter book pages: ";
    cin >> lib[count].pages;
    count++;
}

void displayBook(int n)
{
    cout << "Your total books: " << n << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ". Book name: " << lib[i].name << endl;
    }

    if (n > 0)
    {
        int serialN;
        cout << "Enter the book serial number to see details" << endl;
        cin >> serialN;
        if (serialN > 0 && serialN <= n)
        {
            bookDetails(serialN - 1);
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}

void deleteBook()
{
    int bookId;

    for (int i = 0; i < count; ++i)
    {
        cout << i + 1 << ". Book id: " << lib[i].id << " - book name: " << lib[i].name << endl;
    }

    cout << "Enter book id of the book you want to delete: " << endl;

    cin >> bookId;

    int indexToDelete = -1;

    // Find the index of the object with the given bookId
    for (int i = 0; i < count; i++)
    {
        if (lib[i].id == bookId)
        {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1)
    {
        // Shift elements to fill the gap
        for (int i = indexToDelete; i < count - 1; i++)
        {
            lib[i] = lib[i + 1];
        }

        count--; // Decrement the count to reflect the deletion of an element
        cout << "Book with id " << bookId << " has been deleted." << endl;
    }
    else
    {
        cout << "Book with id " << bookId << " not found." << endl;
    }
}

void editBook()
{
    for (int i = 0; i < count; ++i)
    {
        cout << i + 1 << ". Book id: " << lib[i].id << " - book name: " << lib[i].name << endl;
    }

    int bookId, indexToEdit = -1;
    cout << "Enter book id of the book you want to edit: " << endl;
    cin >> bookId;

    // Find the index of the object with the given bookId
    for (int i = 0; i < count; i++)
    {
        if (lib[i].id == bookId)
        {
            indexToEdit = i;
            break;
        }
    }

    if (indexToEdit != -1)
    {
        // Modify the details of the book
        cout << "Enter updated book name: ";
        cin >> lib[indexToEdit].name;
        cout << "Enter updated book author: ";
        cin >> lib[indexToEdit].author;
        cout << "Enter updated book price: ";
        cin >> lib[indexToEdit].price;
        cout << "Enter updated book pages: ";
        cin >> lib[indexToEdit].pages;
        cout << "Book details with id " << bookId << " have been updated." << endl;
    }
    else
    {
        cout << "Book with id " << bookId << " not found." << endl;
    }
}

int main()
{
    int input;

    while (input != 3)
    {
    start:
        cout << "Enter 1 to add new book" << endl;
        cout << "Enter 2 to display book" << endl;
        cout << "Enter 3 to delete book" << endl;
        cout << "Enter 4 to edit book" << endl;
        cout << "Enter 5 to quit" << endl;

        cin >> input;

        switch (input)
        {
        case 1:
            addBook();
            cout << "Total books: " << count << endl;
            break;
        case 2:
            displayBook(count);
            break;
        case 3:
            deleteBook();
            goto start;
            break;
        case 4:
            editBook();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid input" << endl;
            goto start;
        }
    }

    return 0;
}
