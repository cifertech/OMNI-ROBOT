#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <Hash.h>


const char* ssid = "OMNI BOT";
const char* password = "123456789";

char Data;

#define PIN  D2

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(4, 4, PIN,
                            NEO_MATRIX_BOTTOM  + NEO_MATRIX_LEFT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);


const uint16_t colors[] = {
  matrix.Color(255, 0, 0),
  matrix.Color(0, 255, 0),
  matrix.Color(0, 0, 255)
};

#define AIN1 D7
#define AIN2 D8

#define BIN1 D5
#define BIN2 D6

#define AIN3 D3
#define AIN4 D4


static const char PROGMEM INDEX_HTML[] = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width = device-width, initial-scale = 1.0, maximum-scale = 1.0, user-scalable=0">
    <title>OMNI BOT</title>
    <style>
      body {
        background-color: #343a40;
        font-family: Arial, Helvetica, Sans-Serif;
        Color: #000000;
      }

      #ab {
        color: black;
        padding: 15px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 15px;
        margin: 2px 50px 2px -50px;
        cursor: pointer;
        border-radius: 12px;
        width: 100%;
      }

      #JD {
        text-align: center;
      }

      #JD {
        text-align: center;
        font-family: "Lucida Sans Unicode", "Lucida Grande", sans-serif;
        font-size: 24px;
      }

      .foot {
        text-align: center;
        font-family: "Comic Sans MS", cursive;
        font-size: 30px;
        color: #F00;
      }

      .button {
        border: none;
        color: black;
        padding: 17px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 16px;
        margin: 4px 2px;
        cursor: pointer;
        border-radius: 12px;
        width: 100%;
      }

      .red {
        background-color: #f8f9fa;
      }

      .green {
        background-color: #f8f9fa;
      }

      .yellow {
        background-color: #f8f9fa;
      }

      .blue {
        background-color: #f8f9fa;
      }
    </style>
    <script>
      var websock;

      function start() {
        websock = new WebSocket('ws://' + window.location.hostname + ':81/');
        websock.onopen = function(evt) {
          console.log('websock open');
        };
        websock.onclose = function(evt) {
          console.log('websock close');
        };
        websock.onerror = function(evt) {
          console.log(evt);
        };
        websock.onmessage = function(evt) {
          console.log(evt);
          var e = document.getElementById('ledstatus');
          if (evt.data === 'ledon') {
            e.style.color = 'red';
          } else if (evt.data === 'ledoff') {
            e.style.color = 'black';
          } else {
            console.log('unknown event');
          }
        };
      }

      function buttonclick(e) {
        websock.send(e.id);
      }
    </script>
  </head>
  <body onload="javascript:start();">
    <table width="100" height="249" border="0" align="center">
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
        <td>&nbsp;</td>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="F" type="button" onclick="buttonclick(this);" class="button green">Forward</button>
            </label>
          </form>
        </td>
        <td>&nbsp;</td>
      </tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="L" type="button" onclick="buttonclick(this);" class="button green">Left</button>
            </label>
          </form>
        </td>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="S" type="button" onclick="buttonclick(this);" class="button red">Stop</button>
            </label>
          </form>
        </td>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="R" type="button" onclick="buttonclick(this);" class="button green">Right</button>
            </label>
          </form>
        </td>
      </tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
        <td>&nbsp;</td>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="B" type="button" onclick="buttonclick(this);" class="button green">Backward</button>
            </label>
          </form>
        </td>
        <td>&nbsp;</td>
      </tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="a" type="button" onclick="buttonclick(this);" class="button blue">Forward Right</button>
            </label>
          </form>
        </td>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="b" type="button" onclick="buttonclick(this);" class="button blue">Forward Left</button>
            </label>
          </form>
        </td>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="c" type="button" onclick="buttonclick(this);" class="button blue">Backward Right</button>
            </label>
          </form>
        </td>
        <td align="center" valign="middle">
          <form name="form1" method="post" action="">
            <label>
              <button id="d" type="button" onclick="buttonclick(this);" class="button blue">Backward Left</button>
            </label>
          </form>
        </td>
      </tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr>
      <tr></tr>
      <td align="center" valign="middle">
        <form name="form1" method="post" action="">
          <label>
            <button id="o" type="button" onclick="buttonclick(this);" class="button yellow">CCW</button>
          </label>
        </form>
      </td>
      <td align="center" valign="middle">
        <form name="form1" method="post" action=""> &nbsp; </form>
      </td>
      <td align="center" valign="middle">
        <form name="form1" method="post" action="">
          <label>
            <button id="f" type="button" onclick="buttonclick(this);" class="button yellow">CW</button>
          </label>
        </form>
      </td>
      </tr>
    </table>
    <p class="foot"></p>
  </body>
