#include "Image.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

Image::Image(ifstream& file)
{
	//Header file reading:
	file.read(&idLength, sizeof(idLength));
	file.read(&colorMapType, sizeof(colorMapType));
	file.read(&dataTypeCode, sizeof(dataTypeCode));
	file.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	file.read((char*)&colorMapLength, sizeof(colorMapLength));
	file.read(&colorMapDepth, sizeof(colorMapDepth));
	file.read((char*)&xOrigin, sizeof(xOrigin));
	file.read((char*)&yOrigin, sizeof(yOrigin));
	file.read((char*)&width, sizeof(width));
	file.read((char*)&height, sizeof(height));
	file.read(&bitsPerPixel, sizeof(bitsPerPixel));
	file.read(&imageDescriptor, sizeof(imageDescriptor));

	//Pixel info reading:
	pixels = new Pixel[width * height];
	for (int i = 0; i < (width * height); i++) {
		file.read((char*)&pixels[i].blue, sizeof(pixels[i].blue));
		file.read((char*)&pixels[i].green, sizeof(pixels[i].green));
		file.read((char*)&pixels[i].red, sizeof(pixels[i].red));
	}
}

Image::Image(const Image& A)
{
	this->idLength = A.idLength;
	this->colorMapType = A.colorMapType;
	this->dataTypeCode = A.dataTypeCode;
	this->colorMapOrigin = A.colorMapOrigin;
	this->colorMapLength = A.colorMapLength;
	this->colorMapDepth = A.colorMapDepth;
	this->xOrigin = A.xOrigin;
	this->yOrigin = A.yOrigin;
	this->width = A.width;
	this->height = A.height;
	this->bitsPerPixel = A.bitsPerPixel;
	this->imageDescriptor = A.imageDescriptor;

	pixels = new Pixel[width * height];

	for (int i = 0; i < (width * height); i++)
	{
		this->pixels[i].blue = A.pixels[i].blue;
		this->pixels[i].green = A.pixels[i].green;
		this->pixels[i].red = A.pixels[i].red;
	}
}

Image::~Image()
{
	delete[] pixels;
}

Image& Image::operator=(const Image& A)
{
	this->idLength = A.idLength;
	this->colorMapType = A.colorMapType;
	this->dataTypeCode = A.dataTypeCode;
	this->colorMapOrigin = A.colorMapOrigin;
	this->colorMapLength = A.colorMapLength;
	this->colorMapDepth = A.colorMapDepth;
	this->xOrigin = A.xOrigin;
	this->yOrigin = A.yOrigin;
	this->width = A.width;
	this->height = A.height;
	this->bitsPerPixel = A.bitsPerPixel;
	this->imageDescriptor = A.imageDescriptor;

	delete[] this->pixels;
	pixels = new Pixel[width * height];

	for (int i = 0; i < (width * height); i++)
	{
		this->pixels[i].blue = A.pixels[i].blue;
		this->pixels[i].green = A.pixels[i].green;
		this->pixels[i].red = A.pixels[i].red;
	}

	return *this;
}

