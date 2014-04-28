//==============================================================
//Project Lynxmotion Phoenix
//Description: 
//    This is the hardware configuration file for the Hex Robot.
//  
//
//Date: March 18, 2012
//Programmer: Kurt (aka KurtE)
//Angepasst von Christoph Reiter
//
//==============================================================
#ifndef HEX_CFG_PHOENIX_H
#define HEX_CFG_PHOENIX_H

#define DEFINE_HEX_GLOBALS

// Es wird die serielle Schnittstelle des Arduinos verwendet
// Angeschlossen ist der Servocontroller
#define SSCSerial    Serial
// Servocontroller Baudrate
#define cSSC_BAUD    38400

// which output module to use
#define USE_SSC32

// use hardware Serial so no port setting possible
#define cSSC_OUT     0
#define cSSC_IN      0

// Welcher Pin an welchen Servo angeschlossen ist
//==============================================================

// Rechts Hinten
#define cRRCoxaPin      1
#define cRRFemurPin     0
#define cRRTibiaPin     6
#define cRRTarsPin      //3

// Rechts Mitte
#define cRMCoxaPin      3
#define cRMFemurPin     2
#define cRMTibiaPin     7
#define cRMTarsPin      //7

// Rechts Vorne
#define cRFCoxaPin      5
#define cRFFemurPin     4
#define cRFTibiaPin     8
#define cRFTarsPin      //11

// Links Hinten
#define cLRCoxaPin      17 
#define cLRFemurPin     16 
#define cLRTibiaPin     22 
#define cLRTarsPin      //19

// Links Mitte
#define cLMCoxaPin      19
#define cLMFemurPin     18
#define cLMTibiaPin     23
#define cLMTarsPin      //23

// Links Vorne
#define cLFCoxaPin      21
#define cLFFemurPin     20
#define cLFTibiaPin     24
#define cLFTarsPin      //27


//--------------------------------------------------------------
//[MIN/MAX ANGLES]
#define CoxaMin         -600
#define CoxaMax         600
#define FemurMin        -900
#define FemurMax        450
#define TibiaMin        -900
#define TibiaMax        900

//Mechanical limits of the Right Rear Leg
#define cRRCoxaMin1     CoxaMin      
#define cRRCoxaMax1     CoxaMax
#define cRRFemurMin1    FemurMin
#define cRRFemurMax1    FemurMax
#define cRRTibiaMin1    TibiaMin
#define cRRTibiaMax1    TibiaMax
//4DOF ONLY - In theory the kinematics can reach about -160 deg
//4DOF ONLY - The kinematics will never exceed 23 deg though..
#define cRRTarsMin1     -1300	
#define cRRTarsMax1	500	

//Mechanical limits of the Right Middle Leg
#define cRMCoxaMin1     CoxaMin      
#define cRMCoxaMax1     CoxaMax
#define cRMFemurMin1    FemurMin
#define cRMFemurMax1    FemurMax
#define cRMTibiaMin1    TibiaMin
#define cRMTibiaMax1    TibiaMax
//4DOF ONLY - In theory the kinematics can reach about -160 deg
//4DOF ONLY - The kinematics will never exceed 23 deg though..
#define cRMTarsMin1     -1300	
#define cRMTarsMax1	500	

//Mechanical limits of the Right Front Leg
#define cRFCoxaMin1     CoxaMin      
#define cRFCoxaMax1     CoxaMax
#define cRFFemurMin1    FemurMin
#define cRFFemurMax1    FemurMax
#define cRFTibiaMin1    TibiaMin
#define cRFTibiaMax1    TibiaMax
//4DOF ONLY - In theory the kinematics can reach about -160 deg
//4DOF ONLY - The kinematics will never exceed 23 deg though..
#define cRFTarsMin1     -1300	
#define cRFTarsMax1	500	

//Mechanical limits of the Left Rear Leg
#define cLRCoxaMin1     CoxaMin      
#define cLRCoxaMax1     CoxaMax
#define cLRFemurMin1    FemurMin
#define cLRFemurMax1    FemurMax
#define cLRTibiaMin1    TibiaMin
#define cLRTibiaMax1    TibiaMax
//4DOF ONLY - In theory the kinematics can reach about -160 deg
//4DOF ONLY - The kinematics will never exceed 23 deg though..
#define cLRTarsMin1     -1300	
#define cLRTarsMax1	500	

//Mechanical limits of the Left Middle Leg
#define cLMCoxaMin1     CoxaMin      
#define cLMCoxaMax1     CoxaMax
#define cLMFemurMin1    FemurMin
#define cLMFemurMax1    FemurMax
#define cLMTibiaMin1    TibiaMin
#define cLMTibiaMax1    TibiaMax
//4DOF ONLY - In theory the kinematics can reach about -160 deg
//4DOF ONLY - The kinematics will never exceed 23 deg though..
#define cLMTarsMin1     -1300	
#define cLMTarsMax1	500	

//Mechanical limits of the Left Front Leg
#define cLFCoxaMin1     CoxaMin      
#define cLFCoxaMax1     CoxaMax
#define cLFFemurMin1    FemurMin
#define cLFFemurMax1    FemurMax
#define cLFTibiaMin1    TibiaMin
#define cLFTibiaMax1    TibiaMax
//4DOF ONLY - In theory the kinematics can reach about -160 deg
//4DOF ONLY - The kinematics will never exceed 23 deg though..
#define cLFTarsMin1     -1300	
#define cLFTarsMax1	500	

//--------------------------------------------------------------
//[LEG DIMENSIONS]
//Universal dimensions for each leg in mm

// Die Abmessungen der Beine müssen hier eingetragen werden
#define cXXCoxaLength     29    // This is for Phoenix
#define cXXFemurLength    77
#define cXXTibiaLength    110
#define cXXTarsLength         // 4DOF only...

 //Right Rear leg
