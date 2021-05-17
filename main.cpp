/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */




#include <iostream>
#include <vector> //not using yet
#include <random>
#include <map>  //not using yet
#include <ctime>
#include <unistd.h>
#include "LeakedObjectDetector.h"   //1)

/*
 copied UDT 1:
 */

struct Oscilloscope
{
    float horizontalInput;
    float verticalInput;
    int horizontalGain;
    int verticalGain;
    int horizontalSweepControl;

    Oscilloscope();
    ~Oscilloscope();
    void graphVoltageOverTime(float yInput, float sweep);
    void graphWaveformDifference (int channelA, int channelB);
    float measureVoltage (float channelA, float channelB);
    float measurement ( float a, float b );
    
    JUCE_LEAK_DETECTOR(Oscilloscope)
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
            horizontalInput += 1;
        }
        verticalInput += 1;
    }
    
    std::cout << std::endl;
    return a + b;
}
//oscilloscope wrapper
struct OscilloscopeWrapper
{
    OscilloscopeWrapper( Oscilloscope* ptr ) : pointerToOscilloscope( ptr )
    {
        std::cout << "Oscilloscope Ctor\n";
    }
    ~OscilloscopeWrapper()
    {
        std::cout << "deleting ptr to Oscilloscope object\n";
        delete pointerToOscilloscope;
    }
    
    Oscilloscope* pointerToOscilloscope = nullptr;
};

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
        
        JUCE_LEAK_DETECTOR(TouchScreen)
    };

    void makeCall (int phoneNumber, std::string personYouAreCalling);
    void playGame (bool gameMode);
    void sendEmail (std::string emailAddress);
    void dropPhone(int timesDropped);
    void cellPhoneFunction();

    TouchScreen touchScreen;
    
    JUCE_LEAK_DETECTOR(CellPhone)
};

CellPhone::CellPhone() : screenSize(3), gigabytesOfRAM(128), hasSDCardPort(false), phoneHasHeadphoneJack(true)
{
    
}

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
//cellphone wrapper
struct CellPhoneWrapper
{
    CellPhoneWrapper( CellPhone* ptr ) : pointerToCellPhone( ptr )
    {
        std::cout << "CellPhone ctor\n";
    }
    ~CellPhoneWrapper()
    {
        std::cout << "deleting ptr to cellPhone object\n";
        delete pointerToCellPhone;
        pointerToCellPhone = nullptr;
    }
    CellPhone* pointerToCellPhone = nullptr;
};

struct TouchScreenWrapper
{
    TouchScreenWrapper( CellPhone::TouchScreen* ptr ) : pointerToTouchScreen( ptr ) {}
    ~TouchScreenWrapper()
    {
        delete pointerToTouchScreen;
        pointerToTouchScreen = nullptr;
    }
    
    CellPhone::TouchScreen* pointerToTouchScreen = nullptr;
};

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
    
    JUCE_LEAK_DETECTOR(ParametricEq)
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
    centerBandGain = centerBandGain - sibilanceAmount;
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

struct ParametricEqWrapper
{
    ParametricEqWrapper( ParametricEq* ptr ) : pointerToParametricEq( ptr ) {}
    ~ParametricEqWrapper()
    {
        delete pointerToParametricEq;
        pointerToParametricEq = nullptr;
    }
    
    ParametricEq* pointerToParametricEq = nullptr;
};

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
    void memberGainFunction();
    void memberPowerFunction();
    
    JUCE_LEAK_DETECTOR(MeasurementRack)
};

MeasurementRack::MeasurementRack()
{
    std::cout << "MeasurementRack constructed\nHorizontal Gain: " << inputOscope.horizontalGain << std::endl;
    
}

MeasurementRack::~MeasurementRack()
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

float MeasurementRack::overallGain()
{
    return inputOscope.measureVoltage(1.5f, 2.21f) + outputOscope.measureVoltage(6.3f, 1.1f);
}

float MeasurementRack::power()
{
    return (outputOscope.measurement(2.1f, 3.1f) * outputOscope.measurement(1.02f, 1.11f)) / supplyScope.measurement(1.01f, 1.11f);
}

void MeasurementRack::memberGainFunction()  //2a)
{
    std::cout << "overall gain is: " << this->overallGain() << std::endl;
}

