void setup() {
  ​Serial.begin(9600);  
}
 
void loop() {
  ​int value = analogRead(A0);   
                                ​
  ​Serial.println(value);       
  
  ​int voltage;
  ​voltage = map(value,0,1023,0,5000);   
                                        ​
  ​Serial.println(voltage);              
  
  ​Serial.println();     
  ​delay(200);           
}
