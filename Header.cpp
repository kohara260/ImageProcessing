#include "Header.h"
#include <iostream>
#include <fstream>

Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Pixel::Pixel() {
	red = 0;
	green = 0;
	blue = 0;
}

void Header::GetInfo(string fileName) {
	ifstream file(fileName, ios_base::binary);
	if (file.is_open()) {
		file.read(&idLength, sizeof(idLength));
		file.read(&colorMapType, sizeof(colorMapType));
		file.read(&imageType, sizeof(imageType));
		file.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
		file.read((char*)&colorMapLength, sizeof(colorMapLength));
		file.read(&colorMapDepth, sizeof(colorMapDepth));
		file.read((char*)&xOrigin, sizeof(xOrigin));
		file.read((char*)&yOrigin, sizeof(yOrigin));
		file.read((char*)&width, sizeof(width));
		file.read((char*)&height, sizeof(height));
		file.read(&pixelDepth, sizeof(pixelDepth));
		file.read(&imageDescriptor, sizeof(imageDescriptor));

		int length = width * height;
		unsigned char red;
		unsigned char green;
		unsigned char blue;

		for (int i = 0; i < length; i++) {
			file.read((char*)&blue, sizeof(blue));
			file.read((char*)&green, sizeof(green));
			file.read((char*)&red, sizeof(red));
			Pixel pixel(red, green, blue);
			pixelInfo.push_back(pixel);
		}
		pixels = pixelInfo;
		pixelInfo.clear();

		file.close();
	}
	else {
		cout << "Not open :(" << endl;
	}
}

void Header::WriteInfo(string fileToOpen, string newTgaName, vector<Pixel>& _pixels) {
	ifstream file(fileToOpen, ios_base::binary);
	GetInfo(fileToOpen);

	fstream newTgaFile;
	newTgaFile.open(newTgaName, ios_base::out | ios_base::binary);
	if (newTgaFile.is_open()) {
		newTgaFile.write(&idLength, sizeof(idLength));
		newTgaFile.write(&colorMapType, sizeof(colorMapType));
		newTgaFile.write(&imageType, sizeof(imageType));
		newTgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
		newTgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));
		newTgaFile.write(&colorMapDepth, sizeof(colorMapDepth));
		newTgaFile.write((char*)&xOrigin, sizeof(xOrigin));
		newTgaFile.write((char*)&yOrigin, sizeof(yOrigin));
		newTgaFile.write((char*)&width, sizeof(width));
		newTgaFile.write((char*)&height, sizeof(height));
		newTgaFile.write(&pixelDepth, sizeof(pixelDepth));
		newTgaFile.write(&imageDescriptor, sizeof(imageDescriptor));

		pixels = _pixels;
		for (unsigned int i = 0; i < pixels.size(); i++) {
			unsigned char blue = pixels.at(i).blue;
			newTgaFile.write((char*)&blue, sizeof(blue));
			unsigned char green = pixels.at(i).green;
			newTgaFile.write((char*)&green, sizeof(green));
			unsigned char red = pixels.at(i).red;
			newTgaFile.write((char*)&red, sizeof(red));
		}
		newTgaFile.close();
	}
}

void Header::WriteInfo(string fileToOpen, string newTgaName, vector<Pixel>& _pixels, short _width, short _height) {
	ifstream file(fileToOpen, ios_base::binary);
	GetInfo(fileToOpen);

	fstream newTgaFile;
	newTgaFile.open(newTgaName, ios_base::out | ios_base::binary);
	if (newTgaFile.is_open()) {
		newTgaFile.write(&idLength, sizeof(idLength));
		newTgaFile.write(&colorMapType, sizeof(colorMapType));
		newTgaFile.write(&imageType, sizeof(imageType));
		newTgaFile.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
		newTgaFile.write((char*)&colorMapLength, sizeof(colorMapLength));
		newTgaFile.write(&colorMapDepth, sizeof(colorMapDepth));
		newTgaFile.write((char*)&xOrigin, sizeof(xOrigin));
		newTgaFile.write((char*)&yOrigin, sizeof(yOrigin));
		width = _width;
		newTgaFile.write((char*)&width, sizeof(width));
		height = _height;
		newTgaFile.write((char*)&height, sizeof(height));
		newTgaFile.write(&pixelDepth, sizeof(pixelDepth));
		newTgaFile.write(&imageDescriptor, sizeof(imageDescriptor));

		pixels = _pixels;
		for (unsigned int i = 0; i < pixels.size(); i++) {
			unsigned char blue = pixels.at(i).blue;
			newTgaFile.write((char*)&blue, sizeof(blue));
			unsigned char green = pixels.at(i).green;
			newTgaFile.write((char*)&green, sizeof(green));
			unsigned char red = pixels.at(i).red;
			newTgaFile.write((char*)&red, sizeof(red));
		}
		newTgaFile.close();
	}
}

