//Binary Graphics Version 1.5 Alpha by Osaze Shears\n\n

#include <iostream>
#include <string>
#include <bitset>
#include <windows.h>
#include <time.h>
using namespace std;

void namefunction();
void loopfunction();
void infiniteloopfunction();
void reversefunction();
void colorfunction();
int defcolor(170);
bool grid(false);

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    int useroption;
    char confirmation;
    bool active(true);

    SetConsoleTextAttribute(hConsole,11);
    cout<<"Binary Graphics Version 1.5 Alpha by Osaze Shears\n\n";
    SetConsoleTextAttribute(hConsole,7);

    while (active==true){

        cout<<"Name Function<0>\nLoop Function<1>\nInfinite Loop Function<2>\nReverse Function<3>\nChange Color<4>\nGrid Attribute<5>\nQuit<6>\n";
        cin>>useroption;

        if (useroption==0){
                namefunction();
                cout<<endl;
        }
        else if (useroption==1){
                loopfunction();
                cout<<endl;
        }
        else if (useroption==2){
                SetConsoleTextAttribute(hConsole,12);
                cout<<"Application will run infinitely and will have\n to be manually closed. Are you sure?\n Yes <y> or No <n>.\n";
                SetConsoleTextAttribute(hConsole,7);
                cin>>confirmation;
                if (confirmation=='y'){
                infiniteloopfunction();
                }
                else{
                SetConsoleTextAttribute(hConsole,9);
                cout<<"Operation Canceled...\n";
                SetConsoleTextAttribute(hConsole,7);
                }
                cout<<endl;
        }
        else if (useroption==3){
                bool inuse("true");
                while (inuse==true){
                    cout<<"Run the reverse function?\n Yes <y> or No <n>...\n";
                    cin>>confirmation;
                    if (confirmation=='y'){
                        reversefunction();
                    }
                    else{
                        SetConsoleTextAttribute(hConsole,9);
                        cout<<"Operation Canceled...\n";
                        inuse=false;
                        SetConsoleTextAttribute(hConsole,7);
                    }
                    cout<<endl;
                }
        }
        else if (useroption==4){
            colorfunction();
        }
        else if (useroption==5){
            cout<<"Do you wish to enable the grid attribute?\n Yes <y> or No <n>...\n";
            cin>>confirmation;
            if (confirmation=='y'){
                grid=true;
                SetConsoleTextAttribute(hConsole,9);
                cout<<"Grid has been enabled...\n";
                SetConsoleTextAttribute(hConsole,7);
            }
            else if (confirmation=='n'){
                SetConsoleTextAttribute(hConsole,9);
                grid=false;
                SetConsoleTextAttribute(hConsole,7);
                cout<<"Grid has been disabled...\n";
            }
            else{
                SetConsoleTextAttribute(hConsole,9);
                cout<<"Operation Canceled...\n";
                SetConsoleTextAttribute(hConsole,7);
                }
            cout<<endl;
        }
        else if (useroption==6){
            active=false;
        }
    }
    return 0;
}


void namefunction()
{

    string userinput;
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    bitset<8> mybits;
    string temp;

    cout<<"Enter your name (no spaces) \n";
    cin>>userinput;

    for (size_t i=0; i<userinput.size();++i){
        //cout<<bitset<8>(userinput.c_str()[i])<<endl;
        //cout<<i+1;
        mybits=(userinput.c_str()[i]);
        temp=mybits.to_string<char,char_traits<char>,allocator<char> >();

        if (grid==false){
        for (int ok=0;ok<temp.size();++ok){
            switch (temp[ok]){
                case '0':
                    SetConsoleTextAttribute(hConsole,7);
                    temp.replace(ok,1," ");
                    cout<<temp[ok];
                    break;
                case '1':
                    SetConsoleTextAttribute(hConsole,defcolor);
                    cout<<temp[ok];
                    break;
                default:
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"error";
                    break;
            }
        }
        }
        else if (grid==true){
        for (int ok=0;ok<temp.size();++ok){
            switch (temp[ok]){
                case '0':
                    SetConsoleTextAttribute(hConsole,7);
                    temp.replace(ok,1," ");
                    cout<<temp[ok];
                    break;
                case '1':
                    SetConsoleTextAttribute(hConsole,defcolor);
                    cout<<temp[ok];
                    break;
                default:
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"error";
                    break;
            }
            SetConsoleTextAttribute(hConsole,12);
            cout<<"\|";
        }

        }
    SetConsoleTextAttribute(hConsole,7);
    cout<<endl;
    }

    SetConsoleTextAttribute(hConsole,7);
}

