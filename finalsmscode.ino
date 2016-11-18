/*********************************************************************
Code by Lucky Mokalusi
mokluc@hotmail.com
*********************************************************************/

#include "SIM900.h"
#include <SoftwareSerial.h> //GSM RX = 3; TX = 2
#include "sms.h"
SMSGSM sms;
const int Relay1 = A4;
const int Relay2 = A3;
const int GSMReadyLED = A1;
int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];

char sms_position;
char phone_number[20];
char sms_text[10];
int i;
int pos;
void setup()
{
    
    pinMode(Relay1, OUTPUT);
    pinMode(Relay2,  OUTPUT);
    pinMode(GSMReadyLED,  OUTPUT);
    digitalWrite(GSMReadyLED, LOW);
    
    if (gsm.begin(9600)) 
    {
        started=true;
    }
   
    
}
void loop()
{
  digitalWrite(GSMReadyLED, HIGH);
  String str="";
  int y;
  
    if(started) 
    {
      
        
        sms_position=sms.IsSMSPresent(SMS_UNREAD);
        if (sms_position) 
        {
          
            
            sms.GetSMS(sms_position, phone_number, sms_text, 10);
        
            for (y=0;y<10;y++)
            
            {
              str+= sms_text[y];
              str.toUpperCase();
             
              
            }
            if(str =="R11")
            {
              digitalWrite(Relay1, HIGH);  
             
          
            
            }
            
            if(str =="R10")
            {
              digitalWrite(Relay1, LOW);   
              
             
            }
            
            if(str =="R21")
            {
              digitalWrite(Relay2, HIGH);  
             
            }
            
            if(str =="R20")
            {
              digitalWrite(Relay2, LOW);   
           
            }
            if(str =="ALLON")
            {
              digitalWrite(Relay1, HIGH); 
              digitalWrite(Relay2, HIGH);  
             
            }
            
            if(str =="ALLOFF")
            {
              digitalWrite(Relay1, LOW); 
              digitalWrite(Relay2, LOW);  
            
            }
            
        }
          
      
    }
    
}
