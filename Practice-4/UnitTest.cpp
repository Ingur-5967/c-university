// UnitTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>


float calc_func(float X, float Y) {

	if (X == 0) {
		std::cout << "X cannot be null, because (...) / (2 * X <- ERROR)" << std::endl;
		return -INFINITY;
	}

	if (-1 <= Y <= 1) {
		float R = (-X + sqrt(abs(pow(X, 2) - (4 * X * Y)))) / (2 * X);
		float S = pow(4, (-3 * X)) * sin(Y);

		float C = std::max(R, S);

		std::cout << R << std::endl;
		std::cout << S << std::endl;

		return C;
	}
	else {
		std::cout << "Function sin cannot be (< -1 && > 1)" << std::endl;
	}
}

int main() {

	float X, Y;

	std::cout << "Enter X and Y" << std::endl;

	std::cin >> X;
	std::cin >> Y;

	float result = calc_func(X, Y);

	std::cout << "Max (R,S): " << result << std::endl;
}
