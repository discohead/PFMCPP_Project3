 #include <iostream>
 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Person
{
    int distanceTraveled = 0;

    struct Foot
    {
        int steps = 0;
        int stepDistance = 1;

        void stepForward()
        {
            steps += 1;
        }

        int stepSize()
        {
            return stepDistance;
        }
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(bool startWithLeftFoot);
};

void Person::run(bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */


/*
 1)
 */
struct Oscillator
{
    float frequency = 440.0;
    float phase = 0.0;
    float amplitude = 1.0;
    unsigned int waveType = 0;
    bool on = false;

    void play();
    void stop();   
};

void Oscillator::play()
{
    on = true;
}

void Oscillator::stop()
{
    on = false;
}
/*
2)
*/
struct Envelope
{
    int numStages = 4;
    int currentStage = 0;
    float attack = 0.1f;
    float decay = 0.1f;
    float sustain = 1.0f;
    float release = 0.5f;
    float amplitude = 1.0f;

    void trigger();
    void reset();
};

void Envelope::trigger()
{
    for (int i = 0; i < numStages; i++)
    {
        currentStage++;
    }
}

void Envelope::reset()
{
    currentStage = 0;
}
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

    Bulb bulb;

    void changeBulb(Bulb newBulb);
    void flipSwitch();
};

void Lamp::changeBulb(Lamp::Bulb newBulb)
{   
    bulb = newBulb;
}

void Lamp::flipSwitch()
{
    on = !on;
}
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

void Book::turnPage()
{
    currentPage++;
}
/*
5)
*/
struct Bicycle
{
    struct Wheel
    {
        float diameter = 2.0f;
        int numSpokes = 20;
    };

    Wheel frontWheel;
    Wheel rearWheel;

    void changeWheel(bool frontWheel, Wheel newWheel);
    void pedal();
    void brake();
};

void Bicycle::changeWheel(bool isFrontWheel, Bicycle::Wheel newWheel)
{
    if (isFrontWheel)
    {
        frontWheel = newWheel;
    }
    else
    {
        rearWheel = newWheel;
    }
}
/*
6)
*/
struct Machine
{
    static const unsigned int maxWidgets = 100;
    unsigned int numWidgets = 0;
    
    struct Widget
    {
        float rotatorSize = 1.0f;
        unsigned int shape = 1;
    };

    Widget widgets[maxWidgets];

    struct Foo
    {
        float bar = 0.0f;
    };

    void addWidget(Widget w);
    float processFoo(Foo foo);
};

void Machine::addWidget(Machine::Widget w)
{
    widgets[numWidgets] = w;
    numWidgets++;
}

float Machine::processFoo(Machine::Foo foo)
{
    return foo.bar * numWidgets;
}
/*
7)
*/
struct Phone
{
    float screenSize = 5.7f;
    bool isSmart = true;

    void makeCall(int phoneNumber);
};

void Phone::makeCall(int phoneNumber)
{
    std::cout << "Calling: " << phoneNumber << std::endl;
}
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

void Keyboard::setCurrentKeyDepressed(char key)
{
    currentKeyDepressed = key;
}
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

void Can::open()
{
    isOpen = true;
}

float Can::getVolume()
{
    return 3.14f * radius * radius * height;
}
/*
10)
*/
struct Synthesizer
{
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

float Synthesizer::render(float ampLevel)
{
    return osc.amplitude * filter.cutoff * filterEnv.amplitude * ampEnv.amplitude * ampLevel;
}

int main()
{
    std::cout << "good to go!" << std::endl;
}
