#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

/* --------------------------------------------------------------- */
/*
*  is_prime
*
*
与えられた正整数 xに対して素数かどうか判定する
*/
/* -------------------------------------------------------------- */
bool is_prime(int x) {
	//2からx-1までの数がxで割れるかをチェックする
	//もしも割れたらfalseを返す
	if (x == 1)
		return false;
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return false;
	};
	return true;
}
/* --------------------------------------------------------------- */
/*
*  nth_prime
*
*
与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
*  素数を返す。
*
*  TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
*  ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
//不正な入力値(負の数)を摘出
int nth_prime(int a, unsigned d, unsigned n) {
	if (a < 0 || d < 0 || n < 0)
		throw std::out_of_range("正整数を入力してください");

	int num = a;
	int count = 0; //素数なら増加
	while (num < 1000000) {
		if (is_prime(num))
			count++;
		if (count == n) {
			break;
			count << 0;
		}
		num = num + d;
		// std::cout << i << std::endl;
	};
	std::cout << "初項" << a << "  公差" << d << "  の等差数列の" << n << "番目の素数は" << num << "である ---> ";
	return num;
}
/* --------------------------------------------------------------- */
/*
*  comper_prime
*
*
与えられた正整数 numとans が同じか調べ、真偽を表示する。
*/
/* -------------------------------------------------------------- */

void compare_prime(int num, int ans) {
	if (num == ans) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}
}


int main() {
	//テスト
	try {
		compare_prime(nth_prime(367, 186, 151), 92809);
		compare_prime(nth_prime(179, 10, 203), 6709);
		compare_prime(nth_prime(271, 37, 39), 12037);
		compare_prime(nth_prime(103, 230, 1), 103);
		compare_prime(nth_prime(27, 104, 185), 93523);
		compare_prime(nth_prime(253, 50, 85), 14503);
		compare_prime(nth_prime(1, 1, 1), 2);
		compare_prime(nth_prime(9075, 337, 210), 899429);
		compare_prime(nth_prime(307, 24, 79), 5107);
		compare_prime(nth_prime(331, 221, 177), 412717);
		compare_prime(nth_prime(259, 170, 40), 22699);
		compare_prime(nth_prime(269, 58, 102), 25673);
	}
	catch (std::exception& e) {
		std::cerr << "不正な入力があります" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	
	return 0;
}
