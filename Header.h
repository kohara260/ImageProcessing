#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Pixel {
	unsigned char red;
	unsigned char green;
	unsigned char blue;

	Pixel(unsigned char red, unsigned char green, unsigned char blue);
	Pixel();
};
struct Header {
	char idLength;
	char colorMapType;
	char imageType;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char pixelDepth;
	char imageDescriptor;
	vector<Pixel> pixelInfo;
	vector<Pixel> pixels;
	
	void GetInfo(string fileName);
	//vector<Pixel> GetPixelInfo(string fileName);
	void WriteInfo(string fileToOpen, string newTgaName, vector<Pixel>& _pixels);
	void WriteInfo(string fileToOpen, string newTgaName, vector<Pixel>& _pixels, short width, short height);
	bool Compare(Header& headerObj, string fileName1, string fileName2);
	vector<Pixel> Multiply(string fileName1, string fileName2);
	vector<Pixel> Multiply(vector<Pixel>& pixels, string fileName1);
	vector<Pixel> Subtract(string fileName1, string fileName2);
	vector<Pixel> Subtract(vector<Pixel>& _pixels, string fileName1);
	vector<Pixel> Screen(vector<Pixel>& _pixels, string fileName1);
	vector<Pixel> Overlay(string fileName1, string fileName2);
	vector<Pixel> Scale(string fileName, int scalar1, int scalar2);
	vector<Pixel> Add(string fileName, int addedAmount);
	vector<Pixel> RedChannel(string fileName);
	vector<Pixel> GreenChannel(string fileName);
	vector <Pixel> BlueChannel(string fileName);
	vector<Pixel> Combine(string fileName1, string fileName2, string fileName3);
	vector <Pixel> Flip(string fileName);
	vector<Pixel> ExtraCredit(string fileName1, string fileName2, string fileName3, string fileName4);
};