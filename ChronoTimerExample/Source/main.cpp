#include <iostream>
#include <chrono>
struct ChronoTimer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	ChronoTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~ChronoTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() *1000.0f;
		std::cout << "Timer took " << ms << "ms" << '\n';
	}
};
void Function() {
	ChronoTimer timer; // Create the Timer at the Beginning of your Function and it will be fine
	for (int i = 0; i < 10; i++) {
		std::cout << "hello world!\n";
	}
}
int main()
{
	Function();
	std::cin.get();
	return 0;
}