#define cRRCoxaLength     cXXCoxaLength	   
#define cRRFemurLength    cXXFemurLength
#define cRRTibiaLength    cXXTibiaLength
//4DOF ONLY
#define cRRTarsLength	  cXXTarsLength	    

//Right middle leg
#define cRMCoxaLength     cXXCoxaLength	    
#define cRMFemurLength    cXXFemurLength
#define cRMTibiaLength    cXXTibiaLength
//4DOF ONLY
#define cRMTarsLength	  cXXTarsLength	    

//Rigth front leg
#define cRFCoxaLength     cXXCoxaLength	    
#define cRFFemurLength    cXXFemurLength
#define cRFTibiaLength    cXXTibiaLength
//4DOF ONLY
#define cRFTarsLength	  cXXTarsLength    

//Left Rear leg
#define cLRCoxaLength     cXXCoxaLength	    
#define cLRFemurLength    cXXFemurLength
#define cLRTibiaLength    cXXTibiaLength
//4DOF ONLY
#define cLRTarsLength	  cXXTarsLength    

//Left middle leg
#define cLMCoxaLength     cXXCoxaLength	    
#define cLMFemurLength    cXXFemurLength
#define cLMTibiaLength    cXXTibiaLength
//4DOF ONLY
#define cLMTarsLength	  cXXTarsLength	   

//Left front leg
#define cLFCoxaLength     cXXCoxaLength	    
#define cLFFemurLength    cXXFemurLength
#define cLFTibiaLength    cXXTibiaLength
//4DOF ONLY
#define cLFTarsLength	  cXXTarsLength	    


//--------------------------------------------------------------
//[BODY DIMENSIONS]
// Die Abmessungen der Grundplattform sowie

// Die Winkel in denen die Beine von
// der Grundplattform abstehen
// angegeben in zehntel Grad
// Die 6 Beine sind immer in Winkeln von 60° montiert
#define cRRCoxaAngle1   -600
#define cRMCoxaAngle1    0
#define cRFCoxaAngle1    600
#define cLRCoxaAngle1    -600
#define cLMCoxaAngle1    0
#define cLFCoxaAngle1    600

// Die X und Y Abstände von den 
// Beinen zur Grundplattform

//Distance X from center of the body to the Right Rear coxa
#define cRROffsetX      -43
//Distance Z from center of the body to the Right Rear coxa
#define cRROffsetZ      84     
//Distance X from center of the body to the Right Middle coxa
#define cRMOffsetX      -63
//Distance Z from center of the body to the Right Middle coxa
#define cRMOffsetZ      0
//Distance X from center of the body to the Right Front coxa
#define cRFOffsetX      -43     
//Distance Z from center of the body to the Right Front coxa
#define cRFOffsetZ      -119    
//Distance X from center of the body to the Left Rear coxa
#define cLROffsetX      43      
//Distance Z from center of the body to the Left Rear coxa
#define cLROffsetZ      119     
//Distance X from center of the body to the Left Middle coxa
#define cLMOffsetX      63     
//Distance Z from center of the body to the Left Middle coxa
#define cLMOffsetZ      0       
//Distance X from center of the body to the Left Front coxa
#define cLFOffsetX      43      
//Distance Z from center of the body to the Left Front coxa
#define cLFOffsetZ      -119    

//--------------------------------------------------------------
//[START POSITIONS FEET]
// Erste Position die der Roboter einnimmt

#define cHexInitXZ	 111 
#define CHexInitXZCos60  56        // COS(60) = .5
#define CHexInitXZSin60  96    // sin(60) = .866
#define CHexInitY        65 //30

#define CNT_HEX_INITS 3
#define MAX_BODY_Y  90
#ifdef DEFINE_HEX_GLOBALS
const byte g_abHexIntXZ[] PROGMEM = {cHexInitXZ, 99, 86};
const byte g_abHexMaxBodyY[] PROGMEM = { 20, 50, MAX_BODY_Y};
#else
extern const byte g_abHexIntXZ[] PROGMEM;
extern const byte g_abHexMaxBodyY[] PROGMEM;
#endif

//Start positions of the Right Rear leg
#define cRRInitPosX     CHexInitXZCos60
#define cRRInitPosY     CHexInitY
#define cRRInitPosZ     CHexInitXZSin60

//Start positions of the Right Middle leg
#define cRMInitPosX     cHexInitXZ      
#define cRMInitPosY     CHexInitY
#define cRMInitPosZ     0

//Start positions of the Right Front leg
#define cRFInitPosX     CHexInitXZCos60      
#define cRFInitPosY     CHexInitY
#define cRFInitPosZ     -CHexInitXZSin60

//Start positions of the Left Rear leg
#define cLRInitPosX     CHexInitXZCos60     
#define cLRInitPosY     CHexInitY
#define cLRInitPosZ     CHexInitXZSin60

//Start positions of the Left Middle leg
#define cLMInitPosX     cHexInitXZ      
#define cLMInitPosY     CHexInitY
#define cLMInitPosZ     0

//Start positions of the Left Front leg
#define cLFInitPosX     CHexInitXZCos60     
#define cLFInitPosY     CHexInitY
#define cLFInitPosZ     -CHexInitXZSin60

//--------------------------------------------------------------
// [Tars factors used in formula to calc Tarsus angle relative
// to the ground]
#define cTarsConst	720	//4DOF ONLY
#define cTarsMulti	2	//4DOF ONLY
#define cTarsFactorA	70	//4DOF ONLY
#define cTarsFactorB	60	//4DOF ONLY
#define cTarsFactorC	50	//4DOF ONLY

#endif //CFG_HEX_H
