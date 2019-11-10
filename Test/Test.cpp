#include <iostream>
using namespace std;

class productType                                                 
{                                                                 
public:                                                           
	productType(string, int, double, double);

private:
	string productName;
	string id;
	string manufacturer;
	int quantitiesInStock;
	double price; double discount;
};

int main()
{
	return 0;
}

productType::productType(string id, int quantitiesInStock, double price, double discount) {    
	// initialize productName and manufacturer to an empty string    
	productName = "";    
	manufacturer = "";    
	// initialize id to the first parameter    
	this->id = id;        
	// check that quantitiesInStock is nonnegative    
	if (quantitiesInStock >= 0)    
	{        
		this->quantitiesInStock = quantitiesInStock;     
	}    
	// check that price is nonnegative    
	if (price >= 0)    
	{       
		this->price = price ;    
	}   
	// check that discount is nonnegative  
	if (discount >= 0)  
	{    
		this->discount = discount;   
	}
}