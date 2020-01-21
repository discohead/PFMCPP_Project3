/*
 Project 3 - Part 1 / 5
Video:  Chapter 2 Part 5
 User-Defined Types

 Create a branch named Part1
 
 1) write 10 user-defined types, each with a random number of member variables
    try to make the member variables have names that are related to the user-defined type.
 
 2) give the member variables relevant data types
 
 3) add a couple member functions.  
    make the function parameter list for those member functions use some of your User-Defined Types
 
 4) make 2 of the 10 user-defined types be nested class
 
 5) One of your UDTs should only use UDTs for its member variable types.   
     No primitives allowed!
 
 6) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};


/*
 1)
 */
 struct Oscillator
 {
   float frequency = 440.0;
   float phase = 0.0;
   float amplitude = 1.0;
   unsigned int waveType = 0;

   void play();
   void stop();   
 };

/*
 2)
 */
 struct Envelope
 {
   float attack = 0.1f;
   float decay = 0.1f;
   float sustain = 1.0f;
   float release = 0.5f;
   float amplitude = 1.0f;

   void trigger();
   void reset();
 };

/*
 3)
 */
 struct Lamp
 {
   bool on = false;

   struct Bulb
   {
     float brightness = 100.0f;
     float warmth = 0.5f;
   };

   void changeBulb(Bulb bulb);
   void flipSwitch();
 };


/*
 4)
 */
 struct Book
 {
   unsigned int numPages = 100;
   unsigned int currentPage = 0;
   float fontSize = 12.0f;
   bool isHardBack = false;

   void turnPage();
 };

/*
 5)
 */
 struct Cycle
 {
   unsigned int numWheels = 2;
   
   struct Wheel
   {
     float diameter = 2.0f;
     int numSpokes = 20;
   };

   void addWheel(Wheel wheel);
   void pedal();
   void brake();
 };

/*
 6)
 */
 struct Machine
 {
   float voltage = 10.0f;
   unsigned int numWidgets = 100;

   struct Widget
   {
     float rotatorSize = 1.0f;
     unsigned int shape = 1;
   };

   struct Foo
   {
     float bar = 0.0f;
   };

   void addWidget(Widget w);
   float processFoo(Foo foo);
 };

/*
 7)
 */
 struct Phone
 {
   float screenSize = 5.7f;
   bool isSmart = true;
   
   void makeCall(int phoneNumber);
 };

/*
 8)
 */
struct Keyboard
{
  bool isQwerty = true;
  bool hasNumpad = false;
  char currentKeyDepressed;

  void setCurrentKeyDepressed(char key);

};
/*
 9)
 */
 struct Can
 {
   float height = 5.0f;
   float radius = 2.0f;
   bool isOpen = false;

   void open();
   float getVolume();
 };
/*
 10)
 */
 struct Synthesizer
 {
  struct Oscillator
  {
    float frequency = 440.0f;
    float phase = 0.0f;
    float amplitude = 1.0f;
    unsigned int waveType = 0;

    void play();
    void stop();   
  };

  struct Envelope
  {
    float attack = 0.1f;
    float decay = 0.1f;
    float sustain = 1.0f;
    float release = 0.5f;
    float amplitude = 1.0f;

    void trigger();
    void reset();
  };

  struct Filter
  {
    float cutoff = 600.0f;
    float resonance = 0.f;
    int numPoles = 12;
  };

  Oscillator osc;
  Envelope filterEnv;
  Envelope ampEnv;
  Filter filter;

  float render(float ampLevel);
 };

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
