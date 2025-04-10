#include "TextArea.h"

TextArea::TextArea(int x, int y, int width, int height, string id, string label, RGB& fill, RGB& border){
    setDimensions(x, y, width, height);
    setID(id);
    setLabel(label);
    setFill(fill);
    setBorder(border);
}

TextArea::TextArea(int x, int y, int width, int height, const string id, const string label){
    setDimensions(x, y, width, height);
    setID(id);
    setLabel(label);
    this->fill.WHITE();
    this->border.RED();
}

TextArea::TextArea(Rectangle rect, const string id, const string label){
    setDimensions(rect.x, rect.y, rect.width, rect.height);
    setID(id);
    setLabel(label);
    this->fill.WHITE();
    this->border.BLUE();
}

TextArea::TextArea(Rectangle rect, string id, string label, CuColour fill, CuColour border){
    setDimensions(rect.x, rect.y, rect.width, rect.height);
    setLabel(label);
    this->fill.setColour(fill);
    this->border.setColour(border);
}


// Setters

void TextArea::setPosition(int x, int y){
    this->dimensions.x = x;
    this->dimensions.y = y;
}

void TextArea::setX(int x){
    this->dimensions.x = x;
}

void TextArea::setY(int y){
    this->dimensions.y = y;
}

void TextArea::setSize(int width, int height){
    this->dimensions.width = width;
    this->dimensions.height = height;
}

void TextArea::setWidth(int width){
    this->dimensions.width = width;
}

void TextArea::setHeight(int height){
    this->dimensions.height = height;
}

void TextArea::setDimensions(int x, int y, int width, int height){
    setPosition(x, y);
    setSize(width, height);
}

void TextArea::setID(string id){
    this->id = id;
}

void TextArea::setLabel(string label){
    this->text = label;
}

void TextArea::setText(string label){
    this->text = label;
}

void TextArea::setFill(RGB& fill){
    this->fill = fill;
}

void TextArea::setBorder(RGB& border){
    this->border = border;
}

// Getters

int TextArea::getX(){
    return this->dimensions.x;
}

int TextArea::getY(){
    return this->dimensions.y;
}

int TextArea::getWidth(){
    return this->dimensions.width;
}

int TextArea::getHeight(){
    return this->dimensions.height;
}

string TextArea::getLabel(){
    return this->text;
}

string TextArea::getText(){
    return this->text;
}

Rectangle TextArea::getDimensions(){
    return this->dimensions;
}

string TextArea::getID(){
    return this->id;
}

// Other Methods
bool TextArea::equals(string id){
    if(this->id == id){
        return true;
    }else{
        return false;
    }
}

bool TextArea::overlaps(TextArea& TextArea){
    return this->dimensions.overlaps(TextArea.getDimensions());
}

void TextArea::draw(Display *display, Window& win, GC& gc, int parentX, int parentY){
    int x = getX() + parentX;
    int y = getY() + parentY;
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, getWidth(), getHeight());
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, getWidth(), getHeight());
    // const char *str = "Butt\non";
    // get the font structure
    // XFontStruct *font = XLoadQueryFont(display, "fixed");
    // int textWidth = XTextWidth(font, label.c_str(), label.length());
    const char* font_name = "fixed"; // You can specify a different font
    XID font = XLoadFont(display, font_name);
    XFontStruct* font_info = XQueryFont(display, font);
    if (!font_info) {
        XCloseDisplay(display);
        return; // Failed to query font
    }
    XSetFont(display, gc, font);

    int text_width = XTextWidth(font_info, getLabel().c_str(), getLabel().length());
    int length = getLabel().length();

    //make sure it fits in the TextArea
    while (text_width > getWidth() - 10){
        length--;
        text_width = XTextWidth(font_info, getLabel().c_str(), length);
    }

    int offsetX = (getWidth() - text_width)/2;

    int text_height = font_info->ascent + font_info->descent;

    int offsetY = (getHeight() - text_height)/2 + font_info->ascent;

    // Cleanup
    XFreeFontInfo(NULL, font_info, 1);
    // cout<<"Text width: "<<textWidth<<endl;
    cout<<"TextArea width: "<< getWidth() <<endl;
    // XDrawString(display, win, gc, x + 10, y + 20, label.c_str(), label.length());
    XDrawImageString(display, win, gc, x+offsetX, y + offsetY, getLabel().c_str(), length);
    // XDrawString(display, win, gc, x + 10, y + 20, str, 7);
    cout<<"Called draw on TextArea"<<endl;
}

void TextArea::print(){
    cout<<"TextArea id:   " << getID() << endl;
    cout<<"Preferred location: " << getX() << ", " << getY() <<endl;
    cout<<"Size:     "<< getWidth() << ", " << getHeight() <<endl;
    cout<<"Text:   " << getLabel() << endl;
}