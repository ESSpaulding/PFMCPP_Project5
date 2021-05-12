/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
        // 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc()
        {
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl;
        }
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

#include <iostream>
#include <vector> //not using yet
#include <random>
#include <map>  //not using yet
#include <ctime>
#include <unistd.h>

/*
 copied UDT 1:
 */

struct Oscilloscope
{
    float horizontalInput; //initialized in-class
    float verticalInput;
    int horizontalGain;
    int verticalGain;
    int horizontalSweepControl;

    Oscilloscope(); //constructor
    ~Oscilloscope();
    void graphVoltageOverTime(float yInput, float sweep);
    void graphWaveformDifference (int channelA, int channelB);
    float measureVoltage (float channelA, float channelB);
    float measurement ( float a, float b );
};

Oscilloscope::Oscilloscope() : horizontalInput(0.0f),
verticalInput(0.0f),
horizontalGain(1),
verticalGain(1),
horizontalSweepControl(1) 
{ 

}

Oscilloscope::~Oscilloscope()
{
    std::cout << "Oscilloscope destructed\n";
}

void Oscilloscope::graphVoltageOverTime(float yInput, float sweep)
{
    std::cout << yInput << sweep << std::endl;
}

void Oscilloscope::graphWaveformDifference (int channelA, int channelB)
{
    std::cout << "The difference voltage between channelA and channelB is: " << channelB - channelA << std::endl;
}

float Oscilloscope::measureVoltage (float channelA, float channelB)
{
    return channelA + channelB;
}

float Oscilloscope::measurement ( float a, float b )
{
    for (int i = 0; i < a; ++i)
    {
        std::cout << i << ": ";
        
        for (int j = 0; j < b; ++j)
        {
            std::cout << j ;
            horizontalInput += 1;  // modifying member variable each time through nested loop
        }
        verticalInput += 1;        // modifying member variable each time through loop
    }
    
    std::cout << std::endl;
    return a + b;
}

/*
 copied UDT 2:
 */

struct CellPhone
{
    std::string carrier = "Sprint";
    int screenSize;
    int gigabytesOfRAM;
    bool hasSDCardPort;
    bool phoneHasHeadphoneJack;
    
    CellPhone();
    ~CellPhone();
    
    struct TouchScreen
    {
        float screenHeight;
        float screenWidth;
        int x, y;
        int numberOfGestures;
        bool backLightOn;
        
        TouchScreen();
        ~TouchScreen();
        
        void fingerPrintVerification(bool ownersFinger, bool usersFinger);
        void getFingerPosition(int X, int Y);
        void quickSwipe(bool swipeUp, bool swipeDown);
        void backLightTimer(float timer);
    };

    void makeCall (int phoneNumber, std::string personYouAreCalling);
    void playGame (bool gameMode);
    void sendEmail (std::string emailAddress);
    void dropPhone(int timesDropped);
    void cellPhoneFunction();

    TouchScreen touchScreen;
};

CellPhone::CellPhone() : screenSize(3), gigabytesOfRAM(128), hasSDCardPort(false), phoneHasHeadphoneJack(true) { }

CellPhone::~CellPhone() 
{ 
    std::cout << "CellPhone object destructed\n"; 
}

void CellPhone::makeCall (int phoneNumber, std::string personYouAreCalling)
{
    std::cout << "Hello " << phoneNumber << " this is " << personYouAreCalling << " Speaking" << std::endl;
}

void CellPhone::playGame (bool gameMode)
{
    std::cout << gameMode << std::endl;
}

void CellPhone::sendEmail (std::string emailAddress)
{
    std::cout << emailAddress << std::endl;
}

void CellPhone::dropPhone(int timesDropped)
{
    std::cout << "Your RAM has fallen from: " << gigabytesOfRAM;

    for ( int i = 0; i < timesDropped; i++)
    {
        gigabytesOfRAM = gigabytesOfRAM - rand()%30;
    }

    std::cout << " to " << gigabytesOfRAM << " becasue you dropped your phone " << timesDropped << " times." << std::endl;
}

void CellPhone::cellPhoneFunction()
{
    this->screenSize = 15;
    std::cout << "Screen Size: " << this->screenSize << std::endl;
}

CellPhone::TouchScreen::TouchScreen() :  screenHeight(4.5f), screenWidth(3.0f), x(0), y(0), numberOfGestures(3), backLightOn(true) 
{ 
    std::cout << "TS Ctr \n"; 
}

CellPhone::TouchScreen::~TouchScreen() 
{ 
    std::cout << "TS Dtr\n"; 
}  

