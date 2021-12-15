#pragma once
class Zadacha
{
private:
	int pid;
	int cpuburst;
	int time;
	int resurce;
public:
	Zadacha() {
		pid = 0;
		cpuburst = 0;
		time = 0;
		resurce = 0;
	}
	void setZadacha(int pid1, int cpuburst1, int time1, int resurce1) {
		pid = pid1;
		cpuburst = cpuburst1;
		time = time1;
		resurce = resurce1;
	}
	int repid() { return pid; }
	int recpuburst() { return cpuburst; }
	int reptime() { return time; }
	int represurce() { return resurce; }
};

