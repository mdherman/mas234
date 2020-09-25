#include <iostream>

const std::string sodaType[] = {"Cola", "Fanta", "Solo", "Pepsi Max", "Vann"};
int priceSoda[] = { 25, 22, 29, 34, 15};
const int acceptedCoins[] = {20, 10, 5, 1};
int count[] = {0, 0, 0, 0};

bool machineRun = 0;
int chosenSoda = 0;
int coinInn;
int totalPaid;

int changeSoda;
int newPrice;
int moneyReturned;

int askUserForYesNoInput(){
    std::string yesNoInput;

    std::cout << "(Yes/No)?" << std::endl;
    std::cin >> yesNoInput;

    if (yesNoInput == "y"){
        return 1;
    }
    else if (yesNoInput == "n"){

        return askUserForYesNoInput();
    }
    else if (yesNoInput == "s"){
        return 10;
        return askUserForYesNoInput();
    }
    else{
        std::cout << "Answer with [y] or [n], then press enter." << std::endl;
        return askUserForYesNoInput();
    }
}

int changePrice(){
    std::cout << "Welcome to the service menu\n\nWhat price would you like to change?" << std::endl;
    for (int i = 0; i <=4 ; ++i){
        std::cout << "Press " << (i+1) << " to change the price for " << sodaType[i] << std::endl;
    }
    std::cin >> changeSoda;
    changeSoda = changeSoda - 1;
    std::cout << "You have chosen to change the price of " << sodaType[changeSoda] << "." << std::endl;
    std::cout << "This costs " << priceSoda[changeSoda] << "kr." << std::endl;
    std::cout << "What will the new price be?" << std::endl;
    std::cin >> newPrice;
    priceSoda[changeSoda] = newPrice;
    std::cout << "The new price for " << sodaType[changeSoda] << " is now " << newPrice << "kr." << std::endl;

    return priceSoda[changeSoda];
}

int main()
{
    std::cout << "Hello, would you like to buy a soda?" << std::endl;
    int x = askUserForYesNoInput();
    if (x == 0){
        return main();

    }
    else if (x == 10){
        changePrice();
        main();

    }

    std::cout << "The following soda options are: " << std::endl;

    for (int i = 0; i <= 4; ++i){
        std::cout << "Press " << (i+1) << " for " << sodaType[i] << " [" << priceSoda[i] << "kr]" << std::endl;
    }
    std::cout << std::endl;
    std::cin >> chosenSoda;

    chosenSoda = chosenSoda - 1;

    if (chosenSoda < 0 || chosenSoda > 4){
        std::cout << "Please press buttons 1-5. Try again..." << std:: endl;
        return main();

    }

    std::cout << "\n\nYou chose " << sodaType[chosenSoda] << std::endl;
    std::cout << "Is this correct?" << std::endl;

    x = askUserForYesNoInput();
    if (x == false){
        return main();
    }

    std::cout << "\nGreat, please insert " << priceSoda[chosenSoda] << "kr in 1, 5, 10 or 20 [kr] coins." << std::endl;

    int priceToPay = priceSoda[chosenSoda];

    while (priceToPay > 0){
        std::cin >> coinInn;
        if (coinInn == acceptedCoins[0] || coinInn == acceptedCoins[1] || coinInn == acceptedCoins[2] || coinInn == acceptedCoins[3]){
            priceToPay = priceToPay - coinInn;
            totalPaid = coinInn + totalPaid;

            std::cout << "Total paid: " << totalPaid << "kr." << std::endl;
            if (totalPaid < priceSoda[chosenSoda]){
                std::cout << "Remaining:  " << (priceSoda[chosenSoda] - totalPaid) << "kr." << std::endl;
            }
            else {
                std::cout << "Thanks!\n" << std::endl;
            }
        }

        else {
            std::cout << "You have insterted an non-valid coin. Please try again." << std::endl;
        }
    }
    if (totalPaid > priceSoda[chosenSoda]){
        moneyReturned = totalPaid - priceSoda[chosenSoda];
        std::cout << "To many coins inserted. You will have " << moneyReturned << "kr returned." << std::endl;
        while (moneyReturned != 0){
            for (int i = 0; i <=3; i++){
                while (moneyReturned >= acceptedCoins[i]){
                    count[i] = count[i] + 1;
                    moneyReturned = moneyReturned - acceptedCoins[i];
                }
            }
        }

        std::cout << "\n*NUMBER OF COINS RETURNED*" << std::endl;
        for (int i = 0; i <= 3; ++i){
            if (count[i] > 0){
                std::cout << acceptedCoins[i] << "kr coins returned: " << count[i] << std::endl;
            }
        }
    }

    std::cout << "\nWehey, here is your soda\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;

    moneyReturned = 0;
    totalPaid = 0;
    for (int i = 0; i <= 3; ++i){
        count[i] = 0;
    }

    return main();

}