bool Header::Compare(Header& headerObj, string fileName1, string fileName2) {
	bool match = false;
	Header firstHeader = headerObj;
	firstHeader.GetInfo(fileName1);
	vector<Pixel> file1Pixels = firstHeader.pixels; //output pixels
	Header tempHeader;
	tempHeader.GetInfo(fileName2);
	vector<Pixel> file2Pixels = tempHeader.pixels;

	if (firstHeader.idLength == tempHeader.idLength) {
		match = true;
	}
	else {
		cout << "idLengths do not match" << endl;
		return match = false;
	}
	
	if (match == true) {
		if (firstHeader.colorMapType == tempHeader.colorMapType) {
			match = true;
		}
		else {
			cout << "colorMapTypes do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.imageType == tempHeader.imageType) {
			match = true;
		}
		else {
			cout << "imageTypes do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.colorMapOrigin == tempHeader.colorMapOrigin) {
			match = true;
		}
		else {
			cout << "colorMapOrigins do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.colorMapLength == tempHeader.colorMapLength) {
			match = true;
		}
		else {
			cout << "colorMapLengths do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.colorMapDepth == tempHeader.colorMapDepth) {
			match = true;
		}
		else {
			cout << "colorMapDepths do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.xOrigin == tempHeader.xOrigin) {
			match = true;
		}
		else {
			cout << "xOrigins do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.yOrigin == tempHeader.yOrigin) {
			match = true;
		}
		else {
			cout << "yOrigins do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.width == tempHeader.width) {
			match = true;
		}
		else {
			cout << "widths do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.height == tempHeader.height) {
			match = true;
		}
		else {
			cout << "heights do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.pixelDepth == tempHeader.pixelDepth) {
			match = true;
		}
		else {
			cout << "pixelDepths do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (firstHeader.imageDescriptor == tempHeader.imageDescriptor) {
			match = true;
		}
		else {
			cout << "imageDescriptors do not match" << endl;
			return match = false;
		}
	}
	if (match == true) {
		if (file1Pixels.size() == file2Pixels.size()) {
			for (unsigned int i = 0; i < file1Pixels.size(); i++) {
				if (file1Pixels.at(i).red == file2Pixels.at(i).red) {
					match = true;
				}
				else {
					match = false;
					cout << "Red pixels do not match at index " << i << endl;
				}
				if (file1Pixels.at(i).green == file2Pixels.at(i).green) {
					match = true;
				}
				else {
					match = false;
					cout << "Green pixels do not match at index " << i << endl;
				}
				if (file1Pixels.at(i).blue == file2Pixels.at(i).blue) {
					match = true;
				}
				else {
					match = false;
					cout << "Blue pixels do not match at index " << i << endl;
				}
			}
		}
	}
	return match;
}

vector<Pixel> Header::Multiply(string fileName1, string fileName2) {
	GetInfo(fileName1);
	vector<Pixel> topLayer = pixels;
	GetInfo(fileName2);
	vector<Pixel> bottomLayer = pixels;
	vector<Pixel> multipliedPixels;

	for (unsigned int i = 0; i < topLayer.size(); i++) {
		float redTop = topLayer.at(i).red / 255.0f;
		float redBottom = bottomLayer.at(i).red / 255.0f;
		float redResult = (((redTop * redBottom) * 255.0f) + 0.5f);
		float greenTop = topLayer.at(i).green / 255.0f;
		float greenBottom = bottomLayer.at(i).green / 255.0f;
		float greenResult = (((greenTop * greenBottom) * 255.0f) + 0.5f);
		float blueTop = topLayer.at(i).blue / 255.0f;
		float blueBottom = bottomLayer.at(i).blue / 255.0f;
		float blueResult = (((blueTop * blueBottom) * 255.0f) + 0.5f);

		Pixel newPixel;
		newPixel.red = redResult;
		newPixel.green = greenResult;
		newPixel.blue = blueResult;

		multipliedPixels.push_back(newPixel);
	}
	return multipliedPixels;
}

