#include <string>
#include <fstream>
#include <iostream>
#include "Image.h"
#include <vector>
using namespace std;

int main() {
	vector<Image> openedImages;
	ifstream file1, file2, file4, exFile;
	ofstream file3;

	/*----------Part 1----------*/
	file1.open("input/layer1.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	file2.open("input/pattern1.tga", ios_base::binary);
	if (file2.is_open()) {
		Image b(file2);
		openedImages.push_back(b);
	}
	file2.close();

	Image part1(openedImages[0]);
	Multiply(openedImages[0], openedImages[1], part1);
	file3.open("output/part1.tga", ios_base::binary);
	if (file3.is_open()) {
		part1.WriteFile(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part1.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 1: ";
	if (part1 == openedImages[2]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 2----------*/
	file1.open("input/layer2.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	file2.open("input/car.tga", ios_base::binary);
	if (file2.is_open()) {
		Image b(file2);
		openedImages.push_back(b);
	}
	file2.close();

	Image part2(openedImages[0]);
	Subtract(openedImages[0], openedImages[1], part2);
	file3.open("output/part2.tga", ios_base::binary);
	if (file3.is_open()) {
		part2.WriteFile(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part2.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 2: ";
	if (part2 == openedImages[2]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 3----------*/
	file1.open("input/layer1.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	file2.open("input/pattern2.tga", ios_base::binary);
	if (file2.is_open()) {
		Image b(file2);
		openedImages.push_back(b);
	}
	file2.close();

	file4.open("input/text.tga", ios_base::binary);
	if (file4.is_open()) {
		Image c(file4);
		openedImages.push_back(c);
	}
	file4.close();

	Image part3_mult(openedImages[0]), part3_screen(openedImages[0]);
	Multiply(openedImages[0], openedImages[1], part3_mult);
	Screen(part3_mult, openedImages[2], part3_screen);
	file3.open("output/part3.tga", ios_base::binary);
	if (file3.is_open()) {
		part3_screen.WriteFile(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part3.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 3: ";
	if (part3_screen == openedImages[3]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 4----------*/
	file1.open("input/layer2.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	file2.open("input/circles.tga", ios_base::binary);
	if (file2.is_open()) {
		Image b(file2);
		openedImages.push_back(b);
	}
	file2.close();

	file4.open("input/pattern2.tga", ios_base::binary);
	if (file4.is_open()) {
		Image c(file4);
		openedImages.push_back(c);
	}
	file4.close();

	Image part4_mult(openedImages[0]), part4_sub(openedImages[0]);
	Multiply(openedImages[0], openedImages[1], part4_mult);
	Subtract(openedImages[2], part4_mult, part4_sub);
	file3.open("output/part4.tga", ios_base::binary);
	if (file3.is_open()) {
		part4_sub.WriteFile(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part4.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 4: ";
	if (part4_sub == openedImages[3]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 5----------*/
	file1.open("input/layer1.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	file2.open("input/pattern1.tga", ios_base::binary);
	if (file2.is_open()) {
		Image b(file2);
		openedImages.push_back(b);
	}
	file2.close();

	Image part5(openedImages[0]);
	Overlay(openedImages[0], openedImages[1], part5);
	file3.open("output/part5.tga", ios_base::binary);
	if (file3.is_open()) {
		part5.WriteFile(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part5.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 5: ";
	if (part5 == openedImages[2]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 6----------*/
	file1.open("input/car.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	file3.open("output/part6.tga", ios_base::binary);
	if (file3.is_open()) {
		openedImages[0].WriteGreen(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part6.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 6: ";
	if (openedImages[0] == openedImages[1]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 7----------*/
	file1.open("input/car.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	Image part7(openedImages[0]);
	file3.open("output/part7.tga", ios_base::binary);
	if (file3.is_open()) {
		part7.WriteRedBlue(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part7.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 7: ";
	if (part7 == openedImages[1]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 8----------*/
	ofstream file5, file6;
	file1.open("input/car.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	Image part8_r(openedImages[0]), part8_g(openedImages[0]), part8_b(openedImages[0]);
	file3.open("output/part8_g.tga", ios_base::binary);
	if (file3.is_open()) {
		part8_g.WriteOnlyG(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part8_g.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex1(exFile);
		openedImages.push_back(ex1);
	}
	exFile.close();

	cout << "Test 8-Green: ";
	if (part8_g == openedImages[1]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}

	file5.open("output/part8_r.tga", ios_base::binary);
	if (file5.is_open()) {
		part8_r.WriteOnlyR(file5);
	}
	file5.close();

	exFile.open("examples/EXAMPLE_part8_r.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex2(exFile);
		openedImages.push_back(ex2);
	}
	exFile.close();

	cout << "Test 8-Red: ";
	if (part8_r == openedImages[2]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}

	file6.open("output/part8_b.tga", ios_base::binary);
	if (file6.is_open()) {
		part8_b.WriteOnlyB(file6);
	}
	file6.close();

	exFile.open("examples/EXAMPLE_part8_b.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex3(exFile);
		openedImages.push_back(ex3);
	}
	exFile.close();

	cout << "Test 8-Blue: ";
	if (part8_b == openedImages[3]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 9----------*/
	file1.open("input/layer_blue.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	file2.open("input/layer_green.tga", ios_base::binary);
	if (file2.is_open()) {
		Image b(file2);
		openedImages.push_back(b);
	}
	file2.close();

	file4.open("input/layer_red.tga", ios_base::binary);
	if (file4.is_open()) {
		Image c(file4);
		openedImages.push_back(c);
	}
	file4.close();

	Image part9(openedImages[0]);
	Combine(openedImages[0], openedImages[1], openedImages[2], part9);
	file3.open("output/part9.tga", ios_base::binary);
	if (file3.is_open()) {
		part9.WriteFile(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part9.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 9: ";
	if (part9 == openedImages[3]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Part 10----------*/
	file1.open("input/text2.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	Image part10(openedImages[0]);
	Rotate(openedImages[0], part10);
	file3.open("output/part10.tga", ios_base::binary);
	if (file3.is_open()) {
		part10.WriteFile(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_part10.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Test 10: ";
	if (part10 == openedImages[1]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();

	/*----------Extracredit----------*/
	ifstream file;
	file1.open("input/text.tga", ios_base::binary);
	if (file1.is_open()) {
		Image a(file1);
		openedImages.push_back(a);
	}
	file1.close();

	file2.open("input/pattern1.tga", ios_base::binary);
	if (file2.is_open()) {
		Image b(file2);
		openedImages.push_back(b);
	}
	else {
		cout << "Cannot open file!" << endl;
	}
	file2.close();

	file4.open("input/car.tga", ios_base::binary);
	if (file4.is_open()) {
		Image c(file4);
		openedImages.push_back(c);
	}
	else {
		cout << "Cannot open file!" << endl;
	}
	file1.close();

	file.open("input/circles.tga", ios_base::binary);
	if (file.is_open()) {
		Image d(file);
		openedImages.push_back(d);
	}
	file.close();

	Image extra(openedImages[0]);
	extra.ScaleUp();
	Extracredit(openedImages[0], openedImages[1], openedImages[2], openedImages[3], extra);
	file3.open("output/extracredit.tga", ios_base::binary);
	if (file3.is_open()) {
		extra.WriteFile(file3);
	}
	file3.close();

	exFile.open("examples/EXAMPLE_extracredit.tga", ios_base::binary);
	if (exFile.is_open()) {
		Image ex(exFile);
		openedImages.push_back(ex);
	}
	exFile.close();

	cout << "Extracredit Test: ";
	if (extra == openedImages[4]) {
		cout << "Passed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}
	openedImages.clear();


	return 0;
}