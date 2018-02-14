#include <iostream>
#include <string>

void Yoda(std::string& s1, std::string& s2)
{
	std::string s3, s4;
	int s1Lenght = s1.length(),
	    s2Length = s2.length();

	if (s1.length() > s2.length())
	{
		int spacing = s1.length() - s2.length();
		for (int i = 0; i < spacing; i++)
			s2.insert(i, "0"); // Insert 0 at the beginning.
	}
	else
	{
		int spacing = s2.length() - s1.length();
		for (int i = 0; i < spacing; i++)
			s1.insert(i, "0"); // Insert 0 at the beginning.
	}

	for (int i = 0; i < s2.length(); i++)
	{
		if ((s1[i] - '0') > (s2[i] - '0'))
			s3.push_back(s1[i]);
		else if ((s1[i] - '0') < (s2[i] - '0'))
			s4.push_back(s2[i]);
		else
		{
			s3.push_back(s1[i]);
			s4.push_back(s1[i]);
		}
	}

	// So we don't lose digits.
	if (s1Lenght > s2Length)
		for (int i = s2.length(); i < s1.length(); i++)
			s3.push_back(s1[i]);
	else
		for (int i = s1.length(); i < s2.length(); i++)
			s4.push_back(s2[i]);

	s1 = s3;
	s2 = s4;
}

int main()
{
	std::string s1, s2, s3, s4;
	std::cin >> s1 >> s2;

	Yoda(s1, s2);

	if (s1.empty())
		std::cout << "YODA\n";
	else
		std::cout << std::stoi(s1) << "\n";

	if (s2.empty())
		std::cout << "YODA\n";
	else
		std::cout << std::stoi(s2) << "\n";

	std::cin.ignore();
	std::cin.get();
}
