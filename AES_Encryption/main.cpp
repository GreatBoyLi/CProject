#include "encryption.h"
#include "decryption.h"
#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>

int main()
{
	// 种子密钥
	byte1 key[16] = {0x2b, 0x7e, 0x15, 0x16,
					 0x28, 0xae, 0xd2, 0xa6,
					 0xab, 0xf7, 0x15, 0x88,
					 0x09, 0xcf, 0x4f, 0x3c};

	// 进行密钥扩展
	word w[4 * (Nr + 1)];
	KeyExpansion(key, w);

	// 输出密钥
	cout << "密钥是:" << endl;
	for (int i = 0; i < 16; i++)
	{
		cout << setfill('0') << setw(2) << hex << key[i].to_ulong() << "  ";
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
	cout << endl;
	cout << "请输入要加密的明文：" << endl;
	string inputString;
	getline(cin, inputString);
	cout << endl;
	int num = inputString.size() / 16;
	vector<byte1 *> a;
	for (int i = 0; i < num; i++)
	{
		byte1 *b = new byte1[16];
		for (int j = 0; j < 16; j++)
		{
			b[j] = byte1(inputString[i * 16 + j]);
		}
		a.push_back(b);
	}
	int remainder = inputString.size() % 16;
	if (remainder != 0)
	{
		byte1 *b = new byte1[16];
		for (int i = 0; i < remainder; i++)
		{
			b[i] = byte1(inputString[num * 16 + i]);
		}
		for (int j = remainder; j < 16; j++)
		{
			b[j] = byte1(' ');
		}
		a.push_back(b);
	}
	// 输出明文
	cout << "未加密的明文是:" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << setfill('0') << setw(2) << hex << a[i][j].to_ulong() << "  ";
			if ((j + 1) % 4 == 0)
				cout << endl;
		}
		cout << endl;
	}

	// 输出密文
	cout << "加密后的密文是:" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		encrypt(a[i], w);
		for (int j = 0; j < 16; j++)
		{
			cout << setfill('0') << setw(2) << hex << a[i][j].to_ulong() << "  ";
			if ((j + 1) % 4 == 0)
				cout << endl;
		}
		cout << endl;
	}

	// 再次进行解密
	cout << "解密后的明文是:" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		decrypt(a[i], w);
		for (int j = 0; j < 16; j++)
		{
			cout << setfill('0') << setw(2) << hex << a[i][j].to_ulong() << "  ";
			if ((j + 1) % 4 == 0)
				cout << endl;
		}
		cout << endl;
	}

	cout << "英文是：" << endl;
	string c = "";
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < 16; j++)
		{
			c += static_cast<char>(a[i][j].to_ulong());
		}
	}
	cout << c << endl;
	cout << endl;

	// 测试看看能用吗
	return 0;
}