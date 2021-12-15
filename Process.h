#pragma once
#include <iostream>
#include "PMemory.h"
class Process
{
private:
	bool done;
	int pid;
	int cpuburst;
	int time;
	int resurce;
	int address;
	int file;
	int** vap = new int* [1];
	int** tabl = new int* [1];
public:
	Process() {
		done = false;
		pid = 0;
		cpuburst = 0;
		time = 0;
		resurce = 0;
		address = 0;
		file = -1;
	}
	void setProcess(int pid1, int cpuburst1, int time1, int resurce1) {
		pid = pid1;
		cpuburst = cpuburst1;
		time = time1;
		resurce = resurce1;
	}
	void setMemory() {
		vap = new int* [resurce];
		for (int i = 0; i < resurce; i++) vap[i] = new int[SIZESTR];
		tabl = new int* [resurce];
		for (int i = 0; i < resurce; i++) {
			tabl[i] = new int[TABLBYTE];
			for (int j = 0; j < TABLBYTE; j++) tabl[i][j] = 0;
		}

		int j = -1;
		for (int i = 0; i < M; i++) {
			if (pmemory[i][0] == 0) {
				if (j != resurce - 1) j++;
				else break;
				tabl[j][0] = i + 1;
				if (pid == 0)pmemory[i][0] = 1;
				else pmemory[i][0] = pid * 10;
			}
		}
		address = 1;
	}
	int chektabl() {
		for (int i = 0; i < resurce; i++) {
			if (tabl[i][0] == 0) {
				return 1;
			}
		}
		return 0;
	}
	void vigruz() {
		int j = 0;
		int next = 0;
		for (int i = 0; i < M * 10; i++) {
			if (j < resurce) {
				if (hard[i][0] == 0) {
					if (file == -1) {
						hard[i][0] = 0;
						hard[i][1] = tabl[j][0];
						file = i;
						next = i;
					}
					else {
						hard[next][0] = i;
						next = i;
					}
					j++;
				}
			}
			else break;
		}
		
		for (int i = 0; i < resurce; i++) {
			pmemory[tabl[i][0] - 1][0] = 0;
			tabl[i][0] = 0;
		}
		address = 0;
	}
	int repid() { return pid; }
	int recpuburst() { return cpuburst; }
	int reptime() { return time; }
	int represurce() { return resurce; }
	int readdress() { return address; }
	void printtabl() {
		for (int i = 0; i < resurce; i++) std::cout << i << ":" << tabl[i][0] << " ";
	}
	void work() {
		cpuburst--;
		if (cpuburst <= 0) done = true;
		else done = false;
	}
	bool redone() { return done; }
	void setdone() { done = true; }
};