bool Image::operator==(const Image& A)
{
	if (idLength != A.idLength) {
		cout << "idLengths are NOT equal!" << endl;
		cout << "Output: " << idLength << endl;
		cout << "Actual: " << A.idLength << endl;
		return false;
	}
	if (colorMapType != A.colorMapType) {
		cout << "colorMapTypes are NOT equal!" << endl;
		cout << "Output: " << colorMapType << endl;
		cout << "Actual: " << A.colorMapType << endl;
		return false;
	}
	if (dataTypeCode != A.dataTypeCode) {
		cout << "dataTypeCodes are NOT equal!" << endl;
		cout << "Output: " << dataTypeCode << endl;
		cout << "Actual: " << A.dataTypeCode << endl;
		return false;
	}
	if (colorMapOrigin != A.colorMapOrigin) {
		cout << "colorMapOrigins are NOT equal!" << endl;
		cout << "Output: " << colorMapOrigin << endl;
		cout << "Actual: " << A.colorMapOrigin << endl;
		return false;
	}
	if (colorMapOrigin != A.colorMapOrigin) {
		cout << "colorMapOrigins are NOT equal!" << endl;
		cout << "Output: " << colorMapOrigin << endl;
		cout << "Actual: " << A.colorMapOrigin << endl;
		return false;
	}
	if (colorMapLength != A.colorMapLength) {
		cout << "colorMapLengths are NOT equal!" << endl;
		cout << "Output: " << colorMapLength << endl;
		cout << "Actual: " << A.colorMapLength << endl;
		return false;
	}
	if (colorMapDepth != A.colorMapDepth) {
		cout << "colorMapDepths are NOT equal!" << endl;
		cout << "Output: " << colorMapDepth << endl;
		cout << "Actual: " << A.colorMapDepth << endl;
		return false;
	}
	if (xOrigin != A.xOrigin) {
		cout << "xOrigins are NOT equal!" << endl;
		cout << "Output: " << xOrigin << endl;
		cout << "Actual: " << A.xOrigin << endl;
		return false;
	}
	if (yOrigin != A.yOrigin) {
		cout << "yOrigins are NOT equal!" << endl;
		cout << "Output: " << yOrigin << endl;
		cout << "Actual: " << A.yOrigin << endl;
		return false;
	}
	if (width != A.width) {
		cout << "widths are NOT equal!" << endl;
		cout << "Output: " << width << endl;
		cout << "Actual: " << A.width << endl;
		return false;
	}
	if (height != A.height) {
		cout << "height are NOT equal!" << endl;
		cout << "Output: " << height << endl;
		cout << "Actual: " << A.height << endl;
		return false;
	}
	if (bitsPerPixel != A.bitsPerPixel) {
		cout << "bitsPerPixel are NOT equal!" << endl;
		cout << "Output: " << bitsPerPixel << endl;
		cout << "Actual: " << A.bitsPerPixel << endl;
		return false;
	}
	if (imageDescriptor != A.imageDescriptor) {
		cout << "imageDescriptors are NOT equal!" << endl;
		cout << "Output: " << imageDescriptor << endl;
		cout << "Actual: " << A.imageDescriptor << endl;
		return false;
	}

	for (int i = 0; i < (width * height); i++) {
		if (pixels[i].blue != A.pixels[i].blue) {
			cout << "pixels[" << i << "].blue  are NOT equal!" << endl;
			cout << "Output: " << (int)pixels[i].blue << endl;
			cout << "Actual: " << (int)A.pixels[i].blue << endl;
			return false;
		}
		if (pixels[i].green != A.pixels[i].green) {
			cout << "pixels[" << i << "].green  are NOT equal!" << endl;
			cout << "Output: " << (int)pixels[i].green << endl;
			cout << "Actual: " << (int)A.pixels[i].green << endl;
			return false;
		}
		if (pixels[i].red != A.pixels[i].red) {
			cout << "pixels[" << i << "].red are NOT equal!" << endl;
			cout << "Output: " << (int)pixels[i].red << endl;
			cout << "Actual: " << (int)A.pixels[i].red << endl;
			return false;
		}
	}

	return true;
}

short Image::GetWidth() const
{
	return width;
}

short Image::GetHeight() const
{
	return height;
}

void Image::ScaleUp()
{
	height = height * 2;
	width = width * 2;
	delete[] pixels;

	pixels = new Pixel[width * height];
	for (int i = 0; i < width * height; i++) {
		pixels[i].blue = pixels[i].green = pixels[i].red = 0;
	}
}

void Image::WriteFile(ofstream& file) const
{
	//Header file writing:
	file.write(&idLength, sizeof(idLength));
	file.write(&colorMapType, sizeof(colorMapType));
	file.write(&dataTypeCode, sizeof(dataTypeCode));
	file.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	file.write((char*)&colorMapLength, sizeof(colorMapLength));
	file.write(&colorMapDepth, sizeof(colorMapDepth));
	file.write((char*)&xOrigin, sizeof(xOrigin));
	file.write((char*)&yOrigin, sizeof(yOrigin));
	file.write((char*)&width, sizeof(width));
	file.write((char*)&height, sizeof(height));
	file.write(&bitsPerPixel, sizeof(bitsPerPixel));
	file.write(&imageDescriptor, sizeof(imageDescriptor));

	//Pixel info writing:
	for (int i = 0; i < (width * height); i++) {
		file.write((char*)&pixels[i].blue, sizeof(pixels[i].blue));
		file.write((char*)&pixels[i].green, sizeof(pixels[i].green));
		file.write((char*)&pixels[i].red, sizeof(pixels[i].red));
	}
}

