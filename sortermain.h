#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "Sorter.h" //LinkedList "Sorter" Class (modify this class)

/*
 * change these to true as you implement the sorting predicates
 */
#define TEST_ASC false
#define TEST_DESC false
#define TEST_ASC_ODD_EVEN false
#define TEST_DESC_ODD_EVEN true

 //predicate functions stubs
bool asc_int(const int& a, const int& b)
{
	//std::cout << ">> " << a << " " << b << " <<";
	return a > b ;
}

#if TEST_DESC
bool desc_int(const int& a, const int& b)
{
	return a < b; 
}
#endif

#if TEST_ASC_ODD_EVEN
bool odd_even_asc(const int& a, const int& b)
{
	if (a % 2 != 0 && b %2 != 0) {
		return a > b;
	}
	else if (a%2 == 0 && b%2 == 0) {
		return a > b ;
	}
	else if(a % 2 != 0 && b % 2 == 0){
		return false;
	}
	else {
		return true;
	}

}
#endif

#if TEST_DESC_ODD_EVEN
bool odd_even_desc(const int& a, const int& b)
{
	if (a % 2 != 0 && b % 2 != 0) {
		return a <  b;
	}
	else if (a % 2 == 0 && b % 2 == 0) {
		return a <  b;
	}
	else if (a % 2 != 0 && b % 2 == 0) {
		return false;
	}
	else {
		return true;
	}

}
#endif

//do not modify this function
void print_list(LinkedList<int>& list)
{
	int count = 0;
	std::cout << std::endl;
	 
	auto const* node = list.begin();
	while (node)
	{
		if (count == 0)
		{
			std::cout << "\t";
		}
		std::cout << std::setw(5) << node->data;
		node = node->next;
		if (++count % 10 == 0)
		{
			std::cout << std::endl << "\t";
		}
	}
	std::cout << std::endl; 
}

//do not modify this function
int main(int argc, char* argv[])
{
	//seed random (this is the worst random to use)
	srand(static_cast<unsigned>(time(nullptr)));

#if TEST_ASC
	std::cout << "Ascending Order (1,2,3,4,5,6...):" << std::endl;
	{
		LinkedList<int> integer_list;
		for (int i = 0; i < 100; ++i)
		{
			integer_list.push_back(rand() % 100 + 1);
		}
		std::cout << "Unsorted:\n";
		print_list(integer_list);

		Sorter<int>(integer_list, asc_int);

		std::cout << "Sorted:\n";
		print_list(integer_list);
	}
#endif

#if TEST_DESC
	std::cout << "\nDescending Order (6,5,4,3,2,1,...):" << std::endl;
	{
		LinkedList<int> integer_list;
		for (int i = 0; i < 100; ++i)
		{
			integer_list.push_back(rand() % 100 + 1);
		}
		std::cout << "Unsorted:\n";
		print_list(integer_list);

		Sorter<int>(integer_list, desc_int);

		std::cout << "Sorted:\n";
		print_list(integer_list);
	}
#endif

#if TEST_ASC_ODD_EVEN
	std::cout << "\nOdd_Even Ascending Order (1,3,5,7,2,4,6,8):" << std::endl;
	{
		LinkedList<int> integer_list;
		for (int i = 0; i < 100; ++i)
		{
			integer_list.push_back(rand() % 100 + 1);
		}
		std::cout << "Unsorted:\n";
		print_list(integer_list);

		Sorter<int>(integer_list, odd_even_asc);

		std::cout << "Sorted:\n";
		print_list(integer_list);
	}
#endif

#if TEST_DESC_ODD_EVEN
	std::cout << "\nOdd_Even Descending Order (7,5,3,1,8,6,4,2):" << std::endl;
	{
		LinkedList<int> integer_list;
		for (int i = 0; i < 100; ++i)
		{
			integer_list.push_back(rand() % 100 + 1);
		}
		std::cout << "Unsorted:\n";
		print_list(integer_list);

		Sorter<int>(integer_list, odd_even_desc);

		std::cout << "Sorted:\n";
		print_list(integer_list);
	}
#endif
	
	return 0;
}