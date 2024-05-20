#include <vector>
#include <iostream>

using namespace std;

class ChangeVec
{
private:

public:
	vector<int> Run(vector<int> inputs)
	{
		for (int& input : inputs)
		{
			if (input >= 10 || input == 4)
				throw exception("invalide");

			input += 1;
			if (input == 10)
				input = 0;
			if (input == 4)
				input = 5;
		}
		return inputs;
	}
};