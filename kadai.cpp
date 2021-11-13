#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //’Tõ‚·‚é’l‚ÌãŒÀ’lB

int nth_prime(unsigned a, unsigned d, unsigned n) {
	int value = 0;
	for (int num = 0, i = 0; i < n; num++) {
		value = a + d * num;
		if (value == 2 || value == 3) {
			i += 1;
			continue;
		}
		if (value % 2 == 0 || value % 3 == 0) {
			continue;
		}

		for (int j = 4; j < value; j++) {
			if (value % j == 0) {
				break;
			}
			if (j == value - 1) {
				i += 1;
			}
		}
	}
	return value;
}
int main() {
	int a = 0, d = 0, n = 0;
	for (int i = 0; i < 12; i++) {
		std::cin >> a >> d >> n;
		std::cout << "‰€" << a << " Œö·" << d << " ‚Ì" << n << "”Ô–Ú" << std::endl;
		std::cout << nth_prime(a, d, n) << std::endl;
	}
	std::cout << nth_prime(367, 186, 151) << std::endl;
	return 0;
}