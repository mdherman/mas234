#include <iostream>

std::string dit = "Does it work?";
std::string mwi = "Mess with it?";
std::string yi = "YOU IDIOT!";
std::string dymwi = "Did you mess with it?";
std::string hi = "Hide it.";
std::string dak = "Does anyone know?";
std::string ypi = "You poor idiot.";
std::string wygit = "Will you get into trobule?";
std::string cybse = "Can you blame someone else?";
std::string ti = "Trash it.";
std::string np = "No problem :)";

bool DIT;
bool MWI;
bool DYMWI;
bool DAK;
bool WYGIT;
bool CYBSE;
bool NP;



void askUserForYesNoInput(std::string text, bool& nextStep){


    std::cout << text << std:: endl;

    std::string yesNoInput;

    std::cout << "(Yes/No)?" << std::endl;
    std::cin >> yesNoInput;

    if (yesNoInput == "y"){
        nextStep = true;
    }
    else if (yesNoInput == "n"){
        nextStep = false;
    }
    else{
        std::cout << "Answer with [y] or [n], then press enter." << std::endl;
        return askUserForYesNoInput(text, nextStep);
    }

}


int main()
{
 askUserForYesNoInput(dit, DIT);



     if (DIT == true){
     askUserForYesNoInput(mwi, MWI);
     }
     else{
     askUserForYesNoInput(dymwi, DYMWI);
     }

     std::cout << ""<< std::endl;

     if (MWI == false){
         NP = true;
     }
     else if (DYMWI == falsey){

         askUserForYesNoInput(wygit, WYGIT);

         if (WYGIT == false){
             std::cout << ti << std::endl;
             NP = true;
         }
     }
     else{
         std::cout << yi << std::endl;
         askUserForYesNoInput(dak, DAK);
     }



     if (DAK == true || WYGIT == true){
         while (CYBSE != true){
            std::cout << ypi << std::endl;

            askUserForYesNoInput(cybse, CYBSE);
            if (CYBSE == true){
             NP = true;
             }
         }
     }

     else if (DAK == false){
         std::cout << hi << std::endl;
         NP = true;
     }

 std::cout << np << std::endl;




}