</html>
)rawliteral";

WebSocketsServer webSocket = WebSocketsServer(81);
ESP8266WebServer server(80);


void setup() {
  
  Serial.begin(9600);

  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(20);
  matrix.setTextColor(colors[0]);
  
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);

  pinMode(AIN3,OUTPUT);
  pinMode(AIN4,OUTPUT);

  WiFi.mode(WIFI_AP);          
  WiFi.softAP(ssid, password);  

  IPAddress myIP = WiFi.softAPIP(); 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");   
  Serial.println(myIP);

  server.on("/", [](){
  server.send(200, "text/html", INDEX_HTML);
  });
  
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  
}

int x    = matrix.width();
int pass = 0;

void loop() {
  
   matrix.fillScreen(0);
   matrix.setCursor(x, 0);
   
     if(Data=='a')fl();
else if(Data=='b')fr();
else if(Data=='c')br();
else if(Data=='d')bl();
else if(Data=='o')ccw();
else if(Data=='f')cw(); 
else if(Data=='F')forword();
else if(Data=='B')backword();
else if(Data=='R')right();
else if(Data=='L')left();
else if(Data=='S')stop();

   
   webSocket.loop();
   server.handleClient();

}


void webSocketEvent(uint8_t num, WStype_t type,uint8_t * Payload, size_t length){
  switch(type) {
    case WStype_DISCONNECTED:
      //Serial.printf("[%u] Disconnected!\r\n", num);
      break;
    case WStype_CONNECTED:
      {IPAddress ip = webSocket.remoteIP(num);}
      break;
    case WStype_TEXT:
      //Serial.printf("%s\r\n", Payload);
      Data = Payload[0];
      Serial.println(Data);
      // send data to all connected clients
      webSocket.broadcastTXT(Payload, length);
     
      break;
    case WStype_BIN:
      hexdump(Payload, length);
      // echo data back to browser
      webSocket.sendBIN(num, Payload, length);
      break;
      default:
      break;
  }
}

void face1() {

    matrix.fillScreen(0);
    matrix.setCursor(x, -1);
    
    matrix.print(F("-----------"));
  
    if(--x < -36) {
      x = matrix.width();
      if(++pass >= 3) pass = 0;
      matrix.setTextColor(matrix.Color(255, 0, 255));
    }
   
    matrix.show();
    delay(100);
}

void face2() {

    matrix.fillScreen(0);
    matrix.setCursor(x, 1);
    
    matrix.print(F("^^^^^^^^^"));
  
    if(--x < -36) {
      x = matrix.width();
      if(++pass >= 3) pass = 0;
      matrix.setTextColor(matrix.Color(255, 0, 255));
    }
   
    matrix.show();
    delay(100);
}

void stop() {

  face1();

  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,LOW);
  
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);
  
  digitalWrite(AIN3,LOW); 
  digitalWrite(AIN4,LOW);

}

void backword() {
  
  face2();

  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,HIGH);
  
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
  
  digitalWrite(AIN3,LOW); 
  digitalWrite(AIN4,LOW);
   
}

void forword() {

  face2();

  digitalWrite(AIN1,HIGH); 
  digitalWrite(AIN2,LOW);
  
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);
  
  digitalWrite(AIN3,LOW); 
  digitalWrite(AIN4,LOW);
  
}

void left() {

  face2();

  digitalWrite(AIN1,HIGH); 
  digitalWrite(AIN2,LOW);
  
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
  
  digitalWrite(AIN3,HIGH); 
  digitalWrite(AIN4,LOW);

}

void right() {

  face2();

  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,HIGH);
  
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);
  
  digitalWrite(AIN3,LOW); 
  digitalWrite(AIN4,HIGH);

}

void cw() {

  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,HIGH);
  
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);
  
  digitalWrite(AIN3,HIGH); 
  digitalWrite(AIN4,LOW);

}

void ccw() {

  digitalWrite(AIN1,HIGH); 
  digitalWrite(AIN2,LOW);
  
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
  
  digitalWrite(AIN3,LOW); 
  digitalWrite(AIN4,HIGH);

}

void br() {

  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,HIGH);
  
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);
  
  digitalWrite(AIN3,LOW); 
  digitalWrite(AIN4,HIGH);

}

void fl() {

  digitalWrite(AIN1,HIGH); 
  digitalWrite(AIN2,LOW);
  
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);
  
  digitalWrite(AIN3,HIGH); 
  digitalWrite(AIN4,LOW);

}

void bl() {

  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,LOW);
  
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
  
  digitalWrite(AIN3,HIGH); 
  digitalWrite(AIN4,LOW);

}

void fr() {

  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,LOW);
  
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);
  
  digitalWrite(AIN3,LOW); 
  digitalWrite(AIN4,HIGH);

}
