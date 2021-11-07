//Lab 1 Mohammadzadeh, Hiva Thursday

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>

using namespace std;

//Struct Definition
struct itemType {
    string ID;
    string Name;
    int quantityOnHand;
    double Price;
};

//Function Prototypes
void printInventory(itemType *items[], int counter);
void searchForItem(itemType *items[], int totalItems);
void printReport(int totalItems, itemType *items[]);
void sortMenu(itemType *items[], int totalItems);
int inputData(int totalItems, itemType*[]);
void displayMenu(itemType *items[], int totalItems);
void bubbleSort(int userInput, int totalItems, itemType *items[]);

const int MAX_SIZE = 100;

int main() {
    const int MAX_SIZE = 100;
    int totalItems = 0;
    itemType *items[MAX_SIZE];
    cout << fixed << showpoint;
    totalItems = inputData(totalItems, items);

    cout << "Welcome To The Menu!\n\n";

    displayMenu(items, totalItems);
   
    system("pause");
    return 0;
}

int inputData(int totalItems, itemType *items[])
{
    ifstream file;
    ofstream out;
    
    out.open("/Users/hivamoh/Desktop/CS 136/Labs/CS 136 Lab 1 FINALL/ErrorFile.txt");
    //Open and check file
    file.open("/Users/hivamoh/Desktop/CS 136/Labs/CS 136 Lab 1 FINALL/Lab1 file.txt");
    if (!file)
    {
        cout << "ERROR: File not found."<< endl;
        exit(1);

    }
    else
    {

        //Input Data
        while (!file.eof() && totalItems < MAX_SIZE)
        {
            items[totalItems] = new itemType;
            file >> items[totalItems]->ID >> items[totalItems]->Name >> items[totalItems]->quantityOnHand >> items[totalItems]->Price;

            for (int i = 0; i < items[totalItems]->Name.size(); i++)
                items[totalItems]->Name.at(i) = toupper(items[totalItems]->Name.at(i));
            if (items[totalItems]->quantityOnHand < 0 || items[totalItems]->Price < 0) {
                out << left  << setw(11) << items[totalItems]->ID << setw(30) << items[totalItems]->Name
                    << right << setw(5) << items[totalItems]->quantityOnHand << setw(8) << setprecision(2) << right << items[totalItems]->Price << endl;

            }
            else
            {
                items[totalItems] = items[totalItems];
                totalItems++;
            }

        }
        if (totalItems == 0)
        {
            cout << "File is empty. Program terminates." << endl;
            exit(0);
        }
        else if (totalItems > 100)
        {
            cout << "Too many items in the file. Program terminates." << endl;
            exit(0);
        }
        out.close();
        return totalItems;

    }



}

void printInventory(itemType *items[], int counter) {
    cout << "\nID         ITEM NAME                  QUANTITY   PRICE" << endl; //Header
                                                                                      //Loop through data and output
    for (int j = 0; j < counter; j++) {
        cout << left << setw(11) << items[j]->ID << setw(30) << items[j]->Name << right << setw(5)
            << items[j]->quantityOnHand << setw(8) << setprecision(2) << right << items[j]->Price << endl;
    }
    cout << "\n" << endl;
}

void searchForItem(itemType *items[], int totalItems) {
    bool isFound = false;
    string userInput;
    int i = 0;
    cout << "\nPlease enter your search query: ";
    cin >> userInput;
    for (int i = 0; i < userInput.size(); i++)
        userInput.at(i) = toupper(userInput.at(i));

    while (i < totalItems && !isFound) {
        //Compare the input to IDs and item names simultaneously
        if (items[i]->ID == userInput || items[i]->Name == userInput) {
            cout << "FOUND ITEM:\n\nID         ITEM NAME                     QUANTITY      PRICE" << endl;
            cout << left << setw(11) << items[i]->ID << setw(30) << items[i]->Name << setw(11)
                << items[i]->quantityOnHand << setw(8) << setprecision(2) << right << items[i]->Price << endl << endl;
            isFound = true;
        }
        i++;
    }
    if (isFound == false)
        cout << "\nERROR: Item not found.\n" << endl;
}

void printReport(int totalItems, itemType *items[]) {
    double totalWorthOfInventory = 0;
    int quantities = 0;
    for (int i = 0; i < totalItems; i++)
        totalWorthOfInventory = totalWorthOfInventory + items[i]->Price * items[i]->quantityOnHand;
    for (int i = 0; i < totalItems; i++) {
        quantities += items[i]->quantityOnHand;
    }
    cout << "\nINVENTORY REPORT\n" << endl;
    cout << "There are " << totalItems << " unique items in the inventory." << endl;
    cout << setprecision(2) << "The total worth of the inventory is $" << totalWorthOfInventory << endl;
    cout << "There are " << quantities << " quantities in the inventory.\n" << endl;
}

