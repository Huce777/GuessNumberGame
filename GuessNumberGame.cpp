// GuessNumberGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>

//常量定义
const int MAX_ATTEMPTS_EASY = 10;
const int MAX_ATTEMPTS_MEDIUM = 7;
const int MAX_ATTEMPTS_HARD = 5;
const int MAX_NUMBER_EASY = 50;
const int MAX_NUMBER_MEDIUM = 100;
const int MAX_NUMBER_HARD = 200;

//函数声明
int generateRandomNumber(int maxNumber);
int getMaxAttempts(int difficulty);
int getMaxNumber(int difficulty);
void playGame(int difficulty);
bool askToPlayAgain();

int main() {
	//初始化随机数种子
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "欢迎来到猜数字游戏！\n";
	/*
	int secreNumber = std::rand() % 100 + 1;
	int guess = 0;
	int attempts = 0;
	std::cout << "欢迎来到猜数字游戏！\n";
	std::cout << "我已经想到一个1到100之间的数字，你能猜出来吗？\n";
	//游戏主循环
	while (guess != secreNumber) {
		std::cout << "请输入你的猜测:";
		std::cin >> guess;
		attempts++;
		if (guess > secreNumber) {
			std::cout << "数字太大了\n";
		}
		else if (guess < secreNumber) {
			std::cout << "数字太小了\n";
		}
		else {
			std::cout << "恭喜你猜对了\n";
			std::cout << "你一共猜了" << attempts << "次\n";
		}
	}
	return 0;*/
	do {
		std::cout << "请选择难度级别(1:简单，2:中等，3:困难)：";
		int difficulty;
		while (!(std::cin >> difficulty) || difficulty < 1 || difficulty>3) {
			std::cin.clear(); //清除错误状态
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//忽略无效输入
			std::cout << "无效的选择，请输入1到3之间的数字";
		}
		playGame(difficulty); //开始游戏
	} while (askToPlayAgain()); //询问是否再玩一次

	std::cout << "感谢游玩，再见！\n";
	return 0;
}

//生成随机数字
int generateRandomNumber(int maxNumber) {
	return std::rand() % maxNumber + 1;
}

//获取最大猜测次数
int getMaxAttempts(int difficulty) {
	switch (difficulty) {
	case 1:return MAX_ATTEMPTS_EASY;
	case 2:return MAX_ATTEMPTS_MEDIUM;
	case 3:return MAX_ATTEMPTS_HARD;
	default:return MAX_ATTEMPTS_MEDIUM;
	}
}

//获取最大数字范围
int getMaxNumber(int difficulty) {
	switch (difficulty) {
	case 1:return MAX_NUMBER_EASY;
	case 2:return MAX_NUMBER_MEDIUM;
	case 3:return MAX_NUMBER_HARD;
	default:return MAX_ATTEMPTS_MEDIUM;
	}
}

//游戏主逻辑
void playGame(int difficulty) {
	int maxNumber = getMaxNumber(difficulty);
	int maxAttempts = getMaxAttempts(difficulty);
	int secretNumber = generateRandomNumber(maxNumber);
	int guess = 0;
	int attempts = 0;

	std::cout << "我已经想到一个1到" << maxNumber << "之间的数字，你能在" << maxAttempts << "次猜出来吗？\n";

	while (attempts < maxAttempts) {
		std::cout << "请输入你的猜测(剩余次数:" << maxAttempts - attempts << "):";
		while (!(std::cin >> guess)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "无效的输入，请输入一个数字：";
		}
		attempts++;

		if (guess > secretNumber) {
			std::cout << "数字太大了！\n";
		}
		else if (guess < secretNumber) {
			std::cout << "数字太小了！\n";
		}
		else {
			std::cout << "恭喜你猜对了！你一共猜了" << attempts << "次。\n";
			return;
		}
	}
	std::cout << "很遗憾，你没有在规定的次数内猜中数字。正确答案是" << secretNumber << "。\n";
}

//询问是否再玩一次
bool askToPlayAgain() {
	char choice;
	std::cout << "你想再玩一次吗？(y/n):";
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //清除缓存区
	return (choice == 'y' || choice == 'Y');
}