void CellPhone::TouchScreen::fingerPrintVerification(bool ownersFinger, bool usersFinger)
{
     std::cout << "This is " << (ownersFinger == usersFinger ? "your phone" : "not your phone") << "\n";
}

void CellPhone::TouchScreen::getFingerPosition(int X, int Y)
{
    std::cout << "X coordinate is " << X << " Y coordinate is " << Y  << std::endl;
}

void CellPhone::TouchScreen::quickSwipe(bool swipeUp, bool swipeDown)
{
    std::cout << swipeUp << swipeDown << std::endl;
}

void CellPhone::TouchScreen::backLightTimer(float timer)
{   
    float currentTime = 1.1f;

    while (backLightOn)
    {
        std::cout << "Screen ON\n";
    
        while ( currentTime < timer )
        {
            currentTime += 1.f;
        }

        std::cout << "Screen OFF\n";
        backLightOn = false;        
    }
    std::cout << "Goodbye" << std::endl;
}

/*
 copied UDT 3:
 */

struct ParametricEq
{
    float lowShelfFrequency;
    float highShelfFrequency;
    float centerBandFrequency;
    float centerBandGain;
    float centerBandSlope;
    ParametricEq();
    ~ParametricEq();
    void vocalDeEss (float sibilanceAmount, float sibilanceSuppression);
    void rumbleFilter (float rumbleFrequency, float filterCut);
    void killFeedback (float feedbackFrequency, float gainReduction);
    void centerBandFunction();
};

ParametricEq::ParametricEq() :
lowShelfFrequency(50.0f),
highShelfFrequency(1800.0f),
centerBandFrequency(0.5f),
centerBandGain(0.5f),
centerBandSlope(0.7f)
{ 
    std::cout << "ParametricEQ object constructed " << std::endl;
}

ParametricEq::~ParametricEq() //2)
{ 
    std::cout << "ParametricEQ object destructed\n"; 
}   

void ParametricEq::vocalDeEss (float sibilanceAmount, float sibilanceSuppression)
{
    centerBandGain = centerBandGain - sibilanceAmount;   //is this an example of "implied this" ?
    sibilanceSuppression = 0.f;
    std::cout << "Vocal DeEss engaged.  Fc: " << this->centerBandFrequency << " gain reduced to: " << this->centerBandGain << std::endl;
}

void ParametricEq::rumbleFilter (float rumbleFrequency, float filterCut)
{
    centerBandFrequency = rumbleFrequency;
    centerBandGain = filterCut;
    centerBandSlope = 3.f;
    std::cout << "Rumble filter Fc: " << centerBandFrequency << "Hz centerBand gain: " << centerBandGain << " Slope: " << centerBandSlope << std::endl;
}

void ParametricEq::killFeedback (float feedbackFrequency, float gainReduction)
{
    centerBandFrequency = feedbackFrequency;
    centerBandGain = centerBandGain - gainReduction;
    std::cout << "FB suppression Fc: " << centerBandFrequency << " gain reduced to: " << centerBandGain << std::endl;
}

void ParametricEq::centerBandFunction()
{
    std::cout << "Fc: " << this->centerBandFrequency << "  Gain: " << this->centerBandGain << "  Slope: " << this->centerBandSlope << std::endl; // 2b)
}

/*
 new UDT 4:
 */

struct MeasurementRack
{
    Oscilloscope inputOscope,
    outputOscope,
    supplyScope;
    
    MeasurementRack();
    ~MeasurementRack();
    
    float overallGain();
    float power();
    void memberGainFunction();  //2a
    void memberPowerFunction();  //2a  member function that accesses member variable of owning instance of object
};

MeasurementRack::MeasurementRack()   //5)  constructor that does something and calls member function
{
    std::cout << "MeasurementRack constructed\nHorizontal Gain: " << inputOscope.horizontalGain << std::endl;
    
}
MeasurementRack::~MeasurementRack()  //5) destructor that does something on shutdown
{
    inputOscope.horizontalGain = 0;
    inputOscope.verticalGain = 0;
    std::cout << "MeasurementRack destructed\nH.Gain: " << inputOscope.horizontalGain << " V.Gain: " << inputOscope.verticalGain << std::endl;
}

void rackFunction()  //free function called from main
{
    MeasurementRack measurementRack;
    measurementRack.inputOscope.graphVoltageOverTime(3.0f, 2.1f);
    measurementRack.outputOscope.graphWaveformDifference(12, 256);
    measurementRack.supplyScope.measureVoltage(100, 121);
}