void loopfunction(){

    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    srand(time(0));
    int randNum;
    int stringsize=rand()%20+5;
    string generated;

    for (int i=0;i<stringsize;i++){
        randNum=rand()%96+33;
        //cout<<randNum<<endl;
        char mychar=(char)randNum;
        generated.push_back(mychar);
    }

    SetConsoleTextAttribute(hConsole,12);
    cout<<generated<<endl;
    SetConsoleTextAttribute(hConsole,7);


    bitset<8> mybits;
    string temp;

    for (size_t i=0; i<generated.size();++i){
        //cout<<bitset<8>(generated.c_str()[i])<<endl;
        //cout<<i+1;
        mybits=(generated.c_str()[i]);
        temp=mybits.to_string<char,char_traits<char>,allocator<char> >();

        if (grid==false){
        for (int ok=0;ok<temp.size();++ok){
            switch (temp[ok]){
                case '0':
                    SetConsoleTextAttribute(hConsole,7);
                    temp.replace(ok,1," ");
                    cout<<temp[ok];
                    break;
                case '1':
                    SetConsoleTextAttribute(hConsole,defcolor);
                    cout<<temp[ok];
                    break;
                default:
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"error";
                    break;
            }
        }
        }
    if (grid==true){
         for (int ok=0;ok<temp.size();++ok){
            switch (temp[ok]){
                case '0':
                    SetConsoleTextAttribute(hConsole,7);
                    temp.replace(ok,1," ");
                    cout<<temp[ok];
                    break;
                case '1':
                    SetConsoleTextAttribute(hConsole,defcolor);
                    cout<<temp[ok];
                    break;
                default:
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"error";
                    break;
            }
         SetConsoleTextAttribute(hConsole,12);
        cout<<"\|";
         }
    }
    SetConsoleTextAttribute(hConsole,7);
    cout<<endl;
    }

    SetConsoleTextAttribute(hConsole,7);
}

void infiniteloopfunction()
{
    bool active(true);

    while (active==true){
    loopfunction();
    }


}
void reversefunction()
{
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    string bintocon;

    cout<<"Insert binary to convert...\n";
    cin>>bintocon;
    //cout<<bintocon.size()<<endl;
    if (grid==false){
    for (int ok=0;ok<bintocon.size();++ok){
            switch (bintocon[ok]){
                case '0':
                    SetConsoleTextAttribute(hConsole,7);
                    bintocon.replace(ok,1," ");
                    cout<<bintocon[ok];
                    break;
                case '1':
                    SetConsoleTextAttribute(hConsole,defcolor);
                    cout<<bintocon[ok];
                    break;
                default:
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"error";
                    break;
            }
    }
    }
    else if (grid==true){
    for (int ok=0;ok<bintocon.size();++ok){
            switch (bintocon[ok]){
                case '0':
                    SetConsoleTextAttribute(hConsole,7);
                    bintocon.replace(ok,1," ");
                    cout<<bintocon[ok];
                    break;
                case '1':
                    SetConsoleTextAttribute(hConsole,defcolor);
                    cout<<bintocon[ok];
                    break;
                default:
                    SetConsoleTextAttribute(hConsole,7);
                    cout<<"error";
                    break;
            }
    SetConsoleTextAttribute(hConsole,12);
    cout<<"\|";
    }
    }

    cout<<endl;
    int value=atoi(bintocon.c_str());
    SetConsoleTextAttribute(hConsole,12);
    cout<<"Character Correspondent: ";
    cout<<(char)value;

    SetConsoleTextAttribute(hConsole,7);
}

void colorfunction(){
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    char colorchoice;
    cout<<"Enter the letter of the color you would like to use for the graphic...\n";

    cout<<"a: ";SetConsoleTextAttribute(hConsole,68);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"b: ";SetConsoleTextAttribute(hConsole,204);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"c: ";SetConsoleTextAttribute(hConsole,221);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"d: ";SetConsoleTextAttribute(hConsole,102);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"e: ";SetConsoleTextAttribute(hConsole,238);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"f: ";SetConsoleTextAttribute(hConsole,170);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"g: ";SetConsoleTextAttribute(hConsole,34);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"h: ";SetConsoleTextAttribute(hConsole,51);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"i: ";SetConsoleTextAttribute(hConsole,17);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"j: ";SetConsoleTextAttribute(hConsole,153);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"k: ";SetConsoleTextAttribute(hConsole,187);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"l: ";SetConsoleTextAttribute(hConsole,85);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"m: ";SetConsoleTextAttribute(hConsole,119);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"n: ";SetConsoleTextAttribute(hConsole,136);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
    cout<<"o: ";SetConsoleTextAttribute(hConsole,255);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;

    cin>>colorchoice;

    switch (colorchoice){
    case 'a':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,68);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=68;
        break;
    case 'b':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,204);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=204;
        break;
    case 'c':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,221);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=221;
        break;
    case 'd':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,102);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=102;
        break;
    case 'e':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,238);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=238;
        break;
    case 'f':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,170);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=170;
        break;
    case 'g':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,34);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=34;
        break;
    case 'h':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,51);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=51;
        break;
    case 'i':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,17);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=17;
        break;
    case 'j':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,153);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=153;
        break;
    case 'k':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,187);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=187;
        break;
    case 'l':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,85);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=85;
        break;
    case 'm':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,119);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=119;
        break;
    case 'n':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,136);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=136;
        break;
    case 'o':
        cout<<"Default color has been changed to ";SetConsoleTextAttribute(hConsole,255);cout<<"0";SetConsoleTextAttribute(hConsole,7);cout<<endl;
        defcolor=255;
        break;
    default:
        cout<< colorchoice <<" is not a valid option...\n";

    }



    cout<<endl;
}
