#pragma once
#include<fstream>
#include<iostream>
#include"WallClock.h"
#include"List.h"
using namespace std;
class File//���� ����� �����������
{
public:
	File(char* _filename);
	int Open();
	int OpenText();
	void CloseText();
	const char* GetFileName();
	int Read(List <WallClock>&data);
	void Remote();
	void Add(List<WallClock>& data);
	int Readtext(List <WallClock>& data);
	void Addtext(List<WallClock>& data);
	int Cleartext();
	~File();
private:
	char filename[80]; // ��� �����
	fstream* fstr; // ��������� �� �����
	fstream str;
	int maxpos; // ����� ������� � ����
};