float MeasurementRack::overallGain()  // 4) member function #1 of  1st new UDT
{
    return inputOscope.measureVoltage(1.5f, 2.21f) + outputOscope.measureVoltage(6.3f, 1.1f);  //measureVoltage should return a float too*******
}

float MeasurementRack::power()       // 4) member function #2 of  1st new UDT
{
    return (outputOscope.measurement(2.1f, 3.1f) * outputOscope.measurement(1.02f, 1.11f)) / supplyScope.measurement(1.01f, 1.11f);
}

void MeasurementRack::memberGainFunction()  //2a)
{
    std::cout << "overall gain is: " << this->overallGain() << std::endl;  // 2b)
}

void MeasurementRack::memberPowerFunction()  //2a)
{
    std::cout << "overall power is: " << this->power() << std::endl;   // 2b) measurementRack.power()no go, because that instance exists outside
}
/*
 new UDT 5:
 3) using only the types copied above as member functions. 4) with 2 member functions
 */
struct FourBandPEQ
{
    ParametricEq lowBandPEQ,
    lowMidBandPEQ,
    highMidBandPEQ,
    highBandPEQ;
    
    FourBandPEQ();
    ~FourBandPEQ();
    
    void dimeBagPEQ();
    void speakerCompensation();
};

FourBandPEQ::FourBandPEQ() 
{ 
    std::cout <<"FourBandPEQ object constructed\n"; 
}

FourBandPEQ::~FourBandPEQ() 
{ 
    std::cout << "FourBandPEQ object destroyed\n"; 
}

void FourBandPEQ::dimeBagPEQ()
{
    lowBandPEQ.centerBandFrequency = 100.f;
    lowBandPEQ.centerBandGain = 0.3f;
    lowMidBandPEQ.centerBandFrequency = 1000.f;
    lowMidBandPEQ.centerBandGain = 10.f;
    lowMidBandPEQ.centerBandSlope = 1.f;
    
    std::cout << "Frowning face pre EQ :( , smiling face post EQ :)\n";
}

void FourBandPEQ::speakerCompensation()
{
    lowBandPEQ.lowShelfFrequency = 125.f;
    lowMidBandPEQ.centerBandFrequency = 340.f;
    highMidBandPEQ.centerBandFrequency = 1500.f;
    highBandPEQ.highShelfFrequency = 18000.1f;
    
    std::cout << "Your budget speakers have been optimized\n";
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Oscilloscope oScope;  //3) instatiation of UDT
    oScope.measureVoltage(2.01f, 4.123f);
    oScope.graphWaveformDifference(32, 16);
    oScope.measurement(5.123f, 6.321f);

    rackFunction();  //free function that tests MeasurementRack
    MeasurementRack measurementRack;
    std::cout << "overall gain is: " << measurementRack.overallGain() << std::endl;  //1)  main std::cout
    measurementRack.memberGainFunction();  //2c) print the same as above, but from inside the member function
    std::cout << "overall power is: " << measurementRack.power() << std::endl;  //1) main std::cout
    measurementRack.memberPowerFunction();  //2c)
    
    CellPhone myPhone;
    CellPhone yourPhone;
    myPhone.makeCall(231345632, "Karen");
    myPhone.dropPhone(2);
    std::cout << "Screen Size: " << yourPhone.screenSize << std::endl;  //1)
    yourPhone.cellPhoneFunction();                 //2c)  screen size will not be the same because this function changes the objects member variable value
    
    CellPhone::TouchScreen myTouchscreen;
    myTouchscreen.fingerPrintVerification(true, false);
    yourPhone.makeCall(8675301, "Daryl");
    CellPhone::TouchScreen yourTouchscreen;
    yourTouchscreen.fingerPrintVerification(true, true);
    myTouchscreen.backLightTimer(2);

    ParametricEq pEQ;
    pEQ.rumbleFilter(30.0f, 120.0f);
    pEQ.killFeedback(220, .15f);
    std::cout << "Vocal DeEss engaged.  Fc: " << pEQ.centerBandFrequency << " gain reduced to: " << pEQ.centerBandGain << std::endl; //1)
    pEQ.vocalDeEss(21.f, 30.f);  //2c) this function leaves a previous "implied this->" that modifies member variables.
    std::cout << "Fc: " << pEQ.centerBandFrequency << "  Gain: " << pEQ.centerBandGain << "  Slope: " << pEQ.centerBandSlope << std::endl;  //1)
    pEQ.centerBandFunction();                                                                                                               //2c)
    
    FourBandPEQ fbPEQ;
    fbPEQ.dimeBagPEQ();
    fbPEQ.speakerCompensation();

    std::cout << "good to go!\n" << std::endl;
}
