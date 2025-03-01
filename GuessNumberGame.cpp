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

int main() {
	//初始化随机数种子
	std::srand(static_cast<unsigned int>(std::time(0)));
	//生成一个1到100之间的随机数
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
	return 0;
}