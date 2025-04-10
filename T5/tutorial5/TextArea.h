#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "RGB.h"

using namespace std;

class TextArea {
		
	public:
		// Constructors
		TextArea(int x, int y, int width, int height, string id, string label, RGB& fill, RGB& border);
		TextArea(int x, int y, int width, int height, const string id, const string label);
		TextArea(Rectangle rect, string id, string label, CuColour fill, CuColour border);	
		TextArea(Rectangle rect, const string id, const string label);
		// Setters
		void setPosition(int x, int y);
		void setX(int x);
		void setY(int y);
		void setSize(int width, int height);
		void setWidth(int width);
		void setHeight(int height);
		void setDimensions(int x, int y, int width, int height);
		void setID(string id);
		void setLabel(string label);
		void setText(string label);
		void setFill(RGB& fill);
		void setBorder(RGB& border);


		// Getters
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		Rectangle getDimensions();
		string getText();
		string getID();
		string getLabel();
	

		// Other Methods
		bool equals(string id);
		bool overlaps(TextArea& TextArea);
		void draw(Display *display, Window& win, GC& gc, int parentX, int parentY);	
		void print();
	
	private:
		Rectangle dimensions;
		string text;
		string id;
		RGB fill;
		RGB border;
	
};
#endif