void Image::WriteGreen(ofstream& file)
{
	//Header file writing:
	file.write(&idLength, sizeof(idLength));
	file.write(&colorMapType, sizeof(colorMapType));
	file.write(&dataTypeCode, sizeof(dataTypeCode));
	file.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	file.write((char*)&colorMapLength, sizeof(colorMapLength));
	file.write(&colorMapDepth, sizeof(colorMapDepth));
	file.write((char*)&xOrigin, sizeof(xOrigin));
	file.write((char*)&yOrigin, sizeof(yOrigin));
	file.write((char*)&width, sizeof(width));
	file.write((char*)&height, sizeof(height));
	file.write(&bitsPerPixel, sizeof(bitsPerPixel));
	file.write(&imageDescriptor, sizeof(imageDescriptor));

	//Pixel info writing:
	for (int i = 0; i < (width * height); i++) {
		int green;
		green = (int)pixels[i].green + 200;
		if (green > 255) {
			green = 255;
		}
		pixels[i].green = (unsigned char)green;
		file.write((char*)&pixels[i].blue, sizeof(pixels[i].blue));
		file.write((char*)&pixels[i].green, sizeof(pixels[i].green));
		file.write((char*)&pixels[i].red, sizeof(pixels[i].red));
	}
}

void Image::WriteRedBlue(ofstream& file)
{
	//Header file writing:
	file.write(&idLength, sizeof(idLength));
	file.write(&colorMapType, sizeof(colorMapType));
	file.write(&dataTypeCode, sizeof(dataTypeCode));
	file.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	file.write((char*)&colorMapLength, sizeof(colorMapLength));
	file.write(&colorMapDepth, sizeof(colorMapDepth));
	file.write((char*)&xOrigin, sizeof(xOrigin));
	file.write((char*)&yOrigin, sizeof(yOrigin));
	file.write((char*)&width, sizeof(width));
	file.write((char*)&height, sizeof(height));
	file.write(&bitsPerPixel, sizeof(bitsPerPixel));
	file.write(&imageDescriptor, sizeof(imageDescriptor));

	//Pixel info writing:
	for (int i = 0; i < (width * height); i++) {
		float blue = pixels[i].blue, red = pixels[i].red;
		blue *= 0;
		red *= 4;
		red += 0.5f;
		if (red > 255) {
			red = 255;
		}
		pixels[i].blue = (unsigned char)blue;
		pixels[i].red = (unsigned char)red;
		file.write((char*)&pixels[i].blue, sizeof(pixels[i].blue));
		file.write((char*)&pixels[i].green, sizeof(pixels[i].green));
		file.write((char*)&pixels[i].red, sizeof(pixels[i].red));
	}
}

void Image::WriteOnlyB(ofstream& file)
{
	//Header file writing:
	file.write(&idLength, sizeof(idLength));
	file.write(&colorMapType, sizeof(colorMapType));
	file.write(&dataTypeCode, sizeof(dataTypeCode));
	file.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	file.write((char*)&colorMapLength, sizeof(colorMapLength));
	file.write(&colorMapDepth, sizeof(colorMapDepth));
	file.write((char*)&xOrigin, sizeof(xOrigin));
	file.write((char*)&yOrigin, sizeof(yOrigin));
	file.write((char*)&width, sizeof(width));
	file.write((char*)&height, sizeof(height));
	file.write(&bitsPerPixel, sizeof(bitsPerPixel));
	file.write(&imageDescriptor, sizeof(imageDescriptor));

	//Pixel info writing:
	for (int i = 0; i < (width * height); i++) {
		pixels[i].red = pixels[i].blue;
		pixels[i].green = pixels[i].blue;
		file.write((char*)&pixels[i].blue, sizeof(pixels[i].blue));
		file.write((char*)&pixels[i].green, sizeof(pixels[i].green));
		file.write((char*)&pixels[i].red, sizeof(pixels[i].red));
	}
}

