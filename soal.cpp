#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void getDeposito(float& initiate, float& total){
	cout << "Masukkan uang yang ingin dideposit: ";
	cin >> initiate;
	total = initiate;
}

void getTenor(int& tenor){
	cout << "Tenor yang ingin anda ambil[1|3|6|12]: "; 
	cin >> tenor;
	if(tenor != 1 || tenor != 3 || tenor != 6 || tenor != 12) {
		cout << "Salah!";
	}
}

void getYear(int &year){
	cout << "Berapa Tahun[1-10]: ";
	cin >> year;
	if(year < 1 || year > 10) {
		cout << "Salah!";
	}
}


void getInput(float& initiate, int& tenor, float& total, int& year){
	getDeposito(initiate, total);
	getTenor(tenor);
	getYear(year);
}

void getBunga(int& tenor, float& bunga, float& total) {
	switch(tenor) {
		case 1:
			bunga = total * 0.034 / 12 * tenor;
			break;
		case 3:
			bunga = total * 0.036 / 12 * tenor;
			break;
		case 6:
			bunga = total * 0.0375 / 12 * tenor;
			break;
		case 12:
			bunga = total * 0.042 / 12 * tenor;
			break;
		default:
			cout << "Salah!";
			exit(0);
	}
}

void getTotalBunga(float& initiate, float& total, float& bunga, float& totalBunga, int& tenor, int& year){
	int i, repetitive;
	repetitive = 12 / tenor * year;
	for(i = 1; i <= repetitive; i++){
		getBunga(tenor, bunga, total);
		total += bunga;
		totalBunga = total - initiate;
	}
	total += total + bunga;
	totalBunga = total - initiate;
}

void interestExpense(float& tax, float& totalBunga){
	tax = totalBunga * 0.01;
}

void incomeTax(float& initiate, float& tax, float& totalBunga){
	if(initiate >= 1000){
		tax += totalBunga * 0.2;
	}
}

void deduction(float& initiate, float& tax, float& totalBunga){
	interestExpense(tax, totalBunga);
	incomeTax(initiate, tax, totalBunga);
}

void netInvestment(float& total, float& tax){
	float net;
	net = total - tax;
	cout << fixed << setprecision(2) << net << endl;
}

int main(){
	float total, tax;
	netInvestment(total, tax);
	return 0;
}			
