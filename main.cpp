#include "single.h"
#include "employee.h"

using namespace std;

int main() {
	SingleLinkedList List;
	Item_Type item;
	// linked list
	for (int i = 5; i > 0; i--)
	{
		item.size = i;
		List.push_back(item);
	}
	cout << "List contents: " << endl;
	List.printSingleLinkedList();

	cout << "Testing pop_front(): " << endl;
	List.pop_front();
	List.printSingleLinkedList();

	cout << "Testing pop_back(): " << endl;
	List.pop_back();
	List.printSingleLinkedList();

	cout << "Testing push_front(): " << endl;
	item.size = 20;
	List.push_front(item);
	List.printSingleLinkedList();

	cout << "Testing push_back(): " << endl;
	item.size = 25;
	List.push_back(item);
	List.printSingleLinkedList();

	cout << "Testing insert():  " << endl;
	item.size = 55;
	List.insert(4, item);
	List.printSingleLinkedList();

	cout << "Testing remove(): " << endl;
	List.remove(3);
	List.printSingleLinkedList();

	cout << "Find value 4" << endl;
	item.size = 4;
	cout << "Found at index: " << List.find(item) << endl << endl;

	cout << "Front: " << List.front()->item.size << endl;
	cout << "Back: " << List.back()->item.size << endl;
	cout << "Size: " << List.getNumItems() << endl << endl;

  //part 2
  //Creating object of Professional employee
  cout <<"**PART 2**" << endl << endl;
	cout << "PROFESSIONAL EMPLOYEE " << endl;
	ProfessionalEmployee professional("Jake", "T-mobile", 12000);
	professional.print();
	cout << "Weekly Salary: " << professional.weeklySalary() << endl;
	cout << "Health care: $: " << professional.insurance() << endl;
	cout << "Vacations: " << professional.vacations() << endl << endl;

	//Creating object of non professional employee
	cout << "NONPROFESSIONAL EMPLOYEE " << endl;
	NonProfessionalEmployee nonprofessional("Gaurav", "UMKC", 20, 12);
	nonprofessional.print();
	cout << "Weekly Salary: " << nonprofessional.weeklySalary() << endl;
	cout << "Health care: $ " << nonprofessional.insurance() << endl;
	cout << "Vacations: " << nonprofessional.vacations() << endl << endl;
  
}