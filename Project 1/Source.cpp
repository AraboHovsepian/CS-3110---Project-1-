#include <iostream>
#include <string>
#include <math.h>

using namespace std;

float stringToFloat(string copyS)
{
	int power = 0, eNum = 0;
	float floatNum = 0.0, temp = 0.0;
	bool negative = false;
	string beforeDot = "", afterDot = "", afterE = "";
	size_t dotPos, ePos, EPos;

	if (copyS.find('-') != string::npos)
	{
		negative = true;
	}

	copyS.erase(remove(copyS.begin(), copyS.end(), '_'));
	copyS.erase(remove(copyS.begin(), copyS.end(), '+'));
	copyS.erase(remove(copyS.begin(), copyS.end(), '-'));
	copyS.erase(remove(copyS.begin(), copyS.end(), 'f'));
	copyS.erase(remove(copyS.begin(), copyS.end(), 'F'));
	copyS.erase(remove(copyS.begin(), copyS.end(), 'd'));
	copyS.erase(remove(copyS.begin(), copyS.end(), 'D'));

	dotPos = copyS.find('.');
	ePos = copyS.find('e');
	EPos = copyS.find('E');

	if (ePos != string::npos)
	{
		beforeDot = copyS.substr(0, dotPos);
		afterDot = copyS.substr(dotPos + 1, ePos - (dotPos + 1));
		afterE = copyS.substr(ePos + 1);
	}
	else if (EPos != string::npos)
	{
		beforeDot = copyS.substr(0, dotPos);
		afterDot = copyS.substr(dotPos + 1, EPos - (dotPos + 1));
		afterE = copyS.substr(EPos + 1);
	}
	else if (dotPos != string::npos)
	{
		beforeDot = copyS.substr(0, dotPos);
		afterDot = copyS.substr(dotPos + 1);
	}
	else
	{
		beforeDot = copyS;
	}

	power = beforeDot.length() - 1;
	for (int i = 0; i < beforeDot.length(); i++)
	{
		temp = (beforeDot[i] - 48) * pow(10, power);
		floatNum += temp;
		power--;
	}

	power = -1;
	for (int i = 0; i < afterDot.length(); i++)
	{
		temp = (afterDot[i] - 48) * pow(10, power);
		floatNum += temp;
		power--;
	}

	power = afterE.length() - 1;
	for (int i = 0; i < afterE.length(); i++)
	{
		temp = (afterE[i] - 48) * pow(10, power);
		eNum += temp;
		power--;
	}

	floatNum = floatNum * pow(10, eNum);

	if (negative)
	{
		floatNum = floatNum * -1;
	}

	return floatNum;
}

int main()
{
	string s = "";

	do
	{
		cout << "Please enter a string: ";
		cin >> s;
		cout << "float -> " << stringToFloat(s) << endl;
		cout << "built-in stof (for verification only) -> " << stof(s) << endl;
	} while (true);

	return 0;
}