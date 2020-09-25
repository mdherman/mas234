#include <iostream>


std::string a;
bool firstStep = false;
bool MWIstep = false;
bool YIstep = false;
bool DYMWIstep = false;
bool YPIstep = false;
bool HIstep = false;
bool WYGITstep = false;
bool CYBSEstep = false;
bool finish = false;


void FirstStep(){
    while(firstStep == false){
     std::cout << "Does it work?" << std::endl;
     std::cin >> a;

    if(a=="y" || a =="Y"){
         std::cout << "Mess with it?" << std::endl;
         std::cin >> a;
         if (a=="y" || a=="Y"){
             MWIstep = true;
         }
         else if(a=="n" || a=="N"){
             finish = true;
         }
         firstStep = true;
         YIstep = true;

    }

     else if(a=="n" || a=="N"){
         std::cout << "Did you mess with it?" << std::endl;
         std::cin >> a;
         if (a=="y" || a=="Y"){
             DYMWIstep = true;
         }
             else if(a=="n" || a=="N"){
             WYGITstep = true;
         }

         firstStep = true;

     }
     else{FirstStep();}

    if (WYGITstep==true){
        std::cout << "Will you get into trouble? ";
        std::cin >> a;

        if(a=="y" || a =="Y"){
             YPIstep = true;
         }
         else if(a=="n" || a=="N"){
             std::cout << "Trash it." << std::endl;
             finish = true;
         }
         else{FirstStep();}

    }
   }
}

void secondStep(){

    if(MWIstep==true || DYMWIstep==true){
        std::cout << "You idiot!!!" << std::endl;
        std::cout << "Does anyone know? ";
        std::cin >> a;
        if (a=="y" || a=="Y"){
            YPIstep = true;
        }
        else if (a == "n" || a == "N") {
            std::cout << "OK, lets hide it!" << std::endl;
            finish = true;
        }
        else{secondStep();}

    }
    MWIstep = false;
    DYMWIstep = false;
}

void YPIstepp(){
    if (YPIstep==true){
        std::cout << "You poor idiot." << std::endl;
        std::cout << "Can you blame someone else? ";
        std::cin >> a;

        if (a=="y" || a=="Y"){
            finish = true;
        }
        else{
            return YPIstepp();
        }
    }
}




void lastStep(){
    if(finish==true){
        std::cout << "No problem mate!" << std::endl;

    }
}



void problemSolvingFlowchart(){
    FirstStep();
    secondStep();
    YPIstepp();
    lastStep();



 }


int main()
{
    problemSolvingFlowchart();
}
