#include <EEPROM.h>
#include <SPI.h>
#include <WiFi.h>

//http://playground.arduino.cc/Code/TwitterLibrary
// twitter token: 2422087854-gTM4Re3WULWOJsrF2qKjjoItfm7r2sEyzUx2R3G

//thuis
/*char ssid[] = "STS-VanReeth";     //  your network SSID (name) 
char pass[] = "6007001972";   // your network password*/


//kot
char ssid[] = "telenet-09E47";     //  your network SSID (name) 
char pass[] = "9920592504";   // your network password
int keyIndex = 0;                 // your network key Index number (needed only for WEP)



int status = WL_IDLE_STATUS;


String data;
int adr=0;
int digi;
WiFiClient client;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
 
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 
  
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);
  
    // wait 10 seconds for connection:
    delay(10000);
  } 
Serial.print("You're connected to the network");
  printCurrentNet();
  printWifiData();
}
void loop() {
  
  digi=digitalRead(8);
   Serial.println(digitalRead(8));
   
  if(EEPROM.read(adr)!=digi){
     EEPROM.write(adr, digi);
    data = "data=" + digi;
   
    
    if (client.connect("www.jonastests.eu",80)) { // REPLACE WITH YOUR SERVER ADDRESS
        client.println("POST /add.php HTTP/1.1"); 
        client.println("Host: www.jonastests.eu"); // SERVER ADDRESS HERE TOO
        client.println("User-Agent: Arduino/1.0");
        client.println("Content-Type: application/x-www-form-urlencoded"); 
        client.print("Content-Length: "); 
        client.println(data.length()); 
        client.println(); 
        client.print(data); 
        Serial.println("connected");
      }
    else
      {
      Serial.println("can't connect");
      }
  } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
    Serial.println("connection closed");
  }
  //Serial.println("rondje " + digi);
  delay(1000);
}



void printWifiData() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of the router you're attached to:
  byte bssid[6];
  WiFi.BSSID(bssid);    
  Serial.print("BSSID: ");
  Serial.print(bssid[5],HEX);
  Serial.print(":");
  Serial.print(bssid[4],HEX);
  Serial.print(":");
  Serial.print(bssid[3],HEX);
  Serial.print(":");
  Serial.print(bssid[2],HEX);
  Serial.print(":");
  Serial.print(bssid[1],HEX);
  Serial.print(":");
  Serial.println(bssid[0],HEX);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

  // print the encryption type:
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption,HEX);
  Serial.println();
}
