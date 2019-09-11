#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ifc_projeto";
const char *password = "SEPECARAIO";

ESP8266WebServer server(80);

const String HTTP_HEAD          = "<!DOCTYPE html><html lang=\"en\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/><title>{v}</title>";
const String HTTP_STYLE         = "<style>button { padding: 10px; margin-bottom: 10px; width: 100px;} li { list-style-type: none;} h1{ position: relative; top: -25%; text-align: left; padding-left: 2.5%;} .menu1 { position: relative; left: 0; top: 25%; width: 100%; text-align: left; padding-left: 40%;} .menu2 { position: relative; left: 0; top: 75%; width: 100%; text-align: left; padding-left: 40%;} body { position: relative; top: 50px; left: 0%;} .desliga { background-color: #800000; color: #f0f8ff;} .liga { background-color: #7fff00; color: #000000;} form {display: inline-block;}</style>";
const String HTTP_SCRIPT        = "<script>function c(l){document.getElementById('s').value=l.innerText||l.textContent;document.getElementById('p').focus();}</script>";
const String HTTP_HEAD_END      = "</head><body><div style='text-align:left;display:inline-block;min-width:260px;'>";

const String HOMEPAGE = "<nav class=\"menu1\"><h1>PISO 1</h1><ul><li>Sala:<li><ul><li><p>Lampada</p><form action=\"/cmd1\" method=\"get\"><button class=\"desliga\">Desligado</button></form><br/><form action=\"/cmd2\" method=\"get\"><button class=\"liga\">Liga</button></form><br/><li></ul><li>Cozinha:<li><ul><li><p>lampada</p> <form action=\"/cmd3\" method=\"get\"><button class=\"desliga\">Desliga</button></form><br/><form action=\"/cmd4\" method=\"get\"><button class=\"liga\">Liga</button></form><br/><li><li><p>Chaleira</p> <form action=\"/cmd5\" method=\"get\"><button class=\"desliga\">Desliga</button></form><br/> <form action=\"/cmd6\" method=\"get\"><button class=\"liga\">Liga</button></form><br/><li></ul></ul></nav><nav class=\"menu2\"<h1>PISO 2</h1> <ul><li><Quarto Casal:<li><ul><li><p>Lampada</p> <form action=\"/cmd7\" method=\"get\"><button class=\"desliga\">Desligado</button></form><br/> <form action=\"/cmd8\" method=\"get\"><button class=\"liga\">Liga</button></form><br/> <li></ul><li>Quanto Criancas:<li><ul><li><p>Lampada</p> <form action=\"/cmd9\" method=\"get\"><button class=\"desliga\">Desligado</button></form><br/> <form action=\"/cmd10\" method=\"get\"><button class=\"liga\">Liga</button></form><br/><li></ul></ul></nav>";







/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
 
}

void cmd1() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D7,LOW);
} 
void cmd2() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
    digitalWrite(D7,HIGH);
}
void cmd3() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D6,LOW);
}

void cmd4() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D6,HIGH);
}

void cmd5() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D5,LOW);
}

void cmd6() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D5,HIGH);
}

void cmd7() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D4,LOW);
}

void cmd8() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D4,HIGH);
}

void cmd9() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D3,LOW);
}

void cmd10() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D3,HIGH);
}


void setup() {
  delay(1000);
  pinMode(D7,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D3,OUTPUT);
 
    digitalWrite(D0,LOW);
    
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/cmd1", cmd1);
  server.on("/cmd2", cmd2);
  server.on("/cmd3", cmd3);
  server.on("/cmd4", cmd4);
  server.on("/cmd5", cmd5);
  server.on("/cmd6", cmd6);
  server.on("/cmd7", cmd7);
  server.on("/cmd8", cmd8);
  server.on("/cmd9", cmd9);
  server.on("/cmd10", cmd10);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
