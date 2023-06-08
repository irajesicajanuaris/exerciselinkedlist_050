#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** s, Node** ira);
	bool listEmpty();
	bool delNode();
	void traverse();


};
void CircularLinkedList::addNode() {	//untuk menambahkan Node baru ke dalam circularlinkedlist dan untuk memasukkan rollnumber serta nama node baru
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student : ";
	cin.ignore();
	getline(cin, nm);
	Node* NewNode = new Node();
	NewNode->rollNumber = nim;
	NewNode->name = nm;

	if (LAST == NULL || nim <= LAST->rollNumber) {
	}

}

bool CircularLinkedList::search(int rollno, Node** s, Node** ira) {		//untuk mencari node dengan nomor rollnumber tertentu, mengembalikan 2 pointer yaitu pointer prev dan curr
	*s = LAST->next;
	*ira = LAST->next;

	while (*ira != LAST) {
		if (rollno == (*ira)->rollNumber) {
			return true;
		}
		*s = *ira;
		*ira = (*ira)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {	//untuk mengembalikan nilai true jika circularlinkedlist kosong, false jika berisi node
	return LAST == NULL;
}
bool CircularLinkedList::delNode() {//untuk menghapus node dari circularlinkedlist mengikuti rollnumber yang telah dimasukkan user
	if (listEmpty()) {
		cout << "list is empty " << endl;
		return false;
	}
	if (LAST->next == LAST) {
		Node* ira = LAST->next;
		LAST->next = ira->next;
		delete ira;
	}
}
void CircularLinkedList::traverse() {	//untuk menampilkan semua node dalam circularlinkedlist
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}