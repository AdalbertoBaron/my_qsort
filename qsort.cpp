#include <iostream>
#include <vector>

std::vector<int> &myqsort(std::vector<int> &array)
{
	if (array.size() < 2)
		return array;
	else if (array.size() == 2)
	{
		if (array[0] < array[1])
		{
			int tmp = array[0];
			array[0] = array[1];
			array[1] = tmp;
		}
	}
	else
	{
		std::vector<int> small_array;
		std::vector<int> big_array;
		for(int i = 1; i < array.size(); ++i)
		{
			if (array[0] < array[i])
				small_array.push_back(array[i]);
			else
				big_array.push_back(array[i]);
		}
		small_array = myqsort(small_array);
		small_array.push_back(array[0]);
		big_array = myqsort(big_array);
		for(int i = 0; i < big_array.size(); ++i)
			small_array.push_back(big_array[i]);
		array = small_array;
	}
	return array;
}

int main (void)
{
	std::vector<int> array;
	std::vector<int> sorted_array;

	array.push_back(2);
	array.push_back(5);
	array.push_back(1);
	array.push_back(3);
	array.push_back(12);
	array.push_back(0);
	array.push_back(10);
	array.push_back(5);
	array.push_back(0);
	array.push_back(9999);
	array.push_back(1);
	array.push_back(55);

	sorted_array = myqsort(array);
	for (int i = 0; i < sorted_array.size(); ++i)
		std::cout << sorted_array[i] << std::endl;
	return (0);
}