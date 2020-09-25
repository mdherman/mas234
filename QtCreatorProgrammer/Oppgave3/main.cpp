#include <iostream>
#include <string>
#include <unistd.h>


std::string beverageName;
int beverage = 0;
int price = 0;
int insertedMoney = 0;
int coin = 0;
int coinsAway = 0;
int moneyBack = 0;

int count_1 = 0;
int count_5 = 0;
int count_10 = 0;
int count_20 = 0;


void startup(){


    std::cout << "Hey, what beverage would you like? " << std::endl;
    std::cout << "\nPress 1 for Coke" << std::endl;
    std::cout << "Press 2 for Solo" << std::endl;
    std::cout << "Press 3 for Sprite" << std::endl;
    std::cout << "Press 4 for Pepsi" << std::endl;
    std::cout << "Press 5 for Water\n" << std::endl;

    std::cin >> beverage;


    if (beverage<=5 && beverage>=1){

        if (beverage==1){
            beverageName = "Coke";
            price = 28;
        }
        else if (beverage==2){
            beverageName = "Solo";
            price = 21;
        }
        else if (beverage==3){
            beverageName = "Sprite";
            price = 50;
        }
        else if (beverage==4){
            beverageName = "Pepsi";
            price = 26;
        }
        else if (beverage==5){
            beverageName = "Water";
            price = 15;
        }

        std::cout << "\nYou chose " << beverageName << ". This costs: " << price << "kr" << std::endl;
        std::cout << "\nPlease insert " << price << "kr\n" << std::endl;
        std::cout << "You may insert 1kr, 5kr, 10kr or 20kr.\n" << std::endl;
    }

    else{
        std::cout << "ERROR: SYSTEM CANNOT RECOGNISE INPUT!\n\nPLEASE TRY AGAIN." << std::endl;
        usleep(500000);

        return startup();
    }


}

void addcoin(){
        std::cin >> coin;
        if (coin==1 || coin==5 || coin==5 || coin==10 || coin==20){
            usleep(1000000);

            insertedMoney = insertedMoney + coin;
            std::cout << "\nYou have inserted a total of " << insertedMoney <<"kr.\n" << std::endl;
            coinsAway = price - insertedMoney;
            if(coinsAway==0){
            }
            else if(coinsAway > 0){
                std::cout << "You are " << coinsAway << "kr short. Please enter more coins.\n" << std::endl;
            }
        }
        else {
            std::cout << "\nYou inserted a non-valid coin, please try again\n" << std::endl;
            return addcoin();
        }

    }

void returnMoney(){
    while (moneyBack != 0){
        if (moneyBack >= 20){
            moneyBack = moneyBack - 20;
            count_20 = 1 + count_20;
        }
        else if (moneyBack >= 10){
            moneyBack = moneyBack - 10;
            count_10 = 1 + count_10;
        }
        else if (moneyBack >= 5){
            moneyBack = moneyBack - 5;
            count_5 = 1 + count_5;
        }
        else if (moneyBack >= 1){
            moneyBack = moneyBack - 1;
            count_1 = 1 + count_1;
        }

    }

}


int main(){

    startup();

    while (insertedMoney <= (price-1)){
        addcoin();
    }

    if (insertedMoney > price){
        moneyBack = insertedMoney - price;

        std::cout << "You have inserted to many coins. " << std::endl;
        std::cout << "Therefore you will have " << moneyBack << "kr returned" << std::endl;

        usleep(500000);


        returnMoney();

        std::cout << "\nHere you go:" << std::endl;

        if(count_20 > 0){
        std::cout << "Number of 20kr coins returned: " << count_20 << std::endl;
        }
        if(count_10 > 0){
        std::cout << "Number of 10kr coins returned: " << count_10 << std::endl;
        }
        if(count_5 > 0){
        std::cout << "Number of 5kr coins returned: " << count_5 << std::endl;
        }
        if(count_1 > 0){
        std::cout << "Number of 1kr coins returned: " << count_1 << std::endl;
        }


    }

    std::cout << "\nYour beverage is on the way, please wait...\n" << std::endl;
    usleep(3000000);
    std::cout << "Thanks for shopping." << std::endl;
    usleep(2500000);
    std::cout << "\n*NO BEVERAGE OCCURS*\n." << std::endl;


}
