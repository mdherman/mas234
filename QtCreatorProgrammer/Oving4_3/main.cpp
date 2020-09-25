#include <iostream>
#include <QApplication>
#include <QtWidgets/QLabel>
#include <string>

enum possibility{
    noProblem,
    duckTape,
    oil};


bool askUserForYesNoInput(){

    std::cout << "(Yes/No?) " << std::endl;

    std::string input;
    std::cin >> input;

    if(input == "y"){
    return true;
    }

    else if (input=="n"){
    return false;
    }

    else {
    std::cout << "Please answer with [y] or [n], then press enter." << std::endl;
    return askUserForYesNoInput();
    }

}

possibility engineeringFlowchart(){

    std::cout << "WELCOME TO ENGINEERING FLOWCHART." << std::endl;
    std::cout << "\nDoes it move?" << std::endl;

    bool a = askUserForYesNoInput();

    std::cout << "Should it?" << std::endl;
    bool b = askUserForYesNoInput();

    if ((a == true && b == true) || (a==false && b==false)){
        return noProblem;
    }
    else if (a==true && b ==false){
        return duckTape;
    }
    else {
        return oil;
    }
}

/*QString imageSource(){

    possibility a = engineeringFlowchart();
    if (a==noProblem){
        std::cout << "No problem." << std::endl;
        return "/home/mherman/C_Programs/Photos/noProblem.jpeg";
    }
    else if (a==duckTape){
        std::cout << "Use duck tape." << std::endl;
        return "/home/mherman/C_Programs/Photos/duckTape.jpg";
    }
    else{
        std::cout << "Apply some oil." << std::endl;
        return "/home/mherman/C_Programs/Photos/WD40.jpg";
    }

}*/


void imageSource(QString& source){


    possibility a = engineeringFlowchart();
    if (a==noProblem){
        std::cout << "No problem." << std::endl;
        source = "/home/mherman/C_Programs/Photos/noProblem.jpeg";
    }
    else if (a==duckTape){
        std::cout << "Use duck tape." << std::endl;
        source= "/home/mherman/C_Programs/Photos/duckTape.jpg";
    }
    else{
        std::cout << "Apply some oil." << std::endl;
        source= "/home/mherman/C_Programs/Photos/WD40.jpg";
    }

}

int main(int argc, char *argv[]){
    QString text;
    imageSource(text);
    QApplication a(argc, argv);
    QImage image;

    image.load(text);

    QLabel imageLabel;
    imageLabel.setPixmap(QPixmap::fromImage(image));
    imageLabel.show();

    return a.exec();
}

