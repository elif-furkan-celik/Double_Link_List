/*
 * DoublyLinkedListProgram.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: feyzahafizoglu
 */

#include <iostream>
#include "DoublyIntLinkedList.h"

using namespace std;

int main() {

	DoublyIntLinkedList list;

	if(list.empty())
		cout << "List is empty\n";

	list.add(1, 0);
	list.print();

	list.add(3);
	list.print();

	list.add(7);
	list.print();

	list.add(5, 0);
	list.print();

	list.add(4, 2);
	list.print();

	list.add(9, 4);
	list.print();

	list.add(2, 6);
	list.print();

	list.add(11);
	list.print();

	list.add(8, 1);
	list.print();

	cout << "Index of 5 is " << list.indexOf(5) << endl;
	if(list.indexOf(13) == -1)
		cout << "13 does not exist in the list \n";


	list.remove(0);
	list.print();

	list.remove(7);
	list.print();

	cout << "The size of the list is " << list.size() << endl;

	list.clear();

	cout << "After clearing, the size of the list is " << list.size() << endl;

	return 0;
}


/*

THE OUTPUT OF THE PROGRAM

List is empty
front ->	1
front ->	1 3
front ->	1 3 7
front ->	5 1 3 7
front ->	5 1 4 3 7
front ->	5 1 4 3 9 7
front ->	5 1 4 3 9 7 2
front ->	5 1 4 3 9 7 2 11
front ->	5 8 1 4 3 9 7 2 11
Index of 5 is 0
13 does not exist in the list
front ->	8 1 4 3 9 7 2 11
front ->	8 1 4 3 9 7 2
The size of the list is 7
After clearing, the size of the list is 0

*/
