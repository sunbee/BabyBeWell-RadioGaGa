#include <Arduino.h>
#include <SoftwareSerial.h>

#define RX_PIN 25
#define TX_PIN 26

SoftwareSerial lora(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  while(!Serial);

  lora.begin(9600);
  Serial.println("Completed setup for LoRa Tx!");
  delay(1000);

  char* lora_IPR = "AT+IPR=9600\r\n";           // BAUD RATE
  char* lora_ADDRESS = "AT+ADDRESS=120\r\n";    // 0~65535(default 0)
  char* lora_NETWORKID = "AT+NETWORKID=6\r\n";  // 0~16(default 0)
  
  lora.write(lora_IPR);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

  lora.write(lora_ADDRESS);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }
  
  lora.write(lora_NETWORKID);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  // Send AT Commands for validation!
  char* lora_OK = "AT\r\n";
  char* lora_IPR = "AT+IPR?\r\n";
  char* lora_ADDRESS = "AT+ADDRESS?\r\n";
  char* lora_NETWORKID = "AT+NETWORKID?\r\n";
  char* lora_MODE = "AT+MODE?\r\n";
  char* lora_PARAMETER = "AT+PARAMETER?\r\n";
  char* lora_SEND = "AT+SEND=0,11,HELLO WORLD\r";
  
  lora.write(lora_OK);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

  lora.write(lora_IPR);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

  lora.write(lora_MODE);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

  lora.write(lora_PARAMETER);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

  lora.write(lora_ADDRESS);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

  lora.write(lora_NETWORKID);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

  lora.println(lora_SEND);
  delay(1000);
  if (lora.available()) {
    while (lora.available()) {
      char c = lora.read();
      Serial.print(c);
    }
    Serial.println();
  }

  delay(1000);
}
