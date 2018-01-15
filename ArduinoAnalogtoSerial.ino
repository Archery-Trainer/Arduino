// reads analog input from A0 from your arduino board 
// and sends it out via serial

void setup()
{
  // set baud rate 9600
  Serial.begin(19200);
}

void loop()
{
  //reads 4 out of 6 analog ports
  for( int analog_port=A0;analog_port<=A3; analog_port++)
  { 
    
    Serial.print("sensor");
    Serial.print(analog_port);
    Serial.print(":value:");
    //set the muscle sensor input to A0
    int value = analogRead(analog_port);
    
    //send data through serial/usb
    Serial.println(value);
  
    // delay to make it clearer
    delay(100);
  }
}


