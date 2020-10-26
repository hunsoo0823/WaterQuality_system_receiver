#include <SPI.h>
#include <LoRa.h>
#include <ArduinoJson.h>

char recv;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  Serial.println("LoRa Receiver");

  if(!LoRa.begin(915E6)){
    Serial.println("Starting LoRa failed");
    while(1);
  }
}

void loop(){

  
  int parameter = 0;
  int packetSize = LoRa.parsePacket();
  if(packetSize) {
    Serial.print("  ORP value : ");
    String orpValue="";
    String phValue="";
    String tdsValue="";
    String doValue="";
    String turValue="";
    while(LoRa.available()){
      
      recv = (char)LoRa.read();
      
      if(recv == ' '){
        Serial.println();
        parameter++;
        if(parameter == 1) Serial.print("  PH value : ");
        if(parameter == 2) Serial.print("  TDS value : ");
        if(parameter == 3) Serial.print("  DO value : ");
        if(parameter == 4) Serial.print("  TUR value : ");
      }
      else
      {
        if(parameter == 0) orpValue += recv;
        if(parameter == 1) phValue += recv;
        if(parameter == 2) tdsValue += recv;
        if(parameter == 3) doValue += recv;
        if(parameter == 4) turValue += recv;
        Serial.print(recv);
      }
    }
      Serial.println("-------lora-------");
      Serial.println(orpValue);
      Serial.println(phValue);
      Serial.println(tdsValue);
      Serial.println(doValue);
      Serial.println(turValue);
      Serial.println("-------String-------"); 
}
 
  
  
  /*
  String message = "";
  int packetSize = LoRa.parsePacket();
  if(packetSize) {
  while (LoRa.available()) {
    recv = (char)LoRa.read();
    message += recv;
  }

  Serial.print("Node Receive: ");
  Serial.println(message);
  }
  */

}