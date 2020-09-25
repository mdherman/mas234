#include <iostream>
#include <QtWidgets/QLabel>
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QImage image;

    bool loaded = image.load("/home/mherman/C_Programs/Photos/duckTape.jpg");

    QLabel imageLabel;
    imageLabel.setPixmap(QPixmap::fromImage(image));
    imageLabel.show();

    return a.exec();
}