vector<Pixel> Header::Multiply(vector<Pixel>& _pixels, string fileName1) {
	GetInfo(fileName1);
	vector<Pixel> topLayer = pixels;
	vector<Pixel> bottomLayer = _pixels;
	vector<Pixel> multipliedPixels;

	for (unsigned int i = 0; i < topLayer.size(); i++) {
		float redTop = topLayer.at(i).red / 255.0f;
		float redBottom = bottomLayer.at(i).red / 255.0f;
		float redResult = (((redTop * redBottom) * 255.0f) + 0.5f);
		float greenTop = topLayer.at(i).green / 255.0f;
		float greenBottom = bottomLayer.at(i).green / 255.0f;
		float greenResult = (((greenTop * greenBottom) * 255.0f) + 0.5f);
		float blueTop = topLayer.at(i).blue / 255.0f;
		float blueBottom = bottomLayer.at(i).blue / 255.0f;
		float blueResult = (((blueTop * blueBottom) * 255.0f) + 0.5f);

		Pixel newPixel;
		newPixel.red = redResult;
		newPixel.green = greenResult;
		newPixel.blue = blueResult;

		multipliedPixels.push_back(newPixel);
	}
	return multipliedPixels;
}

vector<Pixel> Header::Subtract(string fileName1, string fileName2) {
	GetInfo(fileName1);
	vector<Pixel> topLayer = pixels;
	GetInfo(fileName2);
	vector<Pixel> bottomLayer = pixels;
	vector<Pixel> subtractedPixels;

	for (unsigned int i = 0; i < topLayer.size(); i++) {
		int redTop = topLayer.at(i).red;
		int redBottom = bottomLayer.at(i).red;
		int redResult = redBottom - redTop;
		if (redResult < 0) {
			redResult = 0;
		}
		if (redResult > 255) {
			redResult = 255;
		}
		int greenTop = topLayer.at(i).green;
		int greenBottom = bottomLayer.at(i).green;
		int greenResult = greenBottom - greenTop;
		if (greenResult < 0) {
			greenResult = 0;
		}
		if (greenResult > 255) {
			greenResult = 255;
		}
		int blueTop = topLayer.at(i).blue;
		int blueBottom = bottomLayer.at(i).blue;
		int blueResult = blueBottom - blueTop;
		if (blueResult < 0) {
			blueResult = 0;
		}
		if (blueResult > 255) {
			blueResult = 255;
		}

		Pixel newPixel;
		newPixel.red = redResult;
		newPixel.green = greenResult;
		newPixel.blue = blueResult;

		subtractedPixels.push_back(newPixel);
	}
	return subtractedPixels;
}

vector<Pixel> Header::Subtract(vector<Pixel>& _pixels, string fileName1) {
	GetInfo(fileName1);
	vector<Pixel> topLayer = pixels;
	vector<Pixel> bottomLayer = _pixels;
	vector<Pixel> subtractedPixels;

	for (unsigned int i = 0; i < topLayer.size(); i++) {
		int redTop = topLayer.at(i).red;
		int redBottom = bottomLayer.at(i).red;
		int redResult = redBottom - redTop;
		if (redResult < 0) {
			redResult = 0;
		}
		if (redResult > 255) {
			redResult = 255;
		}
		int greenTop = topLayer.at(i).green;
		int greenBottom = bottomLayer.at(i).green;
		int greenResult = greenBottom - greenTop;
		if (greenResult < 0) {
			greenResult = 0;
		}
		if (greenResult > 255) {
			greenResult = 255;
		}
		int blueTop = topLayer.at(i).blue;
		int blueBottom = bottomLayer.at(i).blue;
		int blueResult = blueBottom - blueTop;
		if (blueResult < 0) {
			blueResult = 0;
		}
		if (blueResult > 255) {
			blueResult = 255;
		}

		Pixel newPixel;
		newPixel.red = redResult;
		newPixel.green = greenResult;
		newPixel.blue = blueResult;

		subtractedPixels.push_back(newPixel);
	}
	return subtractedPixels;
}

