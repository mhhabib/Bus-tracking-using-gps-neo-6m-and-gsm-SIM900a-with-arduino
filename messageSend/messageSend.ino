#include <TinyGPS.h>

#include <SoftwareSerial.h>
SoftwareSerial Gsm(7, 8);
TinyGPS gps;  //Creates a new instance of the TinyGPS object

void setup()

{

  Serial.begin(9600);
  Gsm.begin(9600);  

}

void loop()
{

  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
  for (unsigned long start = millis(); millis() - start < 1000;)

  {

    while (Serial.available())

    {
      char c = Serial.read();
      Serial.print(c);
      if (gps.encode(c))
        newData = true;  

    }

  }

  if (newData)      //If newData is true
  {
    float flat, flon;
    String output="";
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    /*Gsm.print("AT+CMGF=1\r");
    delay(400);
    Gsm.print("AT+CMGS=\"+8801623709870\"\r");
    delay(300);
    Gsm.print("http://maps.google.com/maps?q=loc:");
   // Gsm.print("Latitude = ");
    Gsm.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    //Gsm.print(" Longitude = ");
    Gsm.print(",");
    Gsm.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    delay(200);
    Gsm.println((char)26); // End AT command with a ^Z, ASCII code 26
    delay(200);
    Gsm.println();
    delay(20000);*/
    flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6;
    flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6;
    Serial.println("Lat:    ");
    Serial.println(flat);
    Serial.println("Lng:   ");
    Serial.println(flon);
    output="cwc19.mhhabib.info/add.php?lat="+String(flat)+"&lng="+String(flon);
    Serial.println(output);

    
    Serial.println("HTTP get method :");
    Serial.print("AT\\r\\n");
    Gsm.println("AT");  /* Check Communication */
    delay(500);
    ShowSerialData(); /* Print response on the serial monitor */
    delay(500);
    /* Configure bearer profile 1 */
    Serial.print("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\\r\\n");    
    Gsm.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");  /* Connection type GPRS */
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.print("AT+SAPBR=3,1,\"APN\",\"www\"\\r\\n");  
    Gsm.println("AT+SAPBR=3,1,\"APN\",\"www\"");  /* APN of the provider */
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.print("AT+SAPBR=1,1\\r\\n");
    Gsm.println("AT+SAPBR=1,1"); /* Open GPRS context */
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.print("AT+SAPBR=2,1\\r\\n");
    Gsm.println("AT+SAPBR=2,1"); /* Query the GPRS context */
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.print("AT+HTTPINIT\\r\\n");
    Gsm.println("AT+HTTPINIT"); /* Initialize HTTP service */
    delay(500); 
    ShowSerialData();
    delay(500);
    Serial.print("AT+HTTPPARA=\"CID\",1\\r\\n");
    Gsm.println("AT+HTTPPARA=\"CID\",1");  /* Set parameters for HTTP session */
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.println("AT+HTTPPARA=\"URL\",\"http://cwc19.mhhabib.info/add.php\"\\r\\n");
    Gsm.print("AT+HTTPPARA=\"URL\",\"cwc19.mhhabib.info/add.php?");
    Gsm.print("&l=");
    Gsm.print(flat,6);
    Gsm.print("&n=");
    Gsm.print(flon,6);
    Gsm.print("\"\r\n");
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.print("AT+HTTPACTION=0\\r\\n");
    Gsm.println("AT+HTTPACTION=0");  /* Start GET session */
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.print("AT+HTTPREAD\\r\\n");
    Gsm.println("AT+HTTPREAD");  /* Read data from HTTP server */
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.print("AT+HTTPTERM\\r\\n");  
    Gsm.println("AT+HTTPTERM");  /* Terminate HTTP service */
    delay(500);
    ShowSerialData();
    delay(500);
    Serial.print("AT+SAPBR=0,1\\r\\n");
    Gsm.println("AT+SAPBR=0,1"); /* Close GPRS context */
    delay(500);
    ShowSerialData();
    delay(500);
    }
}
void ShowSerialData()
{
  while(Gsm.available()!=0)  /* If data is available on serial port */
  Serial.write(char (Gsm.read())); /* Print character received on to the serial monitor */
}
