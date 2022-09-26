#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <fstream>
#include <vector>
using namespace std;


class Image
{
private:
	//Header information
	char idLength, colorMapType, dataTypeCode, colorMapDepth, bitsPerPixel, imageDescriptor;
	short colorMapOrigin, colorMapLength, xOrigin, yOrigin, width, height;

	//struct for a pixel
	struct Pixel
	{
		//In a .TGA file, the pixels color values are stored in reverse order (BGR not RGB).
		unsigned char blue, green, red;
	};

public:
	//Functions
	Pixel* pixels;
	Image(ifstream& file);
	Image(const Image& A);
	~Image();
	Image& operator=(const Image& A);
	bool operator==(const Image& A);
	short GetWidth() const;
	short GetHeight() const;
	void ScaleUp();
	void WriteFile(ofstream& file) const;
	void WriteGreen(ofstream& file);
	void WriteRedBlue(ofstream& file);
	void WriteOnlyR(ofstream& file);
	void WriteOnlyG(ofstream& file);
	void WriteOnlyB(ofstream& file);
};

//void ReadFile(ifstream& file, vector<Image>& test);
void Multiply(const Image& A, const Image& B, Image& C);
void Screen(const Image& A, const Image& B, Image& C);
void Subtract(const Image& A, const Image& B, Image& C);
void Overlay(const Image& A, const Image& B, Image& C);
void Combine(const Image& A, const Image& B, const Image& C, Image& D);
void Rotate(const Image& A, Image& B);
void Extracredit(const Image& A, const Image& B, const Image& C, const Image& D, Image& E);

#endif