void Image::WriteOnlyG(ofstream& file)
{
	//Header file writing:
	file.write(&idLength, sizeof(idLength));
	file.write(&colorMapType, sizeof(colorMapType));
	file.write(&dataTypeCode, sizeof(dataTypeCode));
	file.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	file.write((char*)&colorMapLength, sizeof(colorMapLength));
	file.write(&colorMapDepth, sizeof(colorMapDepth));
	file.write((char*)&xOrigin, sizeof(xOrigin));
	file.write((char*)&yOrigin, sizeof(yOrigin));
	file.write((char*)&width, sizeof(width));
	file.write((char*)&height, sizeof(height));
	file.write(&bitsPerPixel, sizeof(bitsPerPixel));
	file.write(&imageDescriptor, sizeof(imageDescriptor));

	//Pixel info writing:
	for (int i = 0; i < (width * height); i++) {
		pixels[i].red = pixels[i].green;
		pixels[i].blue = pixels[i].green;
		file.write((char*)&pixels[i].blue, sizeof(pixels[i].blue));
		file.write((char*)&pixels[i].green, sizeof(pixels[i].green));
		file.write((char*)&pixels[i].red, sizeof(pixels[i].red));
	}
}

void Image::WriteOnlyR(ofstream& file)
{
	//Header file writing:
	file.write(&idLength, sizeof(idLength));
	file.write(&colorMapType, sizeof(colorMapType));
	file.write(&dataTypeCode, sizeof(dataTypeCode));
	file.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	file.write((char*)&colorMapLength, sizeof(colorMapLength));
	file.write(&colorMapDepth, sizeof(colorMapDepth));
	file.write((char*)&xOrigin, sizeof(xOrigin));
	file.write((char*)&yOrigin, sizeof(yOrigin));
	file.write((char*)&width, sizeof(width));
	file.write((char*)&height, sizeof(height));
	file.write(&bitsPerPixel, sizeof(bitsPerPixel));
	file.write(&imageDescriptor, sizeof(imageDescriptor));

	//Pixel info writing:
	for (int i = 0; i < (width * height); i++) {
		pixels[i].blue = pixels[i].red;
		pixels[i].green = pixels[i].red;
		file.write((char*)&pixels[i].blue, sizeof(pixels[i].blue));
		file.write((char*)&pixels[i].green, sizeof(pixels[i].green));
		file.write((char*)&pixels[i].red, sizeof(pixels[i].red));
	}
}

void Multiply(const Image& A, const Image& B, Image& C)
{
	float red = 0, blue = 0, green = 0;

	for (int i = 0; i < (A.GetWidth() * A.GetHeight()); i++) {
		blue = (((float)A.pixels[i].blue / 255) * ((float)B.pixels[i].blue / 255)) * (float)255;
		blue += 0.5f;
		C.pixels[i].blue = (unsigned char)blue;

		green = (((float)A.pixels[i].green / 255) * ((float)B.pixels[i].green / 255)) * (float)255;
		green += 0.5f;
		C.pixels[i].green = (unsigned char)green;

		red = (((float)A.pixels[i].red / 255) * ((float)B.pixels[i].red / 255)) * (float)255;
		red += 0.5f;
		C.pixels[i].red = (unsigned char)red;
	}
}

void Screen(const Image& A, const Image& B, Image& C)
{
	float red = 0, blue = 0, green = 0;

	for (int i = 0; i < (A.GetWidth() * A.GetHeight()); i++) {
		blue = 1 - ((1 - ((float)A.pixels[i].blue / 255)) * (1 - ((float)B.pixels[i].blue / 255)));
		blue *= 255;
		blue += 0.5f;
		C.pixels[i].blue = (unsigned char)blue;

		green = 1 - ((1 - ((float)A.pixels[i].green / 255)) * (1 - ((float)B.pixels[i].green / 255)));
		green *= 255;
		green += 0.5f;
		C.pixels[i].green = (unsigned char)green;

		red = 1 - ((1 - ((float)A.pixels[i].red / 255)) * (1 - ((float)B.pixels[i].red / 255)));
		red *= 255;
		red += 0.5f;
		C.pixels[i].red = (unsigned char)red;
	}
}

void Subtract(const Image& A, const Image& B, Image& C) {
	int red = 0, blue = 0, green = 0;

	for (int i = 0; i < (A.GetWidth() * A.GetHeight()); i++) {
		blue = (int)B.pixels[i].blue - (int)A.pixels[i].blue;
		if (blue < 0) {
			blue = 0;
		}
		C.pixels[i].blue = (unsigned char)blue;

		green = (int)B.pixels[i].green - (int)A.pixels[i].green;
		if (green < 0) {
			green = 0;
		}
		C.pixels[i].green = (unsigned char)green;

		red = (int)B.pixels[i].red - (int)A.pixels[i].red;
		if (red < 0) {
			red = 0;
		}
		C.pixels[i].red = (unsigned char)red;
	}
}

