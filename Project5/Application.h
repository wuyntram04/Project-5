#pragma once
#include <list>     //For list
#include <map>      //For maps, used in frequencies
#include <iostream> //For overloaded function
#include <sstream>  //For displaying data types, used in frequencies
#include <algorithm> //for find
#include <string>   //For string
#include <sstream>  //For displaying data types, used in frequencies
#include <algorithm> //for find
#include <string>   //For string
using namespace std;

class Application {
private:
	typedef int value_type;
	list<value_type> user_val_list;

public:
	//CONSTRUCTOR
	Application(); //Default

	//MUTATORS
	void set_List(const value_type&);
	void delete_List(const value_type&);

	//ACCESSORS
	bool get_Empty() const;
	string get_Freq() const;

	//FRIEND
	friend ostream& operator <<(ostream& out, const Application&);
};

//Precondition : N/A
//Postcondition: N/A
Application::Application() {}


//Precondition : Integer new_Value
//Postcondition: Pushes in typedef value into back of list
void Application::set_List(const value_type& new_Val) 
{
	user_val_list.push_back(new_Val);
}

//Precondition : Integer user_Val
//Postcondition: Either returns if element is not in list, or erases it
void Application::delete_List(const value_type& user_Val) 
{
	list<value_type>::iterator find_element = find(user_val_list.begin(), user_val_list.end(), user_Val);

	if (find_element == user_val_list.end()) {
		throw invalid_argument("list does not contain");
	}

	user_val_list.erase(find_element);
}


//Precondition : N/A
//Postcondition: Returns true if list is empty, else false
bool Application::get_Empty() const 
{
	return (user_val_list.empty());
}

//Precondition : Class must be filled in
//Postcondition: Returns string showing frequencies of each number
string Application::get_Freq() const 
{
	ostringstream ostream;
	map<value_type, int> Sorted_Map;
	ostream << "\n\tcontainer:";

	for (auto begin = user_val_list.begin(); begin != user_val_list.end(); ++begin) {
		++Sorted_Map[(*begin)];
	}

	for (auto begin = Sorted_Map.begin(); begin != Sorted_Map.end(); ++begin) {
		ostream << "\n\t" << begin->first << ": " << begin->second;
	}

	return ostream.str();
}



//Precondition : ostream, and class object, list must not be empty
//Postcondition: Returns an ostream for display
ostream& operator <<(ostream& out, const Application& obj)
{
	out << "\n\tcontainer: ";

	for (auto begin = obj.user_val_list.begin(); begin != obj.user_val_list.end(); ++begin) {
		out << (*begin) << " ";
	}

	return out;
}
