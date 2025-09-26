//Name: Tram, Khang and Quynh
//Date: 09/25/2025
//Description: Chapter 5 - Vector and List Container

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include "input.h"
#include"Student.h"
using namespace std;


//==================================================================================================================
//			                                       PROTOTYPES
//==================================================================================================================
void mainMenu();
void VectorFunction();
void VectorMenu();
void displayVector(const vector<student>& v);

//==================================================================================================================
//			                                         MAIN
//==================================================================================================================

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
		case 2:
			break;
		case 3:
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


//==================================================================================================================
//			                                         VECTOR
//==================================================================================================================
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
			/*  If new_size < old_size → shrink, remove from the end.

				If new_size > old_size → grow, add default - constructed elements(unknown, unknown, 0.0 in your case).

				If new_size == old_size → nothing happens.

				once you shrink a vector with resize() (or erase()), the elements that were removed

				are destroyed — their memory is gone. There is no automatic way to recover them.


			*/
		}
		break;
		case 'D':
		{
			/*ifstream fin("input.dat", ios::binary);
			if (!fin) {
				cout << "The input file, INPUT.DAT, does not exist.\n";
				break;
			}

			v.clear();
			while (true) {
				size_t nameLen, gradeLen;
				if (!fin.read((char*)&nameLen, sizeof(nameLen))) break;

				string name(nameLen, '\0');
				fin.read(&name[0], nameLen);

				fin.read((char*)&gradeLen, sizeof(gradeLen));
				string grade(gradeLen, '\0');
				fin.read(&grade[0], gradeLen);

				double gpa;
				fin.read((char*)&gpa, sizeof(gpa));

				student s;
				s.setName(name);
				s.setGradeLevel(grade);
				s.setGPA(gpa);

				v.push_back(s);
			}
			fin.close();

			cout << "\n\tThe vector now has " << v.size() << " elements.\n\n";
			for (size_t i = 0; i < v.size(); i++) {
				cout << "\t[" << i << "]: " << v[i] << "\n";
			}
			break;*/

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
			/*if (v.size() >= 2)
			{
				size_t start, end;
				cout << "\n\tEnter starting index (0.." << v.size() - 1 << "): ";
				cin >> start;
				cout << "\n\tEnter ending index (0.." << v.size() - 1 << "): ";
				cin >> end;

				if (start <= end && end < v.size())
				{
					auto start_it = v.begin() + start;
					auto end_it = v.begin() + end + 1;

					cout << "\n\tRemoving elements from index [" << start << "] to [" << end << "]...\n";

					v.erase(start_it, end_it);

					cout << "\n\tThe vector now has " << v.size() << " element(s).\n";
					for (size_t i = 0; i < v.size(); i++)
					{
						cout << "\t[" << i << "]: " << v[i] << "\n";
					}
				}
				else
				{
					cout << "\n\tInvalid range. Must be within 0.." << v.size() - 1 << " and start <= end.\n";
				}
			}
			else {
				cout << "\n\tThe vector has fewer than 2 elements. Nothing to erase.\n";
			}*/

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

			displayVector(v);

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
