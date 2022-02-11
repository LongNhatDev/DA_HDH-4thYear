#include <bits/stdc++.h>
// #include <bits/long.h>
#include <stdio.h>
// #include <iostream.h>
using namespace std;

int Allocation[10][3]; // các tài nguyên mà mỗi tiến trình đang nắm
int Max[10][3];		   // tài nguyên cần tối đa của mỗi tiến trình
int Need[10][3];	   // need = max - allocation

int Request[3];	  // Current = available - request
int Available[3]; // Current = available

int p;			// Số tiến trình
int Current[3]; // tiến trình work hiện tại
// int Current[3];

int a = 1; // biến để tính toán
int request;
bool Executed[10], come;

// Tạo bảng dữ liệu
void Table()
{
	cout << "\n\n>>>>>>>>>>_Table for Bankers_<<<<<<<<<<<<<\n\n";
	cout << "Available: " << Available[0] << " " << Available[1] << " " << Available[2] << "\n\n";
	cout << "processcess    Allocation   \t Max   \t\tNeed\n";
	for (int i = 0; i < p; ++i)
	{
		Need[i][0] = Max[i][0] - Allocation[i][0];
		Need[i][1] = Max[i][1] - Allocation[i][1];
		Need[i][2] = Max[i][2] - Allocation[i][2];
		cout << "  P" << i + 1 << "    ";
		cout << " \t" << Allocation[i][0] << " " << Allocation[i][1] << " " << Allocation[i][2] << "     ";
		cout << " \t" << Max[i][0] << " " << Max[i][1] << " " << Max[i][2] << "     ";
		cout << " \t" << Need[i][0] << " " << Need[i][1] << " " << Need[i][2];
		cout << "\n";
	}
	cout << "\n\n";
}

//
void IMP()
{
	come = false;
	for (int i = 0; i < 10; ++i)
	{
		Executed[i] = false;
	}
}

// Tính toán Banker
void Calculate(){
	Current[0]=Available[0];
	Current[1]=Available[1];
	Current[2]=Available[2];
	IMP();
	int i, j;
	for (i = 0; i < p; ++i){
		for (j = 0; j < p; ++j){
			while (Executed[j] && j < p - 1){
				j++;
			}
			if (Need[j][0] <= Current[0] && Need[j][1] <= Current[1] && Need[j][2] <= Current[2]){
				if (!Executed[j]){
					Executed[j] = true;
					Current[0] += Allocation[j][0];
					Current[1] += Allocation[j][1];
					Current[2] += Allocation[j][2];
					cout << "\n*Process:" << j + 1;
					cout <<"\t" <<Current[0] << " " << Current[1] << " " << Current[2];
					come = true;
					break;
				}
			}
		}
		if (!come){
			cout << "	-->Oops Unsafe !!!!\n\n";
			break;
		}
		else{
			cout << "	-->Safe !!!!\n\n";
			come = false;
		}
	}
}

// Yêu cầu tài nguyên
void Addrequest(){
	Current[0]=Available[0];
	Current[1]=Available[1];
	Current[2]=Available[2];
	cout << "\n*Choose your process to request: ";
	cin >> request;
	cout << "Enter Request[" << request << "]:	";
	request-=1;
	cin >> Request[0] >> Request[1] >> Request[2];
	if (Current[0] >= Request[0] && Current[1] >= Request[1] && Current[2] >= Request[2]){
		Allocation[request][0] += Request[0];
		Allocation[request][1] += Request[1];
		Allocation[request][2] += Request[2];

		Need[request][0] = Max[request][0] - Allocation[request][0];
		Need[request][1] = Max[request][1] - Allocation[request][1];
		Need[request][2] = Max[request][2] - Allocation[request][2];

		Current[0] -= Request[0];
		Current[1] -= Request[1];
		Current[2] -= Request[2];
		Available[0]=Current[0];
		Available[1]=Current[1];
		Available[2]=Current[2];

		cout << "\n*After request of Process[" << ++request << "]:\n";
		Table();
	}
	else{
		cout << "Not Enough Resource!!!";
	}
}

int main()
{
	tryagain: // Nhãn để goto
	cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n*Enter Number of processcesses: "; // nhập vào số tiến trình
	cin >> p;
	cout << "\n";
	cout << "*Enter the Current resources: "; // nhập tiến trình current work ban đầu
	cin >> Current[0] >> Current[1] >> Current[2];
	Available[0]= Current[0];
	Available[1]= Current[1];
	Available[2]= Current[2];
	for (int i = 0; i < p; i++)
	{
		cout << "\n\n*processcess P" << i + 1 << " Details\n";
		cout << "Enter Allocation : ";
		cin >> Allocation[i][0] >> Allocation[i][1] >> Allocation[i][2];
		cout << "       Enter Max : ";
		cin >> Max[i][0] >> Max[i][1] >> Max[i][2];
		Need[i][0] = Max[i][0] - Allocation[i][0];
		Need[i][1] = Max[i][1] - Allocation[i][1];
		Need[i][2] = Max[i][2] - Allocation[i][2];
	}
	Table();
	Calculate();
	while (true){
		int choose;
		int process;
		cout << "\n\n*Select Below oprations:\n\n";
		cout << "[1].Change Max of process: \n";
		cout << "[2].Change Allocation of process\n";
		cout << "[3].Change Initial Work\n";
		cout << "[4].Add Request\n";
		cout << "[5].Try Another\n";
		cout << "[6].Exit\n\n";
		cin >> choose;
		if (choose == 1){
			cout << "\n\nEnter process No: ";
			cin >> process;
			cout << "\nEnter New Max: ";
			cin >> Max[process - 1][0] >> Max[process - 1][1] >> Max[process - 1][2];
			Table();
		}
		else if (choose == 2){
			cout << "\n\nEnter process No: ";
			cin >> process;
			cout << "\nEnter New Allocation: ";
			cin >> Allocation[process - 1][0] >> Allocation[process - 1][1] >> Allocation[process - 1][2];
			Table();
		}
		else if (choose == 3){
			cout << "\nEnter Initial Work: ";
			cin >> Available[0] >> Available[1] >> Available[2];
			Table();
		}
		else if (choose == 4){
			Addrequest();
		}
		else if (choose == 5){
			goto tryagain;
		}
		else{
			break;
		}
		Calculate();
	}
	return 0;
}

	