# Inventory of a Factory
A modularized, menu-driven program to read a file with the unknown number of records.

The input file has an unknown number of records of inventory items (may be empty); one record per line in the following  order: item ID, item  name (one word), quantity on hand, and a price 
All fields in the input file are separated by a tab (‘\t’) or a blank ( up to you)
All items are unique
Item Id and name do not require error checking
Create a menu (use a switch statement) which allows to
print the inventory unsorted
print the inventory sorted in ascending order;  you should allow a user sort by any field: item ID, item name (one word), quantity on hand, or price. Write one function, that can sort by any field using array of pointers. Do not copy and paste sort code five times into the same function. Bubble sort  is the easiest to modify.
search  for an item by ID or name; a user should be able to enter the name of the item using any case, (for example, sTRolleR). You may wish to store items in all lower/upper case to expedite the search. 
print a report with the following details
number of  unique items in the inventory
the total worth of the inventory and the total count of all items in the inventory
quit the program
A user  should be able to run many as many times as a user wants
Use array of structs if you do not know how to write classes yet
Thoroughly test your program. Your grade partially depends on the quality of your test data.
This a and all other  programs in this course  must comply with the Guidelines and Standards posted under Resources 
Clearly label the output

Sample File:

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

