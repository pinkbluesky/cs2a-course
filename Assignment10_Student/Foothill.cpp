/*
* Class: CS2A
* Description: Edit the Student and StudentArrayUtilities classes.
* Test the classes by initializing 4 Student arrays to sort
* and print the median.
* Due date: Dec 6, 2019
* Name: Alina Li
* File name: Foothill.cpp
*/

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// class Student prototype -----------------------
class Student
{
private: 
   string lastName;
   string firstName;
   int totalPoints;

public:
   static const string DEFAULT_NAME;
   static const int DEFAULT_POINTS = 0;
   static const int MAX_POINTS = 1000;

   static const int SORT_BY_FIRST = 88;
   static const int SORT_BY_LAST = 98;
   static const int SORT_BY_POINTS = 108;

public:
   Student( string lst = DEFAULT_NAME, string fst = DEFAULT_NAME,
      int pts = DEFAULT_POINTS);

   // accessors and mutators
   string getLastName() { return lastName; }
   string getFirstName() { return firstName; } 
   int getTotalPoints() { return totalPoints; }

   bool setLastName(string last);
   bool setFirstName(string first);
   bool setPoints(int pts);

   static int compareTwoStudents( Student firstStud, Student secondStud );
   string toString();

   // accessors and mutators for sortKey
   static bool setSortKey(int key);
   static int getSortKey();

private: 
   static bool validString( string testStr );
   static bool validPoints( int testPoints );
   static int sortKey;

};  // end of class Student prototype --------------

// class StudentArrayUtilities prototype -----------------------
class StudentArrayUtilities
{
public:
   static string toString(string title, Student data[], int arraySize);
   static void arraySort(Student array[], int arraySize);
   static double getMedianDestructive(Student array[], int arraySize);

private:
   static bool floatLargestToTop(Student data[], int top);
   static void mySwap(Student &a, Student &b);
};

// static initializations that can't be done in-line
const string Student::DEFAULT_NAME = "zz-error";
int Student::sortKey = Student::SORT_BY_LAST;

// constant initialization for main method
static const int ARR1_LEN = 15;
static const int ARR2_LEN = 16;
static const int ARR3_LEN = 1;
static const int ARR4_LEN = 0;

int main()
{
	Student arr1[ARR1_LEN]
	{
		Student("Hunt", "Hugh", 90), Student("Stevens", "Lloyd", 100),
		Student("Payne", "Matilda", 177),  Student("Hunter", "Madison", 120),
		Student("Chavez", "Georgina", 88),  
		Student("Cunnings","Annabelle", 150),
		Student("Simmons", "Ellie", 78),  Student("O'Gallagher", "Maya", 340),
		Student("Alvarez", "Casey", 133),  Student("Richards", "Darcy", 71),
		Student("Reyes", "Kayla", 200), Student("Berry", "Kathie", 341),
		Student("Simpson", "Bart", 55), Student("Webb", "Dennis", 241),
		Student("Hawkins", "Zelda", 190)
	};
	
	Student arr2[ARR2_LEN]
	{
		Student("Hunt", "Hugh", 90), Student("Stevens", "Lloyd", 100),
		Student("Payne", "Matilda", 177),  Student("Hunter", "Madison", 120),
		Student("Chavez", "Georgina", 88), 
		Student("Cunnings","Annabelle", 150),
		Student("Simmons", "Ellie", 78),  
		Student("O'Gallagher", "Maya", 340),
		Student("Alvarez", "Casey", 133),  Student("Richards", "Darcy", 71),
		Student("Reyes", "Kayla", 200), Student("Berry", "Kathie", 341),
		Student("Simpson", "Bart", 55), Student("Webb", "Dennis", 241),
		Student("Hawkins", "Zelda", 190), Student("Rozenburg", "Cary", 83)
	};
	Student arr3[ARR3_LEN]
	{
		Student("Hunt", "Hugh", 90)
	};

	// array 4
	cout << "Cannot initialize an empty array. (Array 4)" << endl;

	// print the array
	cout << StudentArrayUtilities::toString("-------- Array 2, size " 
		+ to_string(ARR2_LEN) + ", before modification ---------", 
		arr2, ARR2_LEN);
	cout << endl;

	// sort and print array by default sortkey
	StudentArrayUtilities::arraySort(arr2, ARR2_LEN);
	cout << StudentArrayUtilities::toString("-------- Array 2, size "
		+ to_string(ARR2_LEN) + ", sorted by default ---------", 
		arr2, ARR2_LEN);
	cout << endl;

	// sort and print array by first name
	Student::setSortKey(Student::SORT_BY_FIRST);

	StudentArrayUtilities::arraySort(arr2, ARR2_LEN);
	cout << StudentArrayUtilities::toString("-------- Array 2, size "
		+ to_string(ARR2_LEN) + ", sorted by first name ---------", 
		arr2, ARR2_LEN);

	cout << endl;

	// sort and print array by points
	Student::setSortKey(Student::SORT_BY_POINTS);

	StudentArrayUtilities::arraySort(arr2, ARR2_LEN);
	cout << StudentArrayUtilities::toString("-------- Array 2, size "
		+ to_string(ARR2_LEN) + ", sorted by points ---------", 
		arr2, ARR2_LEN);

	cout << endl;

	// set sortkey to first name, call and display median
	Student::setSortKey(Student::SORT_BY_FIRST);
	cout << "Median: " 
		<< StudentArrayUtilities::getMedianDestructive(arr2, ARR2_LEN) 
		<< endl;

	// print sortkey value
	cout << "Sort key value: " << Student::getSortKey() << endl << endl;
	if (Student::getSortKey() == Student::SORT_BY_FIRST)
	{
		cout << "Sort key value successfully preserved." << endl;
	}
	else
	{
		cout << "Sort key value has incorrectly changed." << endl;
	}
	cout << endl;
	// print the medians of the other three arrays
	cout << "Median of Array 1 (large and odd): " 
		<< StudentArrayUtilities::getMedianDestructive(arr1, ARR1_LEN) << endl;
	cout << "Median of Array 3 (array length is 1): " 
		<< StudentArrayUtilities::getMedianDestructive(arr3, ARR3_LEN) << endl;
	cout << "Could not initialize Array 4 with length 0." << endl;

	return 0;
}

