#include "stdafx.h"

class Task 
{
public:
	int taskNumerator;
	int t1, t2, t3;
	int taskExecuteTimeSummary;
};

int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b) 
{
	return a < b ? a : b;
}

bool sortingFactor(const Task& task1, const Task& task2)
{
	return task1.taskExecuteTimeSummary > task2.taskExecuteTimeSummary;
}

std::vector<Task>& sort(std::vector<Task>& tasks)
{
	sort(tasks.begin(), tasks.end(), sortingFactor);
	return tasks;
}

int Neh(std::vector<Task>& tasks, int numberOfMachines, int numberOfTasks) 
{
	sort(tasks);


	return 0;
}

int main() {
	std::vector<Task> tasks;
	std::string fileName = "NEH3.DAT";
	int numberOfTasks;
	int numberOfMachines;
	int result = 0;
	std::ifstream plik;
	plik.open(fileName);
	if (plik.is_open()) {
		plik >> numberOfTasks >> numberOfMachines;
		for (unsigned i = 0; i < numberOfTasks; ++i) 
		{
			Task task;
			plik >> task.t1 >> task.t2 >> task.t3;
			task.taskExecuteTimeSummary = task.t1 + task.t2 + task.t3;
			tasks.push_back(task);
		}

		plik.close();
	}
	else std::cout << "blad otwarcia" << std::endl;

	result = Neh(tasks, numberOfMachines, numberOfTasks);
	std::cout << result << std::endl;

	/*
	std::ofstream plikout;
	plikout.open("wyjsciowe.txt");
	plikout << zadVec.back().momentZakonczenia;
	plikout.close();

	*/

	system("pause");
	return 0;
}