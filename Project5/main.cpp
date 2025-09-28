#include <iostream>
#include <fstream>
#include <vector>
#include <list>
//------------------
#include "input.h"
#include "Student.h"

using namespace std;

//PROTOTYPE

void menu();

void vectorMenu();

void listMenu();
void listOperation();
void list_PushTo(list<student>&, bool);

int main()
{
	menu();
}

void menu()
{
	while (true)
	{
		system("cls");
		cout << "\n\tCMPR131 Chapter 5: Vector and List Container by Minh & Thinh (09/22/2025)";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\t1> Vector container";
		cout << "\n\t\t2> List container";
		cout << "\n\t\t3> Application using Vector and/or List container";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> exit";
		cout << "\n\t" << string(80, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 3))
		{
		case 1:
			//vectorMenu();
			break;
		case 2:
			listOperation();
			break;
		case 3:
			break;
		case 0:
			return;
		}
		
		system("pause");
	}
}

void vectorMenu()
{

	vector<int> vector_container;

	while (true)
	{
		system("cls");

		cout << "\n\tVectors are sequence containers representing arrays that can change in size.";
		cout << "\n\n\t1> Vector's member functions";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)";
		cout << "\n\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements";
		cout << "\n\t\tC> resize(n) - Resizes the container so that it contains n elements";
		cout << "\n\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector";
		cout << "\n\t\tE> pop_back() - Removes the last element in the vector";
		cout << "\n\t\tF> front() - Returns a reference to the first element in the vector";
		cout << "\n\t\tG> back() - Returns a reference to the last element in the vector";
		cout << "\n\t\tH> index using at() or []) - Returns a reference to the element at position n in the vector";
		cout << "\n\t\tI> begin() - Returns an iterator pointing to the first element in the vector";
		cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the vector";
		cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the vector";
		cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector";
		cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first";
		cout << "\n\t\t            element in the vector";
		cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the vector";
		cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
		cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)";
		cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
		cout << "\n\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type";
		cout << "\n\t\tS> Sort - Sorts the vector.";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tOption: ";

	}
}


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