void Overlay(const Image& A, const Image& B, Image& C)
{
	float red = 0, blue = 0, green = 0;

	for (int i = 0; i < (A.GetWidth() * A.GetHeight()); i++) {
		if (((float)B.pixels[i].blue / 255) > 0.5f) { //Use the screen method.
			blue = 1 - (2 * ((1 - ((float)A.pixels[i].blue / 255)) * (1 - ((float)B.pixels[i].blue / 255))));
			blue *= 255;
			blue += 0.5f;
			C.pixels[i].blue = (unsigned char)blue;

			green = 1 - (2 * ((1 - ((float)A.pixels[i].green / 255)) * (1 - ((float)B.pixels[i].green / 255))));
			green *= 255;
			green += 0.5f;
			C.pixels[i].green = (unsigned char)green;

			red = 1 - (2 * ((1 - ((float)A.pixels[i].red / 255)) * (1 - ((float)B.pixels[i].red / 255))));
			red *= 255;
			red += 0.5f;
			C.pixels[i].red = (unsigned char)red;
		}
		else if (((float)B.pixels[i].blue / 255) <= 0.5f) { // Use the multiply method.
			blue = 2 * ((((float)A.pixels[i].blue / 255) * ((float)B.pixels[i].blue / 255)) * (float)255);
			blue += 0.5f;
			if (blue > 255) {
				blue = 255;
			}
			C.pixels[i].blue = (unsigned char)blue;

			green = 2 * ((((float)A.pixels[i].green / 255) * ((float)B.pixels[i].green / 255)) * (float)255);
			green += 0.5f;
			if (green > 255) {
				green = 255;
			}
			C.pixels[i].green = (unsigned char)green;

			red = 2 * ((((float)A.pixels[i].red / 255) * ((float)B.pixels[i].red / 255)) * (float)255);
			red += 0.5f;
			if (red > 255) {
				red = 255;
			}
			C.pixels[i].red = (unsigned char)red;
		}
	}
}

void Combine(const Image& A, const Image& B, const Image& C, Image& D)
{
	for (int i = 0; i < (A.GetWidth() * A.GetHeight()); i++) {
		D.pixels[i].blue = A.pixels[i].blue;
		D.pixels[i].green = B.pixels[i].green;
		D.pixels[i].red = C.pixels[i].red;
	}
}

void Rotate(const Image& A, Image& B)
{
	int j = 0;
	for (int i = (A.GetWidth() * A.GetHeight()) - 1; i >= 0; i--) {
		B.pixels[j].blue = A.pixels[i].blue;
		B.pixels[j].green = A.pixels[i].green;
		B.pixels[j].red = A.pixels[i].red;
		j++;
	}
}

void Extracredit(const Image& A, const Image& B, const Image& C, const Image& D, Image& E)
{
	int imA = 0, imB = 0, imC = 0, imD = 0, totPixels = 0;
	for (int i = 0; i < A.GetHeight() * 2; i++) {
		if (i < A.GetHeight()) {
			for (int j = 0; j < A.GetWidth() * 2; j++) {
				if (j < A.GetWidth()) {
					E.pixels[totPixels].blue = A.pixels[imA].blue;
					E.pixels[totPixels].green = A.pixels[imA].green;
					E.pixels[totPixels].red = A.pixels[imA].red;
					totPixels++;
					imA++;
				}
				else if (j >= A.GetWidth()) {
					E.pixels[totPixels].blue = B.pixels[imB].blue;
					E.pixels[totPixels].green = B.pixels[imB].green;
					E.pixels[totPixels].red = B.pixels[imB].red;
					totPixels++;
					imB++;
				}
			}
		}
		else if (i >= A.GetHeight()) {
			for (int j = 0; j < A.GetWidth() * 2; j++) {
				if (j < A.GetWidth()) {
					E.pixels[totPixels].blue = C.pixels[imC].blue;
					E.pixels[totPixels].green = C.pixels[imC].green;
					E.pixels[totPixels].red = C.pixels[imC].red;
					totPixels++;
					imC++;
				}
				else if (j >= A.GetWidth()) {
					E.pixels[totPixels].blue = D.pixels[imD].blue;
					E.pixels[totPixels].green = D.pixels[imD].green;
					E.pixels[totPixels].red = D.pixels[imD].red;
					totPixels++;
					imD++;
				}
			}
		}
	}
}