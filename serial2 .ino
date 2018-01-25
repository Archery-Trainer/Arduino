// Message sent
String message;
// A counter for making sure all the data is sent 
int counter = 0;

void setup() {
  // Setting up the baudrate to 9600
  Serial.begin(9600);              //Starting serial communication
}
  
void loop() {
  
  counter++;

  //clear the message and add counter
  message = String(counter) + ";";
  
  //goes through the 6 analog ports
  for( int analog_port=A0;analog_port<=A5; analog_port++){ 

    // add the port name and the sensor value to the message
    message = message + analog_port + ":" + String(analogRead(analog_port)) + ";";

    // the analog-digital-converter needs the delay
    delay(10);
  }

  // send the message via serial/USB
  Serial.println(message);

  // delay to make it clearer
  delay(40);
}
