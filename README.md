# Irrigation-System-Controller-using-WIFI-Module using TinkerCad, ThingSpeak and IFTTT Applet

MODEL :

- The Irrigation system controller using Wifi model is an automated irrigation system with Arduino to efficiently utilize water for irrigation. 
- The system has soil moisture sensors inserted into the soil of the plants and when the moisture level crosses its thresholds, the motor is switched on automatically and the farmer is also informed of the status of the field by a message sent through IFTTT applet. 
 - The soil moisture sensor will detect dankness content of soil leading to turn ON/OFF of pumping motor. Along with this the temperature sensor, gas sensor and LDR are also connected to the Arduino. The speed of the motor and soil moisture level along with the temperature, CO2 level and light intensity is measured continuously and displayed on the LCD screen. It will alert the farmer when the irrigation system is turned on/off via cell phone SMS.
- The microcontroller collects the input signals converted into values of moisture in the soil via soil moisture sensors. As the microcontroller starts obtaining the signals, it creates an output that forces a relay for running the water pumping motor.
-	If the level goes below 40%, the motor is switched on automatically at its highest speed and the farmer is messaged. Between 40% to 60% the motor runs at a medium speed. The farmer is updated about it. Above 60%, the motor is switched off and a text sent to the owner
-	We are using an IFTTT applet which is connected to thingspeak cloud to get the messages.The thingspeak cloud is in turn getting updated regularly by the wifi module.
- The project notifies the farmer's phone when the moisture level  crosses the threshold and also accordingly adjusts the speed  of the motor. For this purpose, we use a Wifi Module (ESP8266). The Wifi module requires a power supply of 3.3 V which is  taken from the arduino. 
-	Therefore the farmer can know the status of his fields even if he is away.

SYSTEM IMPLEMENTATION

Once the hardware circuit is constructed in Tinkercad, it has to be integrated to the thingspeak cloud and IFTTT for the farmer to receive messages. The steps to do so is given below:

Step 1. Create a channel on Thinkspeak cloud.
Step 2. Copy the API key and paste it in the Tinkercad code.
Step 3. Create an Applet on web based service IFTTT from webhooks to SMS.
Step 4. On Thinkspeak cloud create a Thing HTTP and paste applet url in that.
Step 5. On Cloud then create a React and set the condition for triggering the event.
Step 6. Download the IFTTT in your android device.

●	IFTTT Applets are connected from webhooks to android messages to alert the farmer regarding the status of the motor via cellphone SMS.
●	Then the name of the event is mentioned in the given url and all the three events are triggered and tested.
●	Conﬁgure the three ThingHTTP and paste the url from all the three event so that the application layer protocol will be established. And the irrigation system will be connected to the android phone.
●	Conﬁgure the three React in Thingspeak cloud to set the condition for all the three events to trigger.
●	Thingspeak cloud channel which will continuously update the value while running the simulation in Tinkercad.(Soil moisture level , Motor speed Temperature, CO2 level and ldr value)
●	Continuous Messages on Android Phone regarding the status of the motor, soil moisture level and  the speed of the motor to alert the 

The irrigation system was simulated in the online platform of tinkercad. The major hardware components required for the system.

●	Arduino Uno or Arduino nano or  Arduino Mega
●	ESP8266 Wifi module
●	DC Motor
●	LCD Display
●	Soil moisture sensor
●	Gas Sensor
●	LDR
●	TMP36
● Potentiometer for LCD (For adjusting the brightness of the LCD screen)
● Buzzer (To alarm the farmer about the water level in the field)
● Resistor x3
● Breadboard
● Wires
