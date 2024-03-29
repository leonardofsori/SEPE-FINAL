#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "ifc_projeto";
const char *password = "12345";

ESP8266WebServer server(80);

const String HTML_CABECALHO = "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/><title>{v}</title>";
const String HTML_CSS = "<style>button { padding: 10px; margin-bottom: 10px; width: 100px;} li { list-style-type: none;} h1{ position: relative; top: -25%; text-align: left; padding-left: 2.5%;} .menu1 { position: absolute; left: 10%; top: 25%; width: 100%; text-align: left; } .menu2 { position: absolute; left: 60%; top: 75%; width: 100%; text-align: left; margin: auto;} body { position: relative; top: 50px; left: 0%; } .desliga { background-color: #800000; color: #f0f8ff;} .liga { background-color: #7fff00; color: #000000;} form {display: inline-block;} .linha-vertical {height: 500px; border-left: 2px solid; position: absolute; left: 50%;} </style>";
const String HTML_JAVA = "<script>function c(l){document.getElementById('s').value=l.innerText||l.textContent;document.getElementById('p').focus();}</script>";
const String HTML_FIM_CABECALHO = "</head><body><div style='text-align:left;display:inline-block;min-width:260px;'>";
const String HOMEPAGE = "<nav class=\"menu1\"><h1>PISO 1</h1><ul><li>Sala:<li><ul><li><p>Lâmpada</p><form action=\"/cmd1\" method=\"get\"><button class=\"desliga\">Desligado</button></form><br/><form action=\"/cmd2\" method=\"get\"><button class=\"liga\">Liga</button></form><br/><li></ul><li>Cozinha:<li><ul><li><p>lâmpada</p> <form action=\"/cmd3\" method=\"get\"><button class=\"desliga\">Desliga</button></form><br/><form action=\"/cmd4\" method=\"get\"><button class=\"liga\">Liga</button></form><br/><li><li><p>Chaleira</p> <form action=\"/cmd5\" method=\"get\"><button class=\"desliga\">Desliga</button></form><br/> <form action=\"/cmd6\" method=\"get\"><button class=\"liga\">Liga</button></form><br/><li></ul></ul></nav><nav class=\"menu2\"><h1>PISO 2</h1><ul><li>Quarto Casal:<li><ul><li><p>Lâmpada</p><form action=\"/cmd7\" method=\"get\"><button class=\"desliga\">Desligado</button></form><br/> <form action=\"/cmd8\" method=\"get\"><button class=\"liga\">Liga</button></form><br/> <li></ul><li>Banheiro:<li><ul><li><p>Lâmpada</p> <form action=\"/cmd9\" method=\"get\"><button class=\"desliga\">Desligado</button></form><br/> <form action=\"/cmd10\" method=\"get\"><button class=\"liga\">Liga</button></form><br/><li></ul></ul></nav>";







/* Para acessar o site, acessar http://192.168.4.1 */
void handleRoot() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
 
}

void cmd1() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D7,LOW);
} 
void cmd2() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
    digitalWrite(D7,HIGH);
}
void cmd3() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D6,LOW);
}

void cmd4() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D6,HIGH);
}

void cmd5() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D5,LOW);
}

void cmd6() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D5,HIGH);
}

void cmd7() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D4,LOW);
}

void cmd8() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D4,HIGH);
}

void cmd9() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D3,LOW);
}

void cmd10() {
 String s =HTML_CABECALHO;
       s += HTML_CSS;
      s += HTML_JAVA;  
      s += HTML_FIM_CABECALHO;
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
  Serial.print("Configurando ponto de acesso...");
 
  WiFi.softAP(ssid, password); /* Para deixar aberto para o publico, apagar o password*/

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Endereço IP: ");
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
  Serial.println("Servidor iniciado");
}

void loop() {
  server.handleClient();
}
