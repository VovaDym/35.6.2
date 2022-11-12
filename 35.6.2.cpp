#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <memory>



int main()
{
	std::vector<int> vec = { 1, 2, 2, 5, 3, 4, 4, 1 };
	
	auto lambda = [](const std::vector<int>&vec)
	{
		std::unordered_set<int> us;
		std::map<int, int> map;
		std::vector<int> newVec;

		for (const auto& el : vec)
		{	
			if (us.insert(el).second)
			{
				map[el] = 1;
			}
			else
			{
				map[el] += 1;
			}		
		}
		for (auto el : map)
		{
			if (el.second == 1)
			{
				newVec.emplace_back(el.first);
			}
		}
		return std::make_unique<std::vector<int>>(newVec);
	};

	auto uptr = lambda(vec);
	for (auto el : *uptr)
	{
		std::cout << el << std::endl;
	}		
}