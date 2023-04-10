#ifndef KEYEXTEND_H
#define KEYEXTEND_H

#include <bitset>

using namespace std;

typedef bitset<8> byte1;
typedef bitset<32> word;

extern byte1 S[256];
extern byte1 inv_S[256];
extern word rcon[10];
extern byte1 encry_s[4 * 4];
extern byte1 decry_s[4 * 4];

// 定义种子密钥长度以及扩展轮数
const int Nr = 10; // 轮数
const int Nk = 4;  // 种子密钥有四个字

// 密钥扩展 相关函数
// 1 四个字节转换成一个字
word Wrod(byte1 b0, byte1 b1, byte1 b2, byte1 b3);

// 2 字移位
word CycWord(word rw);

// 3 S盒替换
word SubWrod(word sw);

// 4 密钥扩展
void KeyExpansion(byte1 key[5 * Nk], word w[4 * (Nr + 1)]);

#endif