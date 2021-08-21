//Submitted By Malik Ahmad (19l-1199)
//DSA Assignment 03
// The Torr Browser


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"mygraphics.h"

using namespace std;
template <class T>
class Node
{
public: T data;
		Node<T>* next;
};
template <class T>
class List
	
{
	Node<T>* head;
	Node<T>* tail;

	
public:
	
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	void insertAtEnd(T value) {
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;
		if (head == nullptr)
			
		{ head = tail = newNode; }
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
	}
	T RemoveAtEnd()
	{
		Node<T>* current = head;
		T data_;
		// Do nothing if list is already Empty 
		if (current != nullptr) {
			//One element
			if (head == tail)
			{
				data_ = current->data;
				head = tail = nullptr;
				delete current;
			}
			else
			{
				//Find second last element
				while (current->next != tail)
				{
					current = current->next;
				}
				tail = current;
				current = current->next;
				data_ = current->data;
				tail->next = nullptr;
				delete current;
			}
		}
		return data_;
	}
	bool isEmpty()
	{
		return head == nullptr;
	}
	void print() const
	{
		Node<T>* curr = head;
		while (curr != 0)
		{
			cout << curr->data << "  ";
			curr = curr->next;
		}

	}
	~List()
	{
		while (head != 0)
		{
			RemoveAtEnd();
		}
		
		// Write: Your Code here [1 mark]
	}
	//friend class Stack<T>;
};
template <class T>
class Stack 
{
	//Data Member:
	List<T>collection;
	

public:
		//Required Functions:

	void Push(T val) 
	{
		collection.insertAtEnd(val);
		
	}

	T Pop() 
	{
		return collection.RemoveAtEnd();
	
		
	}

	bool isEmpty() 
	{
		return collection.isEmpty();
		
	}

	bool isFull() 
	{
		cout << "Linkedlist cannot be full" << endl;
		return false;
	} //Think about this

	Stack() 
	{
		
	} 
	//default constructor: This will be empty

	~Stack() 
	{
		
	}
};
template <typename T>
class torr
{
private:

	Stack<string> history;
	Stack<string> redo;
	Stack<string> undo;

	int no_of_searches = 0;

public:

	torr()
	{

	}
	void url();                                                //Url,file_content,Undo,Redo
	bool search(Stack <string>& obj, string url__);             //Searching from Undo and Redo Stack
	void display(string filename);                               //Display Method
	string chr_to_string(char* a, int size);                  //We cannot write directly to string
	string extension_maker(string s);                             //Function to add extension to given url
	

};

template<typename T>
inline void torr<T>::url()
{
	drawRectangle(0, 0, 10, 600, 155, 0, 155, 155, 0, 155);
	drawRectangle(950, 0, 990, 600, 155, 0, 155, 155, 0, 155);
	drawRectangle(0, 0, 1000, 11, 25, 0, 250, 25, 0, 250);
	drawRectangle(0,470 , 1000, 800, 25, 0, 250, 25, 0, 250);
	cout << endl;
	cout << "_____________________________________Torr Browswer_____________________________________________________________________";
	cout << endl;
	cout << "   What do you want?" << endl;
	cout << "   Press 1 to Surf Websites" << endl;
	//cout << "Press 2 Undo the tab" << endl;
	//cout << "Press 3 to redo the tab" << endl;
	cout << "   Press 2 to view the history" << endl;
	int a;
	cin >> a;
	int redo_cnt = 0;

	if (a == 1)
	{
		
		drawRectangle(0, 0, 10, 600, 155, 0, 155, 155, 0, 155);
		//drawRectangle(0, 0, 195, 600, 155, 0, 155, 155, 0, 155);
		drawRectangle(0, 0, 1000, 11, 25, 0, 250, 25, 0, 250);
		drawRectangle(0, 470, 1000, 800, 25, 0, 250, 25, 0, 250);

		//Requirement 1

		cout << "Give Url";
		string url_;
		cin >> url_;
		string tmp2;                                                         //To add extension
		tmp2 = extension_maker(url_);
		history.Push(url_);                                             //Adding it to history
		no_of_searches++;

		ifstream file_C;
		string input;

		ofstream file;                                               //Saving history to file
		file.open("history.txt", std::ios_base::app);               //opening a file in text mode

		                                           //c_str() is a build in function to convert string into char[] because
		file_C.open(tmp2.c_str());                                 //you cannot use string in any opening mode
		if (file_C.is_open())
		{
			cout << "Your Search Result" << endl;

			while (getline(file_C, input))
			{
				cout << input << endl;
			}
			file_C.close();

			
			if (file.is_open())
			{
				
				
				file << url_<< "\n";
				file.close();
				
			}
		}
		else
		{
			cout << "Invalid Url";
			cout << endl;
		}

		char option;
		cout << "For Undo Press U & for Redo Press R" << endl;
		cin >> option;

		//Requirement 2

		if (option == 'U'|| option =='u')                            //Undo the Stack
		{
			if (this->no_of_searches < 2)
			{
				cout << "No recent tab is opened" << endl;
			}
			else
			{
				string temp1;
				temp1 = undo.Pop();
				redo.Push(url_);
				redo_cnt++;
				display(temp1);
				

			}
		}

		//Requirement 3


		if (option == 'R' || option == 'r')                            //Redo the Stack
		{
			if (this->no_of_searches < 2)
			{
				cout << "No recent tab is  opened" << endl;
			}
			else
			{
			   string temp2;
			  temp2 = redo.Pop();
			  display(temp2);
			}
		}

		
		cout << "Want to use browser again?" << endl;
		cout << "Press Y for yes & N for No" << endl;
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			undo.Push(url_);
			system("cls");

			url();

		}
		else
		{
			cout << "Thanks alot for using us" << endl; 
		}

	}

	//Requirement 4


	if (a == 2)
	{
		cout << "Want to search url from history?" << endl;
		cout << "Enter Url" << endl;
		string res;
		cin >> res;

		bool ab = search(undo, res);

		//Bonus Mark 1

		bool abc = search(redo, res);
		
			if (ab == true||abc==true)
			{
				cout << " You have visited this site" << endl;
				//display(history);
				{
					cout << endl;
					cout << "Past Window History\n" << endl;


					//Bonus Mark 2


					ifstream history;
					string output;
					history.open("history.txt");                                 //you cannot use string in any opening mode
					if (history.is_open())
					{


						while (getline(history, output))
						{
							cout << output << endl;
						}
						history.close();
					}
				}
			}
			if (ab != true && abc!=true)
			{
				cout << "You have Not visited this site" << endl;
			}
		
		/*cout << "Present Window History\n" << endl;*/
		
		
		//{
		//	cout << "Past Window History\n" << endl;

		//	ifstream history;
		//	string output;
		//	history.open("history.txt");                                 //you cannot use string in any opening mode
		//	if (history.is_open())
		//	{
		//		

		//		while (getline(history, output))
		//		{
		//			cout << output << endl;
		//		}
		//		history.close();
		//	}
		//}

		char option;
		cout << "Want to use browser again?" << endl;
		cout << "Press Y for yes & N for No" << endl;
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			undo.Push(res);
			system("cls");

			url();

		}
		else
		{
			cout << "Thanks alot for using us" << endl;
		}
	}
	



}

