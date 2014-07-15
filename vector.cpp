// g++ -Wall -g -o vector{,.cpp}
#include <iostream>
#include <vector>

class Jim
{
public:
	Jim();
	Jim (const Jim &jim);
	~Jim();
	int number;
private:
};

Jim::Jim()
{
	std::cout << "Jim::Jim\n";
	number = 0;
}

Jim::Jim (const Jim &jim)
{
	std::cout << "Jim::Jim (copy)\n";
	number = 100 + jim.number;
}

Jim::~Jim()
{
	std::cout << "Jim::~Jim (" << number << ")\n";
}

int
main (int argc, char *argv[])
{
	std::vector<Jim> vj;
	Jim j;
	std::cout << "hello world\n";

	for (int i = 0; i < 5; i++) {
		j.number = i;
		vj.push_back (j);
	}

	return 0;
}