// beginning of Student method definitions -------------

// constructor requires parameters - no default supplied
Student::Student( string last, string first, int points)
{
   if ( !setLastName(last) )
      lastName = DEFAULT_NAME;
   if ( !setFirstName(first) )
      firstName = DEFAULT_NAME;
   if ( !setPoints(points) )
      totalPoints = DEFAULT_POINTS;  
}

bool Student::setLastName(string last)
{
   if ( !validString(last) )
      return false;
   lastName = last;
   return true;
}

bool Student::setFirstName(string first)
{
   if ( !validString(first) )
      return false;
   firstName = first;
   return true;
}

bool Student::setPoints(int pts)
{
   if ( !validPoints(pts) )
      return false;
   totalPoints = pts;
   return true;
}

// could be an instance method and, if so, would take one parameter
int Student::compareTwoStudents( Student firstStud, Student secondStud )
{
   int result = 0;

   switch (sortKey)
   {
   case SORT_BY_FIRST:
	   result = firstStud.firstName.compare(secondStud.firstName);
	   break;
   case SORT_BY_LAST:
	   result = firstStud.lastName.compare(secondStud.lastName);
	   break;
   case SORT_BY_POINTS:
	   result = firstStud.totalPoints - secondStud.totalPoints;
	   break;
   }

   return result;
}

string Student::toString()
{
   string resultString;
   ostringstream cnvrtFirst, cnvrtLast, cnvrtPoints;

   cnvrtFirst << firstName;
   cnvrtLast << lastName;
   cnvrtPoints << totalPoints;

   resultString = " " + cnvrtLast.str() 
      + ", " + cnvrtFirst.str()
      + " points: " + cnvrtPoints.str()
      + "\n";
   return resultString;
}

// mutator for sortKey
bool Student::setSortKey(int key)
{
	// if it is a valid key
	if (key == SORT_BY_FIRST || key == SORT_BY_LAST 
		|| key == SORT_BY_POINTS)
	{
		sortKey = key;
		return true;
	}

	// if invalid
	return false;
}

// accessor for sortKey
int Student::getSortKey()
{
	return sortKey;
}

bool Student::validString( string testStr )
{
   if (testStr.length() > 0 && isalpha(testStr[0]))
      return true;
   return false;
}

bool Student::validPoints( int testPoints )
{
   if (testPoints >= 0 && testPoints <= MAX_POINTS)
      return true;
   return false;
}
// end of Student method definitions  --------------

// beginning of StudentArrayUtilities method definitions -------------

// print the array with string as a title for the message box
// this is somewhat controversial - we may or may not want an I/O
// methods in this class.  we'll accept it today
string StudentArrayUtilities::toString(string title, Student data[], 
	int arraySize)
{
	string output = title + "\n";

   // build the output string from the individual Students:
   for (int k = 0; k < arraySize; k++)
      output += " " + data[k].toString();

   output += "\n";
   return output;
}

void StudentArrayUtilities::arraySort(Student array[], int arraySize)
{
   for (int k = 0; k < arraySize; k++)
      // compare with method def to see where inner loop stops
         if (!floatLargestToTop(array, arraySize-1-k))
            return;
}

