#include <iostream>
using namespace std;
class additions
{
private:
	int num, Num, ans;
	int reverseNum = 0;
	int originalNum;

public:
	additions()
	{
		cin >> num;
		int flag = 1;
		int count = 0;
		while (1)
		{
			originalNum = num;
			while (num > 0)
			{
				Num = num % 10;
				reverseNum = reverseNum * 10 + Num;
				num /= 10;
			}
			/*cout << "reverseNum = " << reverseNum << endl;*/
			if (reverseNum == originalNum && flag == 0)
			{
				ans = reverseNum;
				break;
			}
			else
			{
				num = reverseNum + originalNum;
				reverseNum = 0;
				flag = 0;
				count++;
				/*cout << "num = " << num;*/
			}
		}
		cout << count << " " << ans << endl;
	}
};

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		additions();
	}
	return 0;
}