// Reads the analog ports A0-A5, adds them to a message and sends it via the serial USB
// The baud rate needs to match the reader.

// Message sent
String message;
// A counter for making sure all the data is sent 
int counter = 0;

void setup() {
  // Setting up the baudrate to 115200. The Raspberry Pi/etc baud rate must match
  Serial.begin(115200); //Starting serial communication
}
  
void loop() {
  
  counter++;

  //clear the message and add counter
  message = String(counter) + ";";
  
  //goes through the 6 analog ports and adds the values to the message 
  for( int analog_port = A0; analog_port <= A5; analog_port++){ 

    // add the port name and the sensor value to the message
    if(analog_port==A5){
      message = message + String(analogRead(analog_port));
    } else{
      message = message + String(analogRead(analog_port)) + ";";
    }

    // the analog-digital-converter needs the delay
    delay(10);
  }

  // send the message via serial/USB
  Serial.println(message);
  
  // just in case the buffer is flushed 
  Serial.flush();

  // Delay is used because the Android application can't draw the plotter faster.
  // This is not optimized and small decrease might be possible. 
  delay(300);
}