// returns the median of the total points values in the array
double StudentArrayUtilities::getMedianDestructive(Student array[], 
	int arraySize)
{
	// check for empty array case
	if (arraySize == 0)
	{
		return 0;
	}

	// check for 1 element array case
	if (arraySize == 1)
	{
		return array[0].getTotalPoints();
	}

	// sort the array
	int tempSortKey = Student::getSortKey();
	Student::setSortKey(Student::SORT_BY_POINTS);
	arraySort(array, arraySize);
	// reset the sort key
	Student::setSortKey(tempSortKey);

	double median = 0;
	// for even numbered arrays:
	if (arraySize % 2 == 0)
	{
		int index1 = (arraySize - 1) / 2;
		int index2 = arraySize / 2; 
		median = ((double) array[index1].getTotalPoints() 
			+ array[index2].getTotalPoints()) / 2.0;
	}

	// for odd numbered arrays
	if (arraySize % 2 == 1)
	{
		median = array[(arraySize - 1) / 2].getTotalPoints();
	}

	return median;
}

// returns true if a modification was made to the array
bool StudentArrayUtilities::floatLargestToTop(Student data[], int top)
{
   bool changed = false;

   // compare with client call to see where the loop stops
   for (int k =0; k < top; k++)
      if (  Student::compareTwoStudents(data[k], data[k + 1]) > 0 )
      {
         mySwap(data[k], data[k + 1]);
         changed = true;
      }
      return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b)
{
   Student temp("", "", 0);

   temp = a;
   a = b;
   b = temp;
}  

// end of StudentArrayUtilities method definitions  --------------

/* ------------------------------ run ----------------------------
Cannot initialize an empty array. (Array 4)
-------- Array 2, size 16, before modification ---------
  Hunt, Hugh points: 90
  Stevens, Lloyd points: 100
  Payne, Matilda points: 177
  Hunter, Madison points: 120
  Chavez, Georgina points: 88
  Cunnings, Annabelle points: 150
  Simmons, Ellie points: 78
  O'Gallagher, Maya points: 340
  Alvarez, Casey points: 133
  Richards, Darcy points: 71
  Reyes, Kayla points: 200
  Berry, Kathie points: 341
  Simpson, Bart points: 55
  Webb, Dennis points: 241
  Hawkins, Zelda points: 190
  Rozenburg, Cary points: 83


-------- Array 2, size 16, sorted by default ---------
  Alvarez, Casey points: 133
  Berry, Kathie points: 341
  Chavez, Georgina points: 88
  Cunnings, Annabelle points: 150
  Hawkins, Zelda points: 190
  Hunt, Hugh points: 90
  Hunter, Madison points: 120
  O'Gallagher, Maya points: 340
  Payne, Matilda points: 177
  Reyes, Kayla points: 200
  Richards, Darcy points: 71
  Rozenburg, Cary points: 83
  Simmons, Ellie points: 78
  Simpson, Bart points: 55
  Stevens, Lloyd points: 100
  Webb, Dennis points: 241


-------- Array 2, size 16, sorted by first name ---------
  Cunnings, Annabelle points: 150
  Simpson, Bart points: 55
  Rozenburg, Cary points: 83
  Alvarez, Casey points: 133
  Richards, Darcy points: 71
  Webb, Dennis points: 241
  Simmons, Ellie points: 78
  Chavez, Georgina points: 88
  Hunt, Hugh points: 90
  Berry, Kathie points: 341
  Reyes, Kayla points: 200
  Stevens, Lloyd points: 100
  Hunter, Madison points: 120
  Payne, Matilda points: 177
  O'Gallagher, Maya points: 340
  Hawkins, Zelda points: 190


-------- Array 2, size 16, sorted by points ---------
  Simpson, Bart points: 55
  Richards, Darcy points: 71
  Simmons, Ellie points: 78
  Rozenburg, Cary points: 83
  Chavez, Georgina points: 88
  Hunt, Hugh points: 90
  Stevens, Lloyd points: 100
  Hunter, Madison points: 120
  Alvarez, Casey points: 133
  Cunnings, Annabelle points: 150
  Payne, Matilda points: 177
  Hawkins, Zelda points: 190
  Reyes, Kayla points: 200
  Webb, Dennis points: 241
  O'Gallagher, Maya points: 340
  Berry, Kathie points: 341


Median: 126.5
Sort key value: 88

Sort key value successfully preserved.

Median of Array 1 (large and odd): 133
Median of Array 3 (array length is 1): 90
Could not initialize Array 4 with length 0.

---------------------------------------------------------------- */
