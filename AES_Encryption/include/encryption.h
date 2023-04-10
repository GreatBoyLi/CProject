#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include "keyExtend.h"

using namespace std;

/*
预处理工作
	1 设计有限域上的乘法函数
*/

// 设计有限域上的乘法函数
byte1 GFMul(byte1 a, byte1 b);

// 1 轮密钥加
void RKey_Add(byte1 sta_matr[4 * 4], word w[4]);

// 2 字节代换
void SubBytes(byte1 sta_matr[4 * 4]);

// 3 行移位--按行进行字节移位
void ShiftRow(byte1 sta_matr[4 * 4]);

// 4 列混合
void MixColumns(byte1 sta_matr[4 * 4], byte1 s[4 * 4]);

// 5 加密函数
void encrypt(byte1 in[4 * 4], word w[4 * (Nr + 1)]);

#endif