/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor.
 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class.
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.
 3) add 2 new UDTs that use only the types you copied above as member variables.
 4) add 2 member functions that use your member variables to each of these new UDTs
 5) Add constructors and destructors to these 2 new types that do stuff.
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

/*
 0) check 1) Oscilloscope, phone, parametricEQcheck 2) add destructors check 3) Add 2 new UDTS that use previous udt's as member variables   4) 5) 6) check
 */
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

//Constructor intializer list
Oscilloscope::Oscilloscope() : horizontalInput(0.0f),
verticalInput(0.0f),
horizontalGain(1),
verticalGain(1),
horizontalSweepControl(1) { }
// 2) destructor implementation outside class
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
    
    CellPhone() : screenSize(3), gigabytesOfRAM(128), hasSDCardPort(false), phoneHasHeadphoneJack(true) { }
    ~CellPhone() { std::cout << "CellPhone object destructed\n"; }    // 2) in-class destructor implementation
    
    struct TouchScreen
    {
        float screenHeight;
        float screenWidth;
        int x, y;
        int numberOfGestures;
        bool backLightOn;
        
        TouchScreen() :  screenHeight(4.5f), screenWidth(3.0f), x(0), y(0), numberOfGestures(3), backLightOn(true) { std::cout << "TS Ctr \n"; }
        ~TouchScreen() { std::cout << "TS Dtr\n"; }  //2) in-class destructor
        
        void fingerPrintVerification(bool ownersFinger, bool usersFinger);
        void getFingerPosition(int X, int Y);
        void quickSwipe(bool swipeUp, bool swipeDown);
        void backLightTimer(float timer);                   //backLightTimer turns off the backLight to save power after timer runs out.
    };

    void makeCall (int phoneNumber, std::string personYouAreCalling);
    void playGame (bool gameMode);
    void sendEmail (std::string emailAddress);
    void dropPhone(int timesDropped);

    TouchScreen touchScreen;
};

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
    time_t currentTime = time(nullptr);
    while (backLightOn)
    {
        std::cout << "Screen ON\n";
    
        while ( time(nullptr) - currentTime < timer )
        {
            //nice blocking loop here :/
        }
        std::cout << "Screen OFF\n";
        backLightOn = false;         //modifying member variable
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
};
//outside class constructor-initializer-list implementation
ParametricEq::ParametricEq() :
lowShelfFrequency(50.0f),
highShelfFrequency(1800.0f),
centerBandFrequency(0.5f),
centerBandGain(0.5f),
centerBandSlope(0.7f)
{}
//outside-class destructor implementation
ParametricEq::~ParametricEq() { std::cout << "ParametricEQ object destructed\n"; }   //2)
//vocalDeEss could use eq to assign Fc to 4kHz and decrease gain by 6dB.
void ParametricEq::vocalDeEss (float sibilanceAmount, float sibilanceSuppression)
{
    centerBandFrequency = 4000.f;
    centerBandGain = centerBandGain - sibilanceAmount;
    sibilanceSuppression = 0.f;
    std::cout << "Vocal DeEss engaged.  Fc: " << centerBandFrequency << " gain reduced to: " << centerBandGain << std::endl;
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

/*
 new UDT 4:
 3) using only the types copied above as member functions. 4) with 2 member functions
 */

struct MeasurementRack
{
    Oscilloscope inputOscope,
    outputOscope,
    supplyScope;
    
    MeasurementRack();
    ~MeasurementRack();
    
    float overallGain();  //4) memeber function
    float power();        //4) member function #2
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

FourBandPEQ::FourBandPEQ() { std::cout <<"FourBandPEQ object constructed\n"; }
FourBandPEQ::~FourBandPEQ() { std::cout << "FourBandPEQ object destroyed\n"; }

void FourBandPEQ::dimeBagPEQ()  // 4) member function #1 of  2nd new UDT
{
    lowBandPEQ.centerBandFrequency = 100.f;
    lowBandPEQ.centerBandGain = 0.3f;
    lowMidBandPEQ.centerBandFrequency = 1000.f;
    lowMidBandPEQ.centerBandGain = 10.f;
    lowMidBandPEQ.centerBandSlope = 1.f;
    
    std::cout << "Frowning face pre EQ :( , smiling face post EQ :)\n";
}

void FourBandPEQ::speakerCompensation()  // 4) member function #2 of 2nd new UDT
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
    srand(time(nullptr));
    
    std::cout << "we are in the main function" << std::endl;
    Oscilloscope oScope;  //3) instatiation of UDT
    oScope.measureVoltage(2.01f, 4.123f);
    oScope.graphWaveformDifference(32, 16);
    oScope.measurement(5.123f, 6.321f);

    rackFunction();  //free function that tests MeasurementRack
    MeasurementRack measurementRack;                                                 //7 instantiate new UDT and call member functions
    std::cout << "overall gain is: " << measurementRack.overallGain() << std::endl;
    std::cout << "overall power is: " << measurementRack.power() << std::endl;
    
    CellPhone myPhone;
    CellPhone yourPhone;
    myPhone.makeCall(231345632, "Karen");
    myPhone.dropPhone(2);
    CellPhone::TouchScreen myTouchscreen;
    myTouchscreen.fingerPrintVerification(true, false);
    yourPhone.makeCall(8675301, "Daryl");
    CellPhone::TouchScreen yourTouchscreen;
    yourTouchscreen.fingerPrintVerification(true, true);
    myTouchscreen.backLightTimer(2);                          //part5 loop that changes member variable backLightOn in seconds

    ParametricEq pEq;
    pEq.rumbleFilter(30.0f, 120.0f);
    pEq.killFeedback(220, .15f);
    //UDT created from ParamtricEQ objects to create a larger, more complex EQ..kinda  //7
    FourBandPEQ fbPEQ;
    fbPEQ.dimeBagPEQ();
    fbPEQ.speakerCompensation();

    std::cout << "good to go!\n" << std::endl;
}