template<typename T>
inline bool torr<T>::search(Stack <string>& obj,string url__)           //Searching From History
{
	Stack<string> temp;   //I used shallow copy method because we were prohibited to add anything in linkedlist
	int cnt1 = 0;           //To not exceed or repeat stack cycle
	while (!obj.isEmpty()||cnt1 != this->no_of_searches)                              //This Function will not disturb the obj attributes
	{
		temp.Push(obj.Pop());
		cnt1++;
	}
	string tmp;
	ifstream file_C;
	string input;
	while (!temp.isEmpty() || cnt1!=0)
	{
		tmp=temp.Pop();
		obj.Push(tmp);
		cnt1--;
		if (tmp == url__)
		{
			//file_C.open(url__.c_str());                                 //you cannot use string in any opening mode
			//if (file_C.is_open())
			//{
			//	
			//	cout << "Your Search Result" << endl;

			//	while (getline(file_C, input))
			//	{
			//		cout << input << endl;
			//	}
			//	file_C.close();
			//}
			return true;

		}

	}
	return false;
}

template<typename T>
inline void torr<T>::display(string filename)                          //Reusable Display Method
{
	drawRectangle(0, 0, 10, 600, 155, 0, 155, 155, 0, 155);
	//drawRectangle(0, 0, 195, 600, 155, 0, 155, 155, 0, 155);
	drawRectangle(0, 0, 1000, 11, 25, 0, 250, 25, 0, 250);
	drawRectangle(0, 470, 1000, 800, 25, 0, 250, 25, 0, 250);
	
	ifstream file_C;
	string input;
	string tmp2;                                                         //To add extension
	tmp2 = extension_maker(filename);
	file_C.open(tmp2.c_str());                                 //you cannot use string in any opening mode
	if (file_C.is_open())
	{

		cout << "Your Search Result" << endl;

		while (getline(file_C, input))
		{
			cout << input << endl;
		}
		file_C.close();
	}
}

template<typename T>
inline string torr<T>::chr_to_string(char* array, int size)
{
	int i;
	string s1 = "";
	for (i = 0; i < size; i++) {
		s1 = s1 + array[i];
	}
	return s1;
}

template<typename T>
inline string torr<T>::extension_maker(string s)
{
	// assigning value to string s
	string str;
	str = s;
	// declaring character array : p
	int a = str.length();
	int b = a;
	char* ptr = new char[str.length() + 4];
	int size = b + 4;

	int i;
	for (i = 0; i < b; i++) {
		ptr[i] = str[i];
	}
	ptr[b + 3] = 't';
	ptr[b + 2] = 'x';
	ptr[b + 1] = 't';
	ptr[b] = '.';
	string url = chr_to_string(ptr, size);
	
	return url;
}

// Sir G is dafa marks na katia ga :)
// Happy Coder!

