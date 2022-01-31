//HT19A021 上坂恭太
#include <iostream>
#include <string>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	   mcxi

	   mcxi 記法を解析するクラスです。
	 */
	 /* --------------------------------------------------------------------- */
	class mcxi {
		
	public:
		/* ----------------------------------------------------------------- */
		/*
		   mcxi

		   指定された文字列を解析して、オブジェクトを初期化します。
		   以下の場合には例外が創出されます。

		   1. [2-9,m,c,x,i] 以外の文字が出現した場合
		   2. 2 文字続けて数字 (2-9) が出現した場合
		   3. m, c, x, i がこの順序で出現しなかった場合
			  ただし、例えば mx のように、特定の文字をスキップする事は許容
			  されます。
		 */
		 /* ----------------------------------------------------------------- */
		bool index_m , index_c , index_x, index_i; //m,c,x,iを処理する際に用いる変数

		mcxi():value_(0){};//デフォルトコンストラクタ

		//コンストラクタ mcxi記法を解読して計算しvalue_へ代入する。
		mcxi(const std::string& s) : value_(0), index_m(true), index_c(true), index_x(true), index_i(true){
			
			int num = 1; //2から9の数値を入れておく変数
			//文字列を一字ずつ読み込む
			for (int i = 0; i < s.size(); i++) {
				//2から9の数字だった場合
				if (ctoi(s[i]) != 0) {
					num = ctoi(s[i]);
				}
				//mの場合
				else if (s[i] == 'm' && index_m && index_c && index_x && index_i) {
					value_ += num * 1000;
					index_m = false;
					num = 1;
				}
				//cの場合
				else if (s[i] == 'c' && index_c && index_x && index_i) {
					value_ += num * 100;
					index_c = false;
					num = 1;
				}
				//xの場合
				else if (s[i] == 'x' && index_x && index_i) {
					value_ += num * 10;
					index_x = false;
					num = 1;
				}
				//iの場合
				else if (s[i] == 'i' && index_i) {
					value_ += num * 1;
					index_i = false;
					num = 1;
				}
				else {
					//文字列がmcxiと2～9以外またはmcxiの順序ではないの場合の例外処理
					std::cout << s << std::endl;
					std::cout << "入力が不正です" << std::endl;
					exit(1);
				}
			}			
			
			std::cout << s << std::endl;
		}

		/* ----------------------------------------------------------------- */
		/*
		   operator+

		   2 つのオブジェクトの加算結果を取得します。
		 */
		 /* ----------------------------------------------------------------- */
		mcxi operator +(const mcxi& rhs) const{
			mcxi var;
			var.value_ = value_ + rhs.value_;
			return var;
		}

		/* ----------------------------------------------------------------- */
		/*
		   to_string

		   現在の値を mcxi 記法に変換します。
		 */
		 /* ----------------------------------------------------------------- */
		std::string to_string() const {
			std::string var = "";
			const int m_num = value_ / 1000; //1000の位の数
			const int c_num = (value_ - m_num*1000)/100; //100の位の数
			const int x_num = (value_ - (m_num*1000 + c_num*100))/10; //10の位の数
			const int i_num =  value_ - (m_num*1000 + c_num*100 + x_num*10); //1の位の数
			std::cout << m_num << c_num << x_num << i_num << std::endl;

			if (m_num > 1) {
				var += itos(m_num);
				var += "m";
			}
			else if (m_num == 1) {
				var += "m";
			}

			if (c_num > 1) {
				var += itos(c_num);
				var += "c";
			}
			else if (c_num == 1) {
				var += "c";
			}

			if (x_num > 1) {
				var += itos(x_num);
				var += "x";
			}
			else if (x_num == 1) {
				var += "x";
			}

			if (i_num > 1) {
				var += itos(i_num);
				var += "i";
			}
			else if (i_num == 1) {
				var += "i";
			}


			return var;
		}

		/* ----------------------------------------------------------------- */
		/*
		   ctoi

		   char型の2～9の文字を数値に変換し返す。それ以外は0を返す。
		 */
		 /* ----------------------------------------------------------------- */
		const int ctoi(char c) const{
			switch (c) {
			case '2': return 2;
			case '3': return 3;
			case '4': return 4;
			case '5': return 5;
			case '6': return 6;
			case '7': return 7;
			case '8': return 8;
			case '9': return 9;
			default: return 0;
			}
		}

		/* ----------------------------------------------------------------- */
		/*
		   itos

		   int型の2～9の文字をstring型に変換し返す。
		 */
		 /* ----------------------------------------------------------------- */
		const std::string itos(int i) const{
			switch (i) {
			case 2: return "2";
			case 3: return "3";
			case 4: return "4";
			case 5: return "5";
			case 6: return "6";
			case 7: return "7";
			case 8: return "8";
			case 9: return "9";
			}
		}

	private:
		int value_;
	};
}

int main() {
	cpp2::mcxi a0("1x");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;

	
	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}