void bubbleSort(int userInput, int totalItems, itemType *items[]) {
    bool toSwap = false;
    for (int i = 0; i < totalItems - 1; i++)
        for (int j = 0; j < totalItems - i - 1; j++) {
            switch (userInput)
            {
            case 1: toSwap = items[j]->ID > items[j + 1]->ID;
                break;
            case 2: toSwap = items[j]->Name > items[j + 1]->Name;
                break;
            case 3: toSwap = items[j]->quantityOnHand > items[j + 1]->quantityOnHand;
                break;
            case 4: toSwap = items[j]->Price > items[j + 1]->Price;
                break;
            }
            if (toSwap == true)
            {
                itemType *temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
}


void sortMenu(itemType *items[], int totalItems) {
    int userInput = 0;
    while (userInput < 1 || userInput > 5) {
        cout << "\nInvalid input. Please enter a proper value, from 1 to 5.\n" << endl;
        cin.clear();
        cin.ignore(255, '\n');
        cout << "\nEnter your choice from 1-5: "<< endl;
        cout << "1. to sort by item ID."<< endl;
        cout << "2. to sort by item name."<< endl;
        cout << "3. to sort by quantity on hand." << endl;
        cout << "4. to sort by item price." << endl;
        cout << "5. to return to the main menu." << endl;
        cin >> userInput;
    }
    if (userInput != 5)
        bubbleSort(userInput, totalItems, items);
    printInventory(items, totalItems);
}

void displayMenu(itemType *items[], int totalItems) {
    int userInput = 0;
    //Menu will re-display as long as user does not choose to quit
    while (userInput != 5)
    {
        cout << "Enter your choice from 1-5: " << endl;
        cout << "1. to print the inventory." << endl;
        cout << "2. to search for an item by ID or name." << endl;
        cout << "3. to sort the inventory by a specific field." << endl;
        cout << "4. to print an inventory report." << endl;
        cout << "5. to exit the program.\n" << endl;
        cin >> userInput;
        
        switch (userInput) {
        case 1:
            printInventory(items, totalItems);
            break;
        case 2:
            searchForItem(items, totalItems);
            break;
        case 3:
            sortMenu(items, totalItems);
            break;
        case 4:
            printReport(totalItems, items);
            break;
        case 5:
            break;
        default:
            cout << "\nInvalid input. Please enter a proper value, from 1 to 5.\n" << endl;
            cin.clear();
            cin.ignore(255, '\n');
        }
    }
}




/*
Test Data
019472306 Violin 10 -130.45
481404928 Synthesizer 45 132.75
110372200 Guitar -5 96.00
880125535 Trumpet 15 212.40
367729102 Flute -7 70.99
490328917 Cello 3 348.59
agj902934 Piano    5 989.99
757109429 Drumset 10 457.00
123980123 Obo 20 -99.99
489012389 Clarinet 79.89
*/
/*
Welcome!

Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

hjhfjdfh

Invalid input. Please enter a proper value, from 1 to 5.

Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

7

Invalid input. Please enter a proper value, from 1 to 5.

Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

1

ID         ITEM NAME                  QUANTITY   PRICE
481404928  SYNTHESIZER                      45  132.75
880125535  TRUMPET                          15  212.40
490328917  CELLO                             3  348.59
agj902934  PIANO                             5  989.99
757109429  DRUMSET                          10  457.00
489012389  CLARINET                         79    0.89


Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

2

Please enter your search query: piamo

ERROR: Item not found.

Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

2

Please enter your search query: pianO
FOUND ITEM:

ID         ITEM NAME                     QUANTITY      PRICE
agj902934  PIANO                         5            989.99

Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

2

Please enter your search query: 481404928
FOUND ITEM:

ID         ITEM NAME                     QUANTITY      PRICE
481404928  SYNTHESIZER                   45           132.75

Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

3

Invalid input. Please enter a proper value, from 1 to 5.


Enter 1-5:
1 to sort by item ID.
2 to sort by item name.
3 to sort by quantity on hand.
4 to sort by item price.
5 to return to the main menu.

1

ID         ITEM NAME                  QUANTITY   PRICE
481404928  SYNTHESIZER                      45  132.75
489012389  CLARINET                         79    0.89
490328917  CELLO                             3  348.59
757109429  DRUMSET                          10  457.00
880125535  TRUMPET                          15  212.40
agj902934  PIANO                             5  989.99


Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

3

Invalid input. Please enter a proper value, from 1 to 5.


Enter 1-5:
1 to sort by item ID.
2 to sort by item name.
3 to sort by quantity on hand.
4 to sort by item price.
5 to return to the main menu.

2

ID         ITEM NAME                  QUANTITY   PRICE
490328917  CELLO                             3  348.59
489012389  CLARINET                         79    0.89
757109429  DRUMSET                          10  457.00
agj902934  PIANO                             5  989.99
481404928  SYNTHESIZER                      45  132.75
880125535  TRUMPET                          15  212.40


Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

3

Invalid input. Please enter a proper value, from 1 to 5.


Enter 1-5:
1 to sort by item ID.
2 to sort by item name.
3 to sort by quantity on hand.
4 to sort by item price.
5 to return to the main menu.

4

ID         ITEM NAME                  QUANTITY   PRICE
489012389  CLARINET                         79    0.89
481404928  SYNTHESIZER                      45  132.75
880125535  TRUMPET                          15  212.40
490328917  CELLO                             3  348.59
757109429  DRUMSET                          10  457.00
agj902934  PIANO                             5  989.99


Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

3

Invalid input. Please enter a proper value, from 1 to 5.


Enter 1-5:
1 to sort by item ID.
2 to sort by item name.
3 to sort by quantity on hand.
4 to sort by item price.
5 to return to the main menu.

5

Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

4

INVENTORY REPORT

There are 6 unique items in the inventory.
The total worth of the inventory is $19795.78
There are 157 quantities in the inventory.

Enter 1-5:
1 to print the inventory.
2 to search for an item by ID or name.
3 to sort the inventory by a specific field.
4 to print an inventory report.
5 to exit the program.

5
Press any key to continue . . .
*/
