#include<iostream>
#include<string>
#include<vector>
using namespace std;
class MIPS {
private:
	string instruction, A, B, C;
public:
	string print(string instruction) {
		instruction.erase(3);
		if (instruction == "$t0") instruction = "01000";
		else if (instruction == "$t1") instruction = "01001";
		else if (instruction == "$t2") instruction = "01010";
		else if (instruction == "$t3") instruction = "01011";
		else if (instruction == "$t4") instruction = "01100";
		else if (instruction == "$t5") instruction = "01101";
		else if (instruction == "$t6") instruction = "01110";
		else if (instruction == "$t7") instruction = "01111";
		return instruction;
	}
	void pass(string a, string b, string c) {
		A = print(a);
		B = print(b);
		C = print(c);
	}
	void passi(string a, string b) {
		A = print(a);
		B = print(b);
	}
	void Binary() {
		int n;
		vector<int> binary;
		cin >> n;
		while (n != 0) {
			binary.push_back(n % 2);
			n /= 2;
		}		
		while(binary.size() < 16){
			binary.push_back(0);
		}
		for (int i = binary.size()-1; i >= 0; i--) {
			cout << binary[i];
		}
		cout << endl;
	}
	void Rtype() {
		string a, b, c;
		cin >> a >> b >> c;
		pass(a, b, c);
		cout << B << C << A;
	}
	void Addi(){
		string a, b;
		cin >> a >> b;
		passi(a, b);
		cout << B << A;
	}
};
int main() {
	MIPS func;
	string instruction;
	string a, b, c;
	int n;
	while (cin >> instruction) {
		if (instruction == "add") {
			cout << "000000";
			func.Rtype();
			cout << "00000100000\n";
		}
		else if (instruction == "sub") {
			cout << "000000";
			func.Rtype();
			cout << "00000100010\n";
		}
		else if (instruction == "or") {
			cout << "000000";
			func.Rtype();
			cout << "00000100101\n";
		}
		else if (instruction == "and") {
			cout << "000000";
			func.Rtype();
			cout << "00000100100\n";
		}
		else if (instruction == "addi") {
			cout << "001000";
			func.Addi();
			func.Binary();
		}
	}
	return 0;
}
