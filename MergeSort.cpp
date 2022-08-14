// Merge Sort

#include <iostream>
#include <list>

std::list<double> myMerge(std::list<double> x, std::list<double> y)
{
	std::list<double> merged_nums = { };

	while (!x.empty() && !y.empty())
	{
		if (*x.begin() <= *y.begin())
		{
			merged_nums.push_back(*x.begin());
			x.pop_front();
		}
		else
		{
			merged_nums.push_back(*y.begin());
			y.pop_front();
		}
	}

	while (!x.empty())
	{
		merged_nums.push_back(*x.begin());
		x.pop_front();
	}

	while (!y.empty())
	{
		merged_nums.push_back(*y.begin());
		y.pop_front();
	}

	return merged_nums;
}


std::list<double> mergeSort(std::list<double> nums)
{
	if (nums.size() <= 1) return nums;

	std::list<double> left = { };
	std::list<double> right = { };

	int size = nums.size();
	for (int i = 0; i < size / 2; i++)
	{
		left.push_back(*nums.begin());
		nums.pop_front();
	}

	while (!nums.empty())
	{
		right.push_back(*nums.begin());
		nums.pop_front();
	}

	left = mergeSort(left);
	right = mergeSort(right);

	return myMerge(left, right);
}


bool tryAgain()
{
	std::cout << "Try again? (Y/N): ";

	char x = 'N';
	std::cin >> x;
	std::cin.clear();

	if (x == 'y' || x == 'Y')
	{
		return true;
	}
	return false;
}


void printList(const std::list<double>& nums)
{
	for (double i : nums)
	{
		std::cout << i << " ";
	}
	std::cout << '\n';
}


int main()
{
	do
	{
		double input;
		std::list<double> nums = { };
		std::list<double> sorted_nums = { };

		std::cout << "Please input the numbers you would like to sort, separated by spaces or tabs: \n";
		try
		{
			
			while (std::cin >> input)
			{
				nums.push_back(input);
				if (std::cin.peek() == '\n') break;
			}
			std::cin.clear();

			std::cout << "Sorted numbers: ";
			sorted_nums = mergeSort(nums);
			printList(sorted_nums);
		}
		catch (...)
		{
			
			std::cout << "Values must be numeric.\n";
		}
	}
	while (tryAgain());
}