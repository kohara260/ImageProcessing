#include "Header.h"

int main() {
	int count = 0;
	Header headerObj;
	vector<Pixel> multipliedPixels = headerObj.Multiply("input/layer1.tga", "input/pattern1.tga");
	headerObj.WriteInfo("input/layer1.tga", "output/part1.tga", multipliedPixels);
	if (headerObj.Compare(headerObj, "output/part1.tga", "examples/EXAMPLE_part1.tga") == true) {
		cout << "Test #1 ...... Passed!" << endl;
		count++;
	}
	Header headerObj2;
	vector<Pixel> subtractedPixels = headerObj2.Subtract("input/layer2.tga", "input/car.tga");
	headerObj2.WriteInfo("input/layer2.tga", "output/part2.tga", subtractedPixels);
	if (headerObj2.Compare(headerObj2, "output/part2.tga", "examples/EXAMPLE_part2.tga") == true) {
		cout << "Test #2 ...... Passed!" << endl;
		count++;
	}
	Header headerObj3;
	vector<Pixel> tempPixels = headerObj3.Multiply("input/layer1.tga", "input/pattern2.tga");
	vector<Pixel> screenedPixels = headerObj3.Screen(tempPixels, "input/text.tga");
	headerObj3.WriteInfo("input/layer1.tga", "output/part3.tga", screenedPixels);
	if (headerObj3.Compare(headerObj3, "output/part3.tga", "examples/EXAMPLE_part3.tga") == true) {
		cout << "Test #3 ...... Passed!" << endl;
		count++;
	}
	Header headerObj4;
	vector<Pixel> _tempPixels = headerObj4.Multiply("input/layer2.tga", "input/circles.tga");
	vector<Pixel> _subtractedPixels = headerObj2.Subtract(_tempPixels, "input/pattern2.tga");
	headerObj4.WriteInfo("input/layer2.tga", "output/part4.tga", _subtractedPixels);
	if (headerObj4.Compare(headerObj4, "output/part4.tga", "examples/EXAMPLE_part4.tga") == true) {
		cout << "Test #4 ...... Passed!" << endl;
		count++;
	}
	Header headerObj5;
	vector<Pixel> overlayedPixels = headerObj5.Overlay("input/layer1.tga", "input/pattern1.tga");
	headerObj5.WriteInfo("input/layer1.tga", "output/part5.tga", overlayedPixels);
	if (headerObj5.Compare(headerObj5, "output/part5.tga", "examples/EXAMPLE_part5.tga") == true) {
		cout << "Test #5 ...... Passed!" << endl;
		count++;
	}
	Header headerObj6;
	vector<Pixel> addedPixels = headerObj6.Add("input/car.tga", 200);
	headerObj6.WriteInfo("input/car.tga", "output/part6.tga", addedPixels);
	if (headerObj6.Compare(headerObj6, "output/part6.tga", "examples/EXAMPLE_part6.tga") == true) {
		cout << "Test #6 ...... Passed!" << endl;
		count++;
	}
	Header headerObj7;
	vector<Pixel> scaledPixels = headerObj7.Scale("input/car.tga", 4, 0);
	headerObj7.WriteInfo("input/car.tga", "output/part7.tga", scaledPixels);
	if (headerObj7.Compare(headerObj7, "output/part7.tga", "examples/EXAMPLE_part7.tga") == true) {
		cout << "Test #7 ...... Passed!" << endl;
		count++;
	}
	Header headerObj8r;
	vector<Pixel> redChannel = headerObj8r.RedChannel("input/car.tga");
	headerObj8r.WriteInfo("input/car.tga", "output/part8_r.tga", redChannel);
	if (headerObj8r.Compare(headerObj8r, "output/part8_r.tga", "examples/EXAMPLE_part8_r.tga") == true) {
		cout << "Test #8r ...... Passed!" << endl;
	}
	Header headerObj8g;
	vector<Pixel> greenChannel = headerObj8g.GreenChannel("input/car.tga");
	headerObj8g.WriteInfo("input/car.tga", "output/part8_g.tga", greenChannel);
	if (headerObj8g.Compare(headerObj8g, "output/part8_g.tga", "examples/EXAMPLE_part8_g.tga") == true) {
		cout << "Test #8g ...... Passed!" << endl;
	}
	Header headerObj8b;
	vector<Pixel> blueChannel = headerObj7.BlueChannel("input/car.tga");
	headerObj8b.WriteInfo("input/car.tga", "output/part8_b.tga", blueChannel);
	if (headerObj8b.Compare(headerObj8b, "output/part8_b.tga", "examples/EXAMPLE_part8_b.tga") == true) {
		cout << "Test #8b ...... Passed!" << endl;
		count++;
	}
	Header headerObj9;
	vector<Pixel> combined = headerObj9.Combine("input/layer_red.tga", "input/layer_green.tga", "input/layer_blue.tga");
	headerObj9.WriteInfo("input/layer_red.tga", "output/part9.tga", combined);
	if (headerObj9.Compare(headerObj9, "output/part9.tga", "examples/EXAMPLE_part9.tga") == true) {
		cout << "Test #9 ...... Passed!" << endl;
		count++;
	}
	Header headerObj10;
	vector<Pixel> flipped = headerObj10.Flip("input/text2.tga");
	headerObj10.WriteInfo("input/text2.tga", "output/part10.tga", flipped);
	if (headerObj10.Compare(headerObj10, "output/part10.tga", "examples/EXAMPLE_part10.tga") == true) {
		cout << "Test #10 ...... Passed!" << endl;
		count++;
	}
	Header extraCredit;
	vector<Pixel> ec = extraCredit.ExtraCredit("input/text.tga", "input/pattern1.tga", "input/car.tga", "input/circles.tga");
	extraCredit.WriteInfo("input/text.tga", "output/extraCred.tga", ec, 1024, 1024);


	//cout << "Test results: " << count << " / 10" << endl;

	return 0;
}