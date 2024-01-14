#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <string>
#include "AbstractButton.h"
#include "QtWidgets/qpushbutton.h"

#include <QWidget>
#include <QPushButton>

class Button : public QPushButton {
private:
    std::string text;
    int x,y, width, height;
    QPushButton *button;
public:
    Button(std::string t, int nx, int ny, int w, int h){
        text = t;
        x = nx;
        y = ny;
        width = w;
        height = h;
    };

    Button(int t, int nx, int ny, int w, int h){
        text = std::to_string(t);
        x = nx;
        y = ny;
        width = w;
        height = h;
    };

    void display(Window*);

};

void Button::display(Window* window){
    QFont font ("Hanson",20,-1,false);
    char ctext[int(text.length())];
    for(int i = 0; i < int(text.length()); i++){ ctext[i] = text[i]; }
    button = new QPushButton(ctext,window);
    button->setGeometry(x,y,width,height);
    button->setFont(font);
}


#endif // BUTTON_H
