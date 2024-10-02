#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float X = 0.0, Y = 0.0;
	cout << "Введите значения x и y\n";
	cin >> X;
	cin >> Y;

	float R = (-X + sqrt(abs(pow(X, 2) - (4 * X * Y)))) / (2 * X);
	float S = pow(4, (- 3 * X)) * sin(Y);

	cout << R << endl << S << endl;

	float C = max(R, S);

	cout << C << endl;

	system("pause");

	return 0;
}
