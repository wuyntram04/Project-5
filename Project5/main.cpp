#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
//------------------
#include "input.h"
#include "Student.h"
#include "Application.h"

using namespace std;

//PROTOTYPE

void mainMenu();

void VectorFunction();
void VectorMenu();
void displayVector(const vector<student>& v);

void listMenu();
void listOperation();
void list_PushTo(list<student>&, bool);

void VectorListContainer();
void menu3();

int main()
{

	do
	{
		system("cls");
		mainMenu();
		switch (inputInteger("\n\tOption: ", 0, 3))
		{
		case 1: VectorFunction();
			break;
		case 2: listOperation();
			break;
		case 3: VectorListContainer();
			break;
		case 0: exit(0);
		}

	} while (true);

	return EXIT_SUCCESS;

}

void mainMenu()
{
	cout << "\n\tCMPR131 Chapter 5: Vector and List Container by Khang Quach, Tram Ho, Quynh Pham (09/24/2025) ";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\t1> Vector container";
	cout << "\n\t\t2> List container";
	cout << "\n\t\t3> Application using Vector and/or List container";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(80, char(205));
}


void VectorMenu()
{
	cout << "\n\tVectors are sequence containers representing arrays that can change in size.\n";
	cout << "\n\t1> Vector's member functions";
	cout << "\n\t" << string(107, char(205));
	cout << "\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)\n";
	cout << "\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements\n";
	cout << "\t\tC> resize(n) - Resizes the container so that it contains n elements\n";
	cout << "\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector\n";
	cout << "\t\tE> pop_back() - Removes the last element in the vector\n";
	cout << "\t\tF> front() - Returns a reference to the first element in the vector\n";
	cout << "\t\tG> back() - Returns a reference to the last element in the vector\n";
	cout << "\t\tH> index using at() or [] - Returns a reference to the element at position n in the vector\n";
	cout << "\t\tI> begin() - Returns an iterator pointing to the first element in the vector\n";
	cout << "\t\tJ> end() Returns an iterator referring to the past-the-end element in the vector\n";
	cout << "\t\tK> Using iterator begin() and end() returns all elements in the vector\n";
	cout << "\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector\n";
	cout << "\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first\n";
	cout << "\t\t            element in the vector\n";
	cout << "\t\tN> Using iterator rbegin() and rend() returns all elements in the vector\n";
	cout << "\t\tO> erase(it) - Removes from the vector a single element(using an iterator)\n";
	cout << "\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)\n";
	cout << "\t\tQ> insert(it, entry) - Insert a new entry at the iterator.\n";
	cout << "\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type\n";
	cout << "\t\tS> Sort - Sorts the vector.";
	cout << "\n\t" << string(107, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(107, char(205));
}

void VectorFunction()
{
	vector<student> v;
	do {
		system("cls");
		VectorMenu();
		switch (toupper(inputChar("\n\tOption: ")))
		{
		case 'A':
		{

			v.clear();
			if (v.empty())
			{
				cout << "\n\tThe vector now has " << v.size() << " elements.";
				cout << "\n\n\tThe vector has been cleared.";
			}
		}
		break;
		case 'B':
		{
			int n = inputInteger("\n\tEnter the capacity(1..100): ", 1, 100);
			v.reserve(n);
			cout << "\n\tThe vector currently holds " << v.size() << " element(s).";
			cout << "\n\tThe vector's capacity (reserved space) is " << v.capacity() << " element(s).\n";
			//number of elements it can store without reallocating

		}
		break;
		case 'C':
		{
			int s = inputInteger("\n\tEnter the new size(1..100): ", 1, 100);
			v.resize(s);

			cout << "\n\tThe vector has been resized to " << v.size() << " element(s).\n\n";

			displayVector(v);
			
		}
		break;
		case 'D':
		{

			ifstream fin("input.dat");
			if (!fin)
			{
				cout << "The input file, INPUT.DAT, does not exist.\n";
				break;
			}

			string line;
			/*v.clear();*/

			while (getline(fin, line))
			{

				if (line.empty()) continue;

				stringstream ss(line);
				string name, grade, gpaStr;

				getline(ss, name, ',');
				getline(ss, grade, ',');
				getline(ss, gpaStr);

				// trim leading spaces
				if (!name.empty() && name[0] == ' ') name.erase(0, 1);
				if (!grade.empty() && grade[0] == ' ') grade.erase(0, 1);

				double gpa = stod(gpaStr);

				student s;
				s.setName(name);
				s.setGradeLevel(grade);
				s.setGPA(gpa);

				v.push_back(s);
			}
			fin.close();

			cout << "\n\tThe vector now has " << v.size() << " elements.\n\n";
			displayVector(v);
			break;
		}
		case 'E':
		{
			if (!v.empty()) {
				cout << "\n\tElement [" << v.size() - 1 << "]: " << v.back()
					<< ", has been removed from the vector.\n";
				v.pop_back();
			}
			else
			{
				cout << "\n\tThe vector is already empty. Nothing to remove.\n";
			}

			cout << "\n\tThe vector now has " << v.size() << " element(s).\n\n";
			displayVector(v);
			break;
		}
		case 'F':
		{
			if (!v.empty())
			{
				cout << "\n\tThe first element in the vector is:\n";
				cout << "\t[0]: " << v.front() << "\n";
			}
			else
			{
				cout << "\n\tThe vector is empty. No first element.\n";
			}
			break;
		}
		case 'G':
		{
			if (!v.empty())
			{
				cout << "\n\tThe last element in the vector is:\n";
				cout << "\t[" << v.size() - 1 << "]: " << v.back() << "\n";
			}
			else {
				cout << "\n\tThe vector is empty. No last element.\n";
			}
			break;
		}
		case 'H':
		{
			if (!v.empty())
			{
				int last = v.size() - 1;
				int index = inputInteger("\n\tEnter the index (0.." + to_string(v.size() - 1) + "): ", 0, last);

				if (index < v.size()) {
					cout << "\n\tElement at [" << index << "] using at(): " << v.at(index) << "\n";
					cout << "\tElement at [" << index << "] using []  : " << v[index] << "\n";
				}
				else {
					cout << "\n\tInvalid index. The vector has only " << v.size() << " elements.\n";
				}
			}
			else {
				cout << "\n\tThe vector is empty. No elements to access.\n";
			}
			break;
		}
		case 'I':
		{
			if (!v.empty())
			{
				auto it = v.begin();
				cout << "\n\tThe iterator referring the first element: " << &(*it) << "(" << *it << ")";
			}
			else {
				cout << "\n\tThe vector is empty. No first element to show.\n";
			}
		}
		break;
		case 'J':
		{
			if (!v.empty())
			{
				auto itEnd = v.end();

				cout << "\n\tThe iterator referring to the past-the-end element: " << &(*(--itEnd)) + 1 << " (" << v.back() << ")\n";

			}
			else
			{
				cout << "\n\tThe vector is empty. end() equals begin(). No elements available.\n";
			}
			break;
		}
		case 'K':
		{
			if (!v.empty())
			{

				int index = 0;
				cout << "\n";
				for (auto it = v.begin(); it != v.end(); ++it, ++index)
				{
					cout << "\t[" << index << "]: " << &(*it)
						<< " (" << *it << ")\n";
				}
			}
			else {
				cout << "\n\tThe vector is empty. No elements to display.\n";
			}
			break;
		}
		case 'M':
		{
			if (!v.empty())
			{
				auto rit = v.rend();

				cout << "\tThe reverse iterator pointing to the last element: " << &(*rit) << "(" << v.front() << ")\n";
			}
			else
			{
				cout << "\n\tThe vector is empty. rend() equals rbegin(). No elements available.\n";
			}
			break;
		}
		case 'N':
		{
			if (!v.empty()) {
				cout << "\n\tUsing rbegin() and rend(), the vector contains (in reverse order):\n";
				int index = v.size() - 1;

				for (auto rit = v.rbegin(); rit != v.rend(); ++rit, --index)
				{
					cout << "\t[" << index << "]: " << &(*rit)
						<< " (" << *rit << ")\n";
				}
			}
			else
			{
				cout << "\n\tThe vector is empty. No elements to display.\n";
			}
			break;
		}
		case 'O':
		{
			if (!v.empty())
			{
				auto it = v.begin();
				cout << "\n\tAn element after the begin iterator " << &(*it)
					<< " (" << *it << ") has been removed.\n";

				v.erase(it);
			}
			else {
				cout << "\n\tThe vector is empty. Nothing to erase.\n";
			}

			cout << "\n\tThe vector now has " << v.size() << " element(s).\n\n";
			displayVector(v);
			break;
		}
		case 'P':
		{

			if (v.empty())
			{
				cout << "\n\tThe vector is empty.";
				break;
			}
			auto start = v.begin();
			auto end = v.end();

			cout << "\n\t\tAll elements starting at begin iterator " << &(*start) << " and going up to end iterator " << &(end) << " has been removed.\n";

			v.erase(start, end);
		}
		break;
		case 'Q':
		{
			student newStudent;
			string names[] = { "Freshman", "Sophmore", "Junior", "Senior" };


			newStudent.setName(inputString("\n\t\tEnter a new student name: ", true));

			int number = inputInteger("\n\t\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
			newStudent.setGradeLevel(names[number - 1]);

			newStudent.setGPA(inputDouble("\n\t\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0));

			int pos = 0;
			int size = v.size();
			if (!v.empty())
			{
				pos = inputInteger("\n\t\tEnter position to insert (0.." + to_string(v.size()) + "): ", 0, size);
			}

			auto it = v.begin() + pos;
			v.insert(it, newStudent);

			cout << "\n\t\tThe new element has been inserted at index [" << pos << "].\n";

			cout << "\n\t\tThe vector now has " << v.size() << " elements:\n";
			displayVector(v);

			break;
		}
		case 'R':
		{
			vector<student> v2;
			cout << "\n\t\tvector (v2) is initially empty.\n";
			v2.swap(v);

			cout << "\n\t\tvector (v1) is empty after swapped with vector (v2).\n";
			cout << "\n\t\tvector (v2) after swapped with vector (v1).\n";

			displayVector(v2);

			break;
		}

		case 'S':
		{
			if (v.empty())
			{
				cout << "\n\tThe vector is empty.";
				break;
			}
			cout << "\n\tVector has been sorted\n";

			cout << endl;
			sort(v.begin(), v.end());

			displayVector(v);

			break;
		}
		case '0': return;
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);
}

void displayVector(const vector<student>& v)
{
	if (v.empty())
	{
		cout << "\t<empty>\n";
		return;
	}

	for (size_t i = 0; i < v.size(); i++) {
		cout << "\t[" << i << "]: " << v[i] << "\n";
	}
}

// -----------------------------LINKED-LIST---------------------------------------

void listMenu()
{

		cout << "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the";
		cout << "\n\tsequence, and iteration in both directions.";
		cout << "\n\n\t2> List container";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA> clear() - Destroys all elements from the list";
		cout << "\n\t\tB> resize(n) - Changes the list so that it contains n elements";
		cout << "\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list";
		cout << "\n\t\tD> pop_front() - Deletes the first element";
		cout << "\n\t\tE> front() - Accesses the first element";
		cout << "\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list";
		cout << "\n\t\tG> pop_back() - Delete the last element";
		cout << "\n\t\tH> back() Accesses the last element";
		cout << "\n\t\tI> begin() - Returns an iterator refereing to the first element in the list";
		cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list";
		cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the list";
		cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list";
		cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element";
		cout << "\n\t\t            in the list";
		cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list";
		cout << "\n\t\tO> erase(it) - Removes from the list a single element(using an iterator)";
		cout << "\n\t\tP> erase(start_it,end_it) - Removes from the list a range of elements( using iterators)";
		cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
		cout << "\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type";
		cout << "\n\t\tS> Sort - Sorts the list.";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(80, char(205));

}

void listOperation()
{
	list<student> stud_list;

	while (true)
	{
		system("cls");

		listMenu();


		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHIJKLMNOPQRS0"))))
		{
		case 'A':
			stud_list.clear();
			cout << "\n\t\tThe list has been cleared.";
			break;
		case 'B':
			stud_list.resize(inputInteger("\n\t\tEnter the new size(1..100): ", 1, 100));
			cout << "\n\t\tThe list has been resized to " << stud_list.size() << " elements.";
			break;
		case 'C':
			list_PushTo(stud_list, true);
			break;
		case 'D':
			if (!stud_list.empty())
			{
				cout << "\n\t\tFirst element, (" << stud_list.front() << "), has been removed from the list.";
				stud_list.pop_front();
				cout << "\n\n\t\tThe list now has " << stud_list.size() << " elements.\n";

				for (auto it = stud_list.begin(); it != stud_list.end(); it++)
				{
					cout << "\n\t\t\t" << *it;
				}
			}else
				cout << "\n\t\tThe list is empty.";
			break;
		case 'E':
			if (!stud_list.empty())
				cout << "\n\t\tFirst element from the list is (" << stud_list.front() << ").";
			else
				cout << "\n\t\tThe list is empty.";
			break;
		case 'F':
			list_PushTo(stud_list, false);
			break;
		case 'G':
			if (!stud_list.empty())
			{
				cout << "\n\t\tLast element, (" << stud_list.back() << "), has been removed from the list.";
				stud_list.pop_back();
				cout << "\n\n\t\tThe list now has " << stud_list.size() << " elements.\n";

				for (auto it = stud_list.begin(); it != stud_list.end(); it++)
				{
					cout << "\n\t\t\t" << *it;
				}
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;
		case 'H':
			if (!stud_list.empty())
				cout << "\n\t\tLast element from the list is (" << stud_list.back() << ").";
			else
				cout << "\n\t\tThe list is empty.";
			break;
		case 'I':
			if (!stud_list.empty())
			{
				auto it = stud_list.begin();
				cout << "\n\t\tThe iterator referring the first element: " << &it << "(" << *it << ")";
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;
		case 'J':
			if (!stud_list.empty())
			{
				auto it = stud_list.end();
				cout << "\n\t\tThe iterator referring to the past-the-end element: " << &it;
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;
		case 'K':
			if (!stud_list.empty())
			{
				cout << "\n\t\tUsing begin() and end(), the list contains: ";
				for (auto it = stud_list.begin(); it != stud_list.end(); it++)
				{
					cout << "\n\t\t\t" << &*it << " (" << *it << ")";
				}
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;
		
		case 'L':
			if (!stud_list.empty())
			{
				auto it = stud_list.rbegin();
				cout << "\n\t\tThe iterator referring to the reverse first element: " << &it << " (" << *it << ")";
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;

		case 'M':
			if (!stud_list.empty())
			{
				auto it = stud_list.rend();
				cout << "\n\t\tThe iterator referring to the reverse past-the-end element: " << &it;
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;

		case 'N':
			if (!stud_list.empty())
			{
				cout << "\n\t\tUsing rbegin() and rend(), the list contains:";

				for (auto it = stud_list.rbegin(); it != stud_list.rend(); it++)
				{
					cout << "\n\t\t\t" << &*it << " (" << *it << ")";
				}
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;

		case 'O':
			if (!stud_list.empty())
			{
				auto it = stud_list.begin();
				stud_list.erase(it);
				cout << "\n\t\tAn element after the begin iterator " << &it << " has been removed.";
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;
		
		case 'P':
			if (!stud_list.empty())
			{
				auto start_it = stud_list.begin();
				auto end_it = stud_list.end();
				stud_list.erase(start_it, end_it);
				cout << "\n\t\tAll elements starting at begin iterator " << &start_it << " and going up to end iterator " << &end_it << " have been removed";
			}
			else
				cout << "\n\t\tThe list is empty.";
			break;
		case 'Q':
		{
			student stu;

			stu.setName(inputString("\t\tEnter a new student name: ", true));

			switch (inputInteger("\t\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4))
			{
			case 1:
				stu.setGradeLevel("Freshman"); break;
			case 2:
				stu.setGradeLevel("Sophmore"); break;
			case 3:
				stu.setGradeLevel("Junior"); break;
			case 4:
				stu.setGradeLevel("Senior"); break;
			}

			stu.setGPA(inputDouble("\t\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0));

			stud_list.insert(stud_list.begin(), stu);

			cout << "\n\t\tThe new element has been inserted after the begin iterator.";
		}
		break;

		case 'R':
		{
			list<student> stud_list2;

			if (stud_list2.empty())
				cout << "\n\t\tlist (l2) is initially empty.";

			stud_list.swap(stud_list2);

			if (stud_list.empty())
				cout << "\n\n\t\tlist (l1) is empty after swapped with list (l2).";

			if (stud_list2.empty())
				cout << "\n\n\t\tlist (l2) is empty.";
			else
				cout << "\n\n\t\tlist (l2) is now has " << stud_list2.size() << " element(s).";
		}
		break;

		case 'S':
		{
			if (!stud_list.empty())
			{
				stud_list.sort();
				cout << "\n\t\tSorted list: ";

				for (auto it = stud_list.begin(); it != stud_list.end(); it++)
				{
					cout << "\n\t\t\t" << &*it << " (" << *it << ")";
				}
			}
			else
				cout << "\n\t\tThe list is empty.";
		}
		break;

		case '0':
			cout << "\n";
			return;
			break;
		}

		cout << "\n\n";
		system("pause");

	}
}

void list_PushTo(list<student> &list, bool push_front)
{
	fstream dataFile;

	dataFile.open("input.dat", ios::in | ios::binary);

	if (dataFile.fail())
	{
		cout << "\n\tThe input file, INPUT.DAT, does not exist";
		return;
	}

	string name;
	string gradeLevel;
	string GPA;

	while (!dataFile.eof())
	{
		if (getline(dataFile, name, ',') && getline(dataFile, gradeLevel, ',') && getline(dataFile, GPA, '\n')) {

			student newStudent;
			newStudent.setName(name);
			newStudent.setGradeLevel(gradeLevel);
			newStudent.setGPA(stod(GPA));

			if (push_front)
				list.push_front(newStudent);
			else
				list.push_back(newStudent);
		}
	}
	
	dataFile.close();
	cout << "\n\t\tThe list now has " << list.size() << " elements.";

}

void VectorListContainer()
{
	Application list_Apply;

	do
	{
		system("cls");
		menu3();
		switch (toupper(inputChar("\n\t\tOption: ")))
		{
		case '0': return;
		case 'A': list_Apply.set_List(inputInteger("\n\tAdd an integer: ")); break;
		case 'B': {
			//if value is not in list, error
			int user_Value = inputInteger("\n\t Delete an integer: ");
			try {
				list_Apply.delete_List(user_Value);
			}
			catch (const invalid_argument& error) {
				cout << "\n\t" << error.what() << to_string(user_Value) << ".";
			}
		}break;
		case 'C': {
			if (list_Apply.get_Empty()) {
				cout << "\n\tERROR: Empty List. Please input integer (Option A)";
				break;
			}

			cout << list_Apply;
		}; break;
		case 'D': {
			if (list_Apply.get_Empty()) {
				cout << "\n\tERROR: Empty List. Please input integer (Option A)";
				break;
			}

			cout << list_Apply.get_Freq();
		}; break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

}

void menu3()
{
	cout << "\n\t3> Application using Vector and/or List container";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> Add an integer";
	cout << "\n\t\tB> Delete an integer";
	cout << "\n\t\tC> Display input integers";
	cout << "\n\t\tD> Display frequencies of integers";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205));

}
