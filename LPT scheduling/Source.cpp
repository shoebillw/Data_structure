#include<iostream>
#include<stdlib.h> 
#include<string>
using namespace std;
int trans(string);
int change(char);
int m=0;//Job
int temp_arr[10000];
int main()
{
	string in; 
	int n;//number of machinecout 
	cout << "Please enter the number of machines:" << endl;
	cin >> n;
	cout << "Please enter the jobs:" << endl;
	getline(cin, in);
	getline(cin, in);
	trans(in);
	int *input;
	int *time;
	m--;
	input = new int[m];
	time = new int[n];
	int ** array;
	array = new int *[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[m];
	}
	for (int i = 0; i < m; i++)
	{
		input[i] = temp_arr[i];
	}
	int temp;
	////////////////////////////
	for (int i = m - 1; i > 0; i--)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (input[j] < input[j + 1])
			{
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}/////做降冪排列
	////////////////////////////
	system("pause");
	for (int i = 0; i < m; i++)
	{
		temp = 0;
		for (int j = 0; j < n-1; j++)
		{
			if (time[j] > time[j + 1])
			{
				temp = j + 1;
			}
		}
		time[temp] = time[temp] + input[i];
		for (int k = 0; k < m; k++)
		{
			if (array[temp][k] != NULL)
			{
				array[temp][k] = input[i];
				cout << "( " << temp + 1 << ", " << input[i] << " )" << endl;
				break;
			}
		}
	}//////Job分配給每個Machine
	system("pause");
	return 0;
}
int trans(string a)
{
	int out=0;
	a.push_back(' ');
	for (int i = 0; i < a.size(); i++)
	{
		if (i == a.size() - 1 )
		{
			out = change(a[i]);
			temp_arr[m] = out;
			m++;
		}
		else if (a[i + 1] == ' ')
		{
			out = change(a[i]);
			temp_arr[m] = out;
			m++;
		}
		else if (a[i + 2] == ' ')
		{
			out = 10 * change(a[i]) + change(a[i + 1]);
			temp_arr[m] = out;
			m++;
			i = i + 1;
		}
		else
		{
		}
	}
	return out;
}
int change(char b)
{
	int out=0;
	if (b == '0') out = 0;
	if (b == '1') out = 1;
	if (b == '2') out = 2;
	if (b == '3') out = 3;
	if (b == '4') out = 4;
	if (b == '5') out = 5;
	if (b == '6') out = 6;
	if (b == '7') out = 7;
	if (b == '8') out = 8;
	if (b == '9') out = 9;
	return out;
}