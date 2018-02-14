#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
int main()
{
	std::srand((unsigned int)std::time(0));
	int r = 0, n = 0;
	std::cin >> r >> n;
	int randomBookedRoom = std::rand() % r + 1;

	std::vector<int> bookedRooms;
	for (int i = 0; i < n; i++)
	{
		int roomBooked = 0;
		while (roomBooked <= 0 && roomBooked < r)
			std::cin >> roomBooked;
		bookedRooms.push_back(roomBooked);
	}
	
	if (n == r)
	{
		std::cout << "too late";
		return 0;
	}

    // Fugly solution, has to be a better way!
	bool notFree = false;
	while (!notFree)
	{
		notFree = true;
		randomBookedRoom = std::rand() % r + 1;
		for (int i = 0; i < bookedRooms.size(); i++)
			if (randomBookedRoom == bookedRooms[i])
				notFree = false;
	}
	std::cout << randomBookedRoom;
}
