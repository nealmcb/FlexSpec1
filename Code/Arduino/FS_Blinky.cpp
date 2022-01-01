/*****************************************************************************
*
*  FS_Blinky.cpp --
*
* private:
*
*    string name                         ; // This instance's name
*    int    pin                          ; // Pin assigned to the led
*    int    ontime                       ; // The on time for the led
*    int    offtime                      ; // The on time for the led
*    int    pause                        ; // Time to delay between an on/off cycle
*    int    count                        ; // Count of cycles to perform
*    int    status                       ; // Maintain the status condition
*    int    returnrequested              ; // What to do when Process finishes
*
*  Generated by insclass on Sun Jul 11 14:01:21 2021
*
*****************************************************************************/
#include "FS_Blinky.h"
#ifdef __REGRESSION__
#include "ArduinoStub.h"
#endif

#define VERSION "0.0.1"

/*****************************************************************************
*
*  FS_Blinky::ThinkFast -- Constructor
*
*  Get permission for fast interrupt check. FS_Dispatcher
*****************************************************************************/
void FS_Blinky::ThinkFast()
{
  // UNIMPLEMENTED


} // FS_Blinky::ThinkFast

/*****************************************************************************
*
*  FS_Blinky::Report -- Constructor
*
*  Get permission for fast interrupt check. FS_Dispatcher
*****************************************************************************/
void FS_Blinky::Report(string &ref)
{
 ref = string("{ Blinky : {"  "name"              " : "   + name          +           ", "
                        "ontime"           " : "   + to_string(ontime)    + ", "
                        "offtime"          " : "   + to_string(offtime)   + ", "
                        "pause"            " : "   + to_string(pause)     + ", "
                        "count"            " : "   + to_string(count)     + ", "
                        "status"           " : "   + to_string(status)    + ", "
                        "returnrequested"  " : "   + to_string(returnrequested)
                 + "}}");

} // FS_Blinky::Report

/*****************************************************************************
*
*  FS_Blinky::Process -- Constructor
*
*  Get permission for fast interrupt check. FS_Dispatcher
*****************************************************************************/
void FS_Blinky::Process(string &ref)
{
   // TODO INITIALIZE FROM THE STRING
   for(int i = 0; i < count; ++i)
   {
       digitalWrite(pin,0);
       delay(ontime);
       digitalWrite(pin,1);
       delay(offtime);
       delay(pause);
   }
   // TODO returnrequested


} // FS_Blinky::Process

/*****************************************************************************
*
*  FS_Blinky::Inventory -- Constructor
*
*  Load string with the inventory info
*****************************************************************************/
void FS_Blinky::Inventory(string &ref)
{
   ref = VERSION;

} // FS_Blinky::Inventory

/*****************************************************************************
*
*  FS_Blinky::reset -- Constructor
*
** Reset -- whatever that may mean.
*****************************************************************************/
void FS_Blinky::reset()
{
   count = 0;

} // FS_Blinky::reset