vector<Pixel> Header::Screen(vector<Pixel>& _pixels, string fileName1) {
	GetInfo(fileName1);
	vector<Pixel> topLayer = pixels;
	vector<Pixel> bottomLayer = _pixels;
	vector<Pixel> screenedPixels;

	for (unsigned int i = 0; i < topLayer.size(); i++) {
		float redTop = (1 - (topLayer.at(i).red / 255.0f));
		float redBottom = (1 - (bottomLayer.at(i).red / 255.0f));
		float redResult = (((1 - (redTop * redBottom)) * 255.0f) + 0.5f);
		if (redResult < 0) {
			redResult = 0;
		}
		if (redResult > 255) {
			redResult = 255;
		}
		float greenTop = (1 - (topLayer.at(i).green / 255.0f));
		float greenBottom = (1 - (bottomLayer.at(i).green / 255.0f));
		float greenResult = (((1 - (greenTop * greenBottom)) * 255.0f) + 0.5f);
		if (greenResult < 0) {
			greenResult = 0;
		}
		if (greenResult > 255) {
			greenResult = 255;
		}
		float blueTop = (1 - (topLayer.at(i).blue / 255.0f));
		float blueBottom = (1 - (bottomLayer.at(i).blue / 255.0f));
		float blueResult = (((1 - (blueTop * blueBottom)) * 255.0f) + 0.5f);
		if (blueResult < 0) {
			blueResult = 0;
		}
		if (blueResult > 255) {
			blueResult = 255;
		}

		Pixel newPixel;
		newPixel.red = redResult;
		newPixel.green = greenResult;
		newPixel.blue = blueResult;

		screenedPixels.push_back(newPixel);
	}
	return screenedPixels;
}

vector<Pixel> Header::Overlay(string fileName1, string fileName2) {
	GetInfo(fileName1);
	vector<Pixel> topLayer = pixels;
	GetInfo(fileName2);
	vector<Pixel> bottomLayer = pixels;
	vector<Pixel> overlayedPixels;

	for (unsigned int i = 0; i < topLayer.size(); i++) {
		float redTop = topLayer.at(i).red / 255.0f;
		float redBottom = bottomLayer.at(i).red / 255.0f;
		float redResult = 0.0f;
		if (redBottom <= 0.5) {
			redResult = (((2 * (redTop * redBottom)) * 255.0f) + 0.5f);
		}
		if (redBottom > 0.5) {
			redTop = (1 - redTop);
			redBottom = (1 - redBottom);
			redResult = (((1 - (2 * (redTop * redBottom))) * 255.0f) + 0.5f);
		}
		float greenTop = topLayer.at(i).green / 255.0f;
		float greenBottom = bottomLayer.at(i).green / 255.0f;
		float greenResult = 0.0f;
		if (greenBottom <= 0.5) {
			greenResult = (((2 * (greenTop * greenBottom)) * 255.0f) + 0.5f);
		}
		if (greenBottom > 0.5) {
			greenTop = (1 - greenTop);
			greenBottom = (1 - greenBottom);
			greenResult = (((1 - (2 * (greenTop * greenBottom))) * 255.0f) + 0.5f);
		}
		float blueTop = topLayer.at(i).blue / 255.0f;
		float blueBottom = bottomLayer.at(i).blue / 255.0f;
		float blueResult = 0.0f;
		if (blueBottom <= 0.5) {
			blueResult = (((2 * (blueTop * blueBottom)) * 255.0f) + 0.5f);
		}
		if (blueBottom > 0.5) {
			blueTop = (1 - blueTop);
			blueBottom = (1 - blueBottom);
			blueResult = (((1 - (2 * (blueTop * blueBottom))) * 255.0f) + 0.5f);
		}

		Pixel newPixel;
		newPixel.red = redResult;
		newPixel.green = greenResult;
		newPixel.blue = blueResult;

		overlayedPixels.push_back(newPixel);
	}
	return overlayedPixels;
}

