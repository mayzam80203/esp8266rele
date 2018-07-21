

/*
НАЙДИ НИЖЕ ТАКИЕ СТРОКИ И ЗАПОЛНИ ИХ ПОД СВОЮ СЕТЬ
const char* host = "rele-remote";
const char* ssid = "WIFI-HOME";
const char* password = "1234567890";
const char* ssidap = "WIFI-rele";
const char* passwordap = "1234567890";
*/
///////////////ZAM  "ПЕРЕМЕННЫЕ"-ВЫШЕ//////////////////////////////////////////////////////////////



#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


#define ledPin0 D0
#define ledPin1 D1
#define ledPin2 D2
#define ledPin3 D3
#define ledPin4 D4
#define ledPin5 D5
#define ledPin6 D6
#define ledPin7 D7
#define ledPin8 D8




const char* host = "rele-remote";
const char* ssid = "WIFI-HOME";
const char* password = "1234567890";
const char* ssidap = "WIFI-rele";
const char* passwordap = "1234567890";

ESP8266WebServer server(80);
const char* serverIndex = "<form method='POST' action='/update/update' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'></form>";

void setup(void){
  Serial.begin(115200);
    delay(10);

////////////////////
Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssidap, passwordap);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
////////////////////это заменило открытую сеть AP по умолчанию




 
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);

  
  
  
  
  
  
  digitalWrite(ledPin0, 1);
  digitalWrite(ledPin1, 1);
  digitalWrite(ledPin2, 1);
  digitalWrite(ledPin3, 1);
  digitalWrite(ledPin4, 0);
  digitalWrite(ledPin5, 1);
  digitalWrite(ledPin6, 1);
  digitalWrite(ledPin7, 1);
  digitalWrite(ledPin8, 1);



    
  Serial.println();
  Serial.println("Booting Sketch...");
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  if(WiFi.waitForConnectResult() == WL_CONNECTED){
    MDNS.begin(host);



 server.on("/", [](){
    server.send(200, "text/html", webPage());
////////////////////////SSILKA NA KNOPKU0///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8//////////////////////////////////////////////////
  });

  server.on("/ledPin0On", [](){
    digitalWrite(ledPin0, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin0Off", [](){
    digitalWrite(ledPin0, 0);
    server.send(200, "text/html", webPage());
    delay(100);
 ///////////////////////////SSILKA NA KNOPKU1///////////////////////////////////////////////   
    });

  server.on("/ledPin1On", [](){
    digitalWrite(ledPin1, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin1Off", [](){
    digitalWrite(ledPin1, 0);
    server.send(200, "text/html", webPage());
    delay(100);
////////////////////////////SSILKA NA KNOPKU2/////////////////////////////////////////////////////
    });

  server.on("/ledPin2On", [](){
    digitalWrite(ledPin2, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin2Off", [](){
    digitalWrite(ledPin2, 0);
    server.send(200, "text/html", webPage());
    delay(100);
////////////////////////////SSILKA NA KNOPKU3/////////////////////////////////////////////////////
    });

  server.on("/ledPin3On", [](){
    digitalWrite(ledPin3, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin3Off", [](){
    digitalWrite(ledPin3, 0);
    server.send(200, "text/html", webPage());
    delay(100);
////////////////////////////SSILKA NA KNOPKU4/////////////////////////////////////////////////////
    });

  server.on("/ledPin4On", [](){
    digitalWrite(ledPin4, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin4Off", [](){
    digitalWrite(ledPin4, 0);
    server.send(200, "text/html", webPage());
    delay(100);
////////////////////////////SSILKA NA KNOPKU5/////////////////////////////////////////////////////
    });

  server.on("/ledPin5On", [](){
    digitalWrite(ledPin5, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin5Off", [](){
    digitalWrite(ledPin5, 0);
    server.send(200, "text/html", webPage());
    delay(100);
////////////////////////////SSILKA NA KNOPKU6/////////////////////////////////////////////////////
    });

  server.on("/ledPin6On", [](){
    digitalWrite(ledPin6, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin6Off", [](){
    digitalWrite(ledPin6, 0);
    server.send(200, "text/html", webPage());
    delay(100);
////////////////////////////SSILKA NA KNOPKU7/////////////////////////////////////////////////////  
    });

  server.on("/ledPin7On", [](){
    digitalWrite(ledPin7, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin7Off", [](){
    digitalWrite(ledPin7, 0);
    server.send(200, "text/html", webPage());
    delay(100);
////////////////////////////SSILKA NA KNOPKU8/////////////////////////////////////////////////////
    });

  server.on("/ledPin8On", [](){
    digitalWrite(ledPin8, 1);
    server.send(200, "text/html", webPage());
    delay(100);
    
  });

  server.on("/ledPin8Off", [](){
    digitalWrite(ledPin8, 0);
    server.send(200, "text/html", webPage());
    delay(100);
/////////////////////////////////////////////////////////////////////////////////
 
  });




    //zamzamzamzamzamzamzamzamzamzamzamzamzamzamzamzamza
    server.on("/update/", HTTP_GET, [](){
      server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/html", serverIndex);
    });
  
   //zamzamzamzamzamzamzamzamzamzamzamzamzamzamzamzamza
   
    server.on("/update/update", HTTP_POST, [](){
      server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/plain", (Update.hasError())?"FAIL":"OK");
      ESP.restart();
    },[](){
      HTTPUpload& upload = server.upload();
      if(upload.status == UPLOAD_FILE_START){
        Serial.setDebugOutput(true);
        WiFiUDP::stopAll();
        Serial.printf("Update: %s\n", upload.filename.c_str());
        uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
        if(!Update.begin(maxSketchSpace)){//start with max available size
          Update.printError(Serial);
        }
      } else if(upload.status == UPLOAD_FILE_WRITE){
        if(Update.write(upload.buf, upload.currentSize) != upload.currentSize){
          Update.printError(Serial);
        }
      } else if(upload.status == UPLOAD_FILE_END){
        if(Update.end(true)){ //true to set the size to the current progress
          Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
        } else {
          Update.printError(Serial);
        }
        Serial.setDebugOutput(false);
      }
      yield();
    });
    server.begin();
    MDNS.addService("http", "tcp", 80);
  
    Serial.printf("Ready! Open http://%s.local in your browser\n", host);
  } else {
    Serial.println("WiFi Failed");
  }
}
 
void loop(void){
  server.handleClient();
  delay(1);
} 


String webPage()
{
  String web; 
  web += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/> <meta charset=\"utf-8\"><title>WIFi-relay-9</title><style>button{color:red;padding: 10px 27px;}</style></head>";
  web += "<h1 style=\"text-align: center;font-family: Open sans;font-weight: 100;font-size: 20px;\">Управление релейным блоком - перед нажатием обнови!</h1><div>";
  
////////////////////////KNOPKA0///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin0) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 1 ВКЛ</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 1 ВЫК</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin0On\"><button>ON</button></a>&nbsp;<a href=\"ledPin0Off\"><button>OFF</button></a></div>";
 ////////////////////////KNOPKA1///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin1) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 2 ВКЛ</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 2 ВЫК</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin1On\"><button>ON</button></a>&nbsp;<a href=\"ledPin1Off\"><button>OFF</button></a></div>";
 ////////////////////////KNOPKA2///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin2) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 3 ВКЛ</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 3 ВЫК</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin2On\"><button>ON</button></a>&nbsp;<a href=\"ledPin2Off\"><button>OFF</button></a></div>";
 ////////////////////////KNOPKA3///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin3) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 1 ВЫК</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 1 ВКЛ</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin3Off\"><button>ON</button></a>&nbsp;<a href=\"ledPin3On\"><button>OFF</button></a></div>";
 ////////////////////////KNOPKA4///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin4) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 2 ВЫК</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 2 ВКЛ</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin4Off\"><button>ON</button></a>&nbsp;<a href=\"ledPin4On\"><button>OFF</button></a></div>";
 ////////////////////////KNOPKA5///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin5) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 6 ВКЛ</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 6 ВЫК</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin5On\"><button>ON</button></a>&nbsp;<a href=\"ledPin5Off\"><button>OFF</button></a></div>";
 ////////////////////////KNOPKA6///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin6) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 7 ВКЛ</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 7 ВЫК</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin6On\"><button>ON</button></a>&nbsp;<a href=\"ledPin6Off\"><button>OFF</button></a></div>";
 ////////////////////////KNOPKA7///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin7) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 8 ВКЛ</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 8 ВЫК</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin7On\"><button>ON</button></a>&nbsp;<a href=\"ledPin7Off\"><button>OFF</button></a></div>";
 ////////////////////////KNOPKA8///////ledPin0, ledPin1, ledPin2, ledPin3, ledPin4, ledPin5, ledPin6, ledPin7, ledPin8////////////////////////////////////////////////// 
  if (digitalRead(ledPin8) == 1)
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #43a209;margin: 0 auto;\">РЕЛЕ 9 ВКЛ</div>";
  }
  else 
  {
    web += "<div style=\"text-align: center;width: 98px;color:white ;padding: 10px 30px;background-color: #ec1212;margin: 0 auto;\">РЕЛЕ 9 ВЫК</div>";
  }
  web += "<div style=\"text-align: center;margin: 5px 0px;\"> <a href=\"ledPin8On\"><button>ON</button></a>&nbsp;<a href=\"ledPin8Off\"><button>OFF</button></a></div>";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 

 
  
  // ========REFRESH=============
  web += "<div style=\"text-align:center;margin-top: 20px;\"><a href=\"/\"><button style=\"width:158px;\">REFRESH</button></a></div>";
  // ========REFRESH=============
  
  
  web += "</div>";
  return(web);
}

