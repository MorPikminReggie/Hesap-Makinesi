#include <cmath>
#include <iostream>
using namespace std;
int input = 0;
double* sayilar;
char* oper;
bool binary_check = false;
double calculate(double* sayilar, char* oper, int input);

int main()
{
	while (true)
	{
		cout << "HESAP MAKINESI" << endl << endl;
		cout << "PLEASE ENTER OPERATION-NUMBER" << endl;
		cin >> input;
		sayilar = new double[input + 1];
		oper = new char[input];
		cout << "PLEASE ENTER AN OPERATION" << endl;
		cin >> sayilar[0];
		for (int i = 0; i < input; i++)
		{
			cin >> oper[i] >> sayilar[i + 1];
		}
		double sonuc = calculate(sayilar, oper, input);
		if(binary_check==false)
		{
			cout << sonuc << endl;
		}
		system("pause");
		system("cls");
	}
}

double calculate(double* sayilar, char* oper, int input)
{
	long long bin = 0;
	int i = 0;
	int itemsayisi = input;
	for (int j = 0; j <= itemsayisi; j++)
	{
		i = 0;
		while (i < input)
		{
			if (oper[i] == '^')
			{
				sayilar[i + 1] = pow(sayilar[i], sayilar[i + 1]);
				for (int j = i + 1; j <= input; j++)
				{
					sayilar[j - 1] = sayilar[j];
				}
				for (int j = i + 1; j <= input; j++)
				{
					oper[j - 1] = oper[j];
				}
				input--;
			}
			i++;
		}
	}
	for (int j = 0; j <= itemsayisi; j++)
	{

		i = 0;
		while (i < input)
		{
			if (oper[i] == '*' || oper[i] == '/')
			{
				if (oper[i] == '*')
				{
					sayilar[i + 1] = sayilar[i] * sayilar[i + 1];
				}
				else if (oper[i] == '/')
				{
					sayilar[i + 1] = sayilar[i] / sayilar[i + 1];
				}
				for (int j = i + 1; j <= input; j++)
				{
					sayilar[j - 1] = sayilar[j];
				}
				for (int j = i + 1; j < input; j++)
				{
					oper[j - 1] = oper[j];
				}
				input--;
			}
			i++;
		}
	}
	for (int j = 0; j <= itemsayisi; j++)
	{

		i = 0;
		while (i < input)
		{
			if (oper[i] == '+' || oper[i] == '-')
			{
				if (oper[i] == '+')
				{
					sayilar[i + 1] = sayilar[i] + sayilar[i + 1];
				}
				else if (oper[i] == '-')
				{
					sayilar[i + 1] = sayilar[i] - sayilar[i + 1];
				}
				for (int j = i + 1; j <= input; j++)
				{
					sayilar[j - 1] = sayilar[j];
				}
				for (int j = i + 1; j < input; j++)
				{
					oper[j - 1] = oper[j];
				}
				input--;
			}
			i++;
		}
	}
	for (int j = 0; j <= itemsayisi; j++)
	{

		i = 0;
		while (i < input)
		{
			if (oper[i] == '%')
			{
				sayilar[i + 1] = (int)sayilar[i] % (int)sayilar[i + 1];
				for (int j = i + 1; j <= input; j++)
				{
					sayilar[j - 1] = sayilar[j];
				}
				for (int j = i + 1; j <= input; j++)
				{
					oper[j - 1] = oper[j];
				}
				input--;
			}
			i++;
		}
	}

	i = 0;
	while (i < input)
	{
		if (oper[i] == '|')
		{
			long long j = 1;
			while ((int)sayilar[i] != 0)
			{
				int rem = (int)sayilar[i] % (int)sayilar[i + 1];
				sayilar[i] = (int)sayilar[i] / sayilar[i + 1];
				bin = rem * j + bin;
				j = j * 10;
			}
			binary_check=true;
			cout << bin << endl;
			sayilar[i + 1] = bin;
			for (int j = i + 1; j <= input; j++)
			{
				sayilar[j - 1] = sayilar[j];
			}
			for (int j = i + 1; j <= input; j++)
			{
				oper[j - 1] = oper[j];
			}
			input--;
		}
		i++;
	}
	return sayilar[0];
}