void MeasurementRack::memberPowerFunction()
{
    std::cout << "overall power is: " << this->power() << std::endl;
}

struct MeasurementRackWrapper
{
    MeasurementRackWrapper( MeasurementRack* ptr ) : pointerToMeasurementRack( ptr ) {}
    ~MeasurementRackWrapper()
    {
        delete pointerToMeasurementRack;
        pointerToMeasurementRack = nullptr;
    }
    
    MeasurementRack* pointerToMeasurementRack = nullptr;
};

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
    
    JUCE_LEAK_DETECTOR(FourBandPEQ)
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

struct FourBandPEQWrapper
{
    FourBandPEQWrapper( FourBandPEQ* ptr ) : pointerToFourBandPEQ( ptr ) { }
    ~FourBandPEQWrapper()
    {
        delete pointerToFourBandPEQ;
        pointerToFourBandPEQ = nullptr;
    }
    
    FourBandPEQ* pointerToFourBandPEQ = nullptr;
};

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
    OscilloscopeWrapper oScopeWrapper( new Oscilloscope() );
    oScopeWrapper.pointerToOscilloscope->measureVoltage(2.01f, 4.123f);
    oScopeWrapper.pointerToOscilloscope->graphWaveformDifference(32, 16);
    oScopeWrapper.pointerToOscilloscope->measurement(5.123f, 6.321f);

    rackFunction();  //free function that tests MeasurementRack

    MeasurementRackWrapper measurementRackWrapper( new MeasurementRack() );
    std::cout << "overall gain is: " << measurementRackWrapper.pointerToMeasurementRack->overallGain() << std::endl;
    measurementRackWrapper.pointerToMeasurementRack->memberGainFunction();
    std::cout << "overall power is: " << measurementRackWrapper.pointerToMeasurementRack->power() << std::endl;
    measurementRackWrapper.pointerToMeasurementRack->memberPowerFunction();
    
    CellPhoneWrapper myPhoneWrapper( new CellPhone() );
    CellPhoneWrapper yourPhoneWrapper(new CellPhone());
    myPhoneWrapper.pointerToCellPhone->makeCall(231345632, "Karen");
    myPhoneWrapper.pointerToCellPhone->dropPhone(2);
    std::cout << "Screen Size: " << yourPhoneWrapper.pointerToCellPhone->screenSize << std::endl;
    yourPhoneWrapper.pointerToCellPhone->cellPhoneFunction();
    
    TouchScreenWrapper myTouchScreenWrapper( new CellPhone::TouchScreen );
    myTouchScreenWrapper.pointerToTouchScreen->fingerPrintVerification(true, false);
    yourPhoneWrapper.pointerToCellPhone->makeCall(8675301, "Daryl");
    TouchScreenWrapper yourTouchScreenWrapper( new CellPhone::TouchScreen );
    yourTouchScreenWrapper.pointerToTouchScreen->fingerPrintVerification(true, true);
    myTouchScreenWrapper.pointerToTouchScreen->backLightTimer(2);

    ParametricEqWrapper pEQWrapper(new ParametricEq );
    pEQWrapper.pointerToParametricEq->rumbleFilter(30.0f, 120.0f);
    pEQWrapper.pointerToParametricEq->killFeedback(220, .15f);
    std::cout << "Vocal DeEss engaged.  Fc: " << pEQWrapper.pointerToParametricEq->centerBandFrequency << " gain reduced to: " << pEQWrapper.pointerToParametricEq->centerBandGain << std::endl; //1)
    pEQWrapper.pointerToParametricEq->vocalDeEss(21.f, 30.f);
    std::cout << "Fc: " << pEQWrapper.pointerToParametricEq->centerBandFrequency << "  Gain: " << pEQWrapper.pointerToParametricEq->centerBandGain << "  Slope: " << pEQWrapper.pointerToParametricEq->centerBandSlope << std::endl;
    pEQWrapper.pointerToParametricEq->centerBandFunction();
    
    FourBandPEQWrapper fbPEQWrapper( new FourBandPEQ );
    fbPEQWrapper.pointerToFourBandPEQ->dimeBagPEQ();
    fbPEQWrapper.pointerToFourBandPEQ->speakerCompensation();

    std::cout << "good to go!\n" << std::endl;

    return 0;
}