vector<Pixel> Header::Scale(string fileName, int scalar1, int scalar2) {
	GetInfo(fileName);
	vector<Pixel> scaledPixels;

	for (unsigned int i = 0; i < pixels.size(); i++) {
		int _red = (pixels.at(i).red * scalar1);
		if (_red > 255) {
			_red = 255;
		}
		unsigned char _green = pixels.at(i).green;
		int _blue = (pixels.at(i).blue * scalar2);
		Pixel pixel;
		pixel.red = _red;
		pixel.green = _green;
		pixel.blue = _blue;
		scaledPixels.push_back(pixel);
	}
	return scaledPixels;
}

vector<Pixel> Header::Add(string fileName, int addedAmount) {
	GetInfo(fileName);
	vector<Pixel> added;

	for (unsigned int i = 0; i < pixels.size(); i++) {
		unsigned char _red = pixels.at(i).red;
		int newGreen = pixels.at(i).green + addedAmount;
		if (newGreen > 255) {
			newGreen = 255;
		}
		unsigned char _blue = pixels.at(i).blue;
		Pixel pixel;
		pixel.red = _red;
		pixel.green = newGreen;
		pixel.blue = _blue;
		added.push_back(pixel);
	}
	return added;
}

vector<Pixel> Header::RedChannel(string fileName) {
	GetInfo(fileName);

	for (unsigned int i = 0; i < pixels.size(); i++) {
		pixels.at(i).green = pixels.at(i).red;
		pixels.at(i).blue = pixels.at(i).red;
	}
	return pixels;
}

vector<Pixel> Header::GreenChannel(string fileName) {
	GetInfo(fileName);

	for (unsigned int i = 0; i < pixels.size(); i++) {
		pixels.at(i).red = pixels.at(i).green;
		pixels.at(i).blue = pixels.at(i).green;
	}
	return pixels;
}

vector <Pixel> Header::BlueChannel(string fileName) {
	GetInfo(fileName);

	for (unsigned int i = 0; i < pixels.size(); i++) {
		pixels.at(i).green = pixels.at(i).blue;
		pixels.at(i).red = pixels.at(i).blue;
	}
	return pixels;
}

vector<Pixel> Header::Combine(string fileName1, string fileName2, string fileName3) {
	GetInfo(fileName1);
	vector<Pixel> combined = pixels;
	Header header2;
	header2.GetInfo(fileName2);
	Header header3;
	header3.GetInfo(fileName3);

	for (unsigned int i = 0; i < combined.size(); i++) {
		combined.at(i).blue = header3.pixels.at(i).blue;
		combined.at(i).green = header2.pixels.at(i).green;
	}
	return combined;
}

vector <Pixel> Header::Flip(string fileName) {
	GetInfo(fileName);
	vector<Pixel> flipped;

	for (unsigned int i = pixels.size() - 1; i > 0; i--) {
		unsigned char newBlue = pixels.at(i).blue;
		unsigned char newGreen = pixels.at(i).green;
		unsigned char newRed = pixels.at(i).red;
		Pixel pixel(newRed, newGreen, newBlue);
		flipped.push_back(pixel);
	}
	return flipped;
}

// ---------------------------------------------------- FIX ME ---------------------------------------------------- //
                                                                                                                    
 vector<Pixel> Header::ExtraCredit(string fileName1, string fileName2, string fileName3, string fileName4) {      
	GetInfo(fileName1);                                                                                             
	vector<Pixel> fourImages = pixels;                                                                              
	                                                                                                                
	Header header2;                                                                                                 
	header2.GetInfo(fileName2);                                                                                     
	                                                                                                        
	Header header3;                                                                                                                                                                              
	header3.GetInfo(fileName3);                                                                               
                                                                                                             
	Header header4;                                                                                            
	header4.GetInfo(fileName4);                                                                               
                                                                                                            
	for (unsigned int i = 0; i < header2.pixels.size(); i++) {                                                
		fourImages.push_back(header2.pixels.at(i));                                                           
	}                                                                                                         
	for (unsigned int i = 0; i < header3.pixels.size(); i++) {                                                
		fourImages.push_back(header3.pixels.at(i));                                                           
	}                                                                                                         
	for (unsigned int i = 0; i < header4.pixels.size(); i++) {                                                
		fourImages.push_back(header4.pixels.at(i));                                                           
	}                                                                                                         
		                                                                                                      
	                                                                                                          
	return fourImages;                                                                                        
}                                                                                                             

// ---------------------------------------------------- FIX ME ---------------------------------------------------- //

