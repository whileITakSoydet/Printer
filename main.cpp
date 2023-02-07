#include <iostream>

using namespace std;

class QueuePri
{
	string* queue;
	int* pri;
	int maxSize;
	int inqueue;
	string* statistics;
	int statsize;

	void Memory(string& nam)
	{
		string* buff = new string[statsize + 1];
		for (int i = 0; i < statsize; i++)
		{
			buff[i] = statistics[i];
		}
		buff[statsize] = nam;
		delete[] statistics;
		statistics = buff;
		statsize++;
	}
public:

	QueuePri(int s)
	{
		maxSize = s;
		queue = new string[maxSize];
		pri = new int[maxSize];
		inqueue = 0;
		statsize = 0;
		statistics = nullptr;
	}

	~QueuePri()
	{
		//óäàëåíèå î÷åðåäè
		delete[] queue;
		delete[] pri;
		delete[] statistics;
	}

	void add(string c, int p)
	{
		if (!isFull()) {
			queue[inqueue] = c;
			pri[inqueue] = p;
			inqueue++;
		}
	}

	string extract()
	{
		if (!isEmpty()) 
		{
			int max_pri = pri[0];
			int pos_max_pri = 0;
			for (int i = 1; i < inqueue; i++)
				if (max_pri < pri[i]) 
				{
					max_pri = pri[i];
					pos_max_pri = i;
				}
			string temp1 = queue[pos_max_pri];
			int temp2 = pri[pos_max_pri];
			for (int i = pos_max_pri; i < inqueue - 1; i++) 
			{
				queue[i] = queue[i + 1];
				pri[i] = pri[i + 1];
			}
			inqueue--;
			Memory(temp1);
			return temp1;
		}
		else return "";
	}

	void clear()
	{
		inqueue = 0;
	}

	bool isEmpty()
	{
		return inqueue == 0;
	}

	bool isFull()
	{
		return inqueue == maxSize;
	}

	int getCount()
	{
		return inqueue;
	}

	void show()
	{
		cout << "List queue:\n";
		for (int i = 0; i < inqueue; i++)
		{
			cout << queue[i] << " - " << pri[i] << "\t";
		}
		cout << endl;
	}

	void showStatistics()
	{
		cout << "Print data: ";
		for (int i = 0; i < statsize; i++)
		{
			cout << statistics[i] << "|\t";
		}
	}
};

int main()
{
	QueuePri wait(10);
	wait.add("worker2", 1);
	wait.add("manager", 2);
	wait.add("worker1", 1);
	wait.add("worker3", 1);
	wait.add("boss", 3);
	wait.add("worker4", 1);
	wait.add("my", 100000);
	wait.show();

	cout << wait.extract() << endl;
	cout << wait.extract() << endl;
	cout << wait.extract() << endl;

	wait.show();
	wait.showStatistics();


	return 0;
}
