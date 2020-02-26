#include<iostream>
#include<string>

using namespace std;

class Employee 
{
	private :
		string name;
		string empNo;
		int * salaries ;
		int months ;
	public :
		Employee () ; // default constructor
		Employee (string name, int months ); // constructor
		Employee ( const Employee & other); // copy constructor
		~ Employee () ; // destructor
		void setSalary ( const int month , const int value ); //set Salary of a month 
		int getSalary ( const int month );	// get Salary of a month
		int getMonths();	//return months
		void setName(string name);
		void print () ;
}; 

// default constructor
Employee :: Employee ()
{ 
	this->name="NoName";
	this->months =12; 
	this->salaries = new int [12];
} 


// constructor
Employee :: Employee (string name, int months)
{ 
	this->name = name;
	this->months = months;
	this->salaries = new int [months];
}
Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		name = other.name; //copying everything.. 
		empNo = other.number;
		months = other.months;

		delete [] salaries;
		salaries = new int[other.months];

		for(int i=0; i<other.months;i++){
			salaries[i] = other.salaries[i];
		}
	}
	return *this
}

// copy constructor
Employee :: Employee ( const Employee & other)
{ 
	this->name = other.name ;

	this->months = other.months;

	this->salaries = new int[other.months]; //new array pointer pointing to a new mem location in heap
	for(int i=0;i<other.months; i++){
		salaries[i] = other.salaries[i];
	}
		//Shallow Copy
}

//Destructor 
Employee ::~ Employee () 
{
	delete [] salaries ;
}

//setter Method
void Employee::setSalary ( const int month , const int value )
{
	this->salaries[month]=value;
}

//getter Method
int Employee::getSalary ( const int month )
{
	if (0 <= month <= this->months)
		return this->salaries[month];
	else
		return -1;
}

//getter Method
int Employee::getMonths()
{
	return this->months;
}

//setter Method
void Employee::setName ( string name )
{
	this->name = name;
}

//Print Method
void Employee::print ()
{
	cout<<"Name:"<<this->name<<endl;
	for (int i=0; i<this->months; i++)
	{
		cout<<this->salaries[i]<<endl;
	}
}

// main function
int main()
{
	Employee emp1;
	Employee emp2(emp1);
	Employee emp3;
	emp3=emp1;

	emp1.setName("emp1");
	emp2.setName("emp2");
	emp3.setName("emp3");


	for (int i=0; i<emp1.getMonths(); i++)
	    emp1.setSalary(i,1000);
	
	for (int i=0; i<emp2.getMonths(); i++)
	    emp2.setSalary(i,2000);

	for (int i=0; i<emp3.getMonths(); i++)
	    emp3.setSalary(i,3000);
	


	emp1.print();
	emp2.print();
	emp3.print();
	
	return EXIT_SUCCESS;
}