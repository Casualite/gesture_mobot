#include <WiFi.h>
#include <WebServer.h>


/*Put your SSID & Password*/
const char* ssid = " ";  // Enter SSID here
const char* password = " ";  //Enter Password here

WebServer server(80);             
 
void setup() {
  
  Serial.begin(115200);
  delay(100);
  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  
  Serial.println(WiFi.localIP());

  server.on("/asasasasa/", handle_OnConnect);

  server.on("/asasasasa/left", left);

  server.on("/asasasasa/right", right);

  server.on("/asasasasa/forward", forward);

  server.on("/asasasasa/backward", backward);

  server.on("/asasasasa/stop", halt);

  server.on("/asasasasa/open", isOpen);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}

void left() {
  server.send(200, "text/html", SendHTML()); 
}

void right() {
  server.send(200, "text/html", SendHTML()); 
}

void forward() {
  server.send(200, "text/html", SendHTML()); 
}

void backward() {
  server.send(200, "text/html", SendHTML()); 
}

void halt() {
  server.send(200, "text/html", SendHTML()); 
}

void isOpen() {
  server.send(200, "text/html", SendHTML()); 
}


void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n";
  ptr +="<title>IoT Gesture Bot</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>Enter /<command> on the URL, or contact Admin for WebRemote</h1>\n";
  ptr +="<p>Available Commands - left,  right,  forward,  stop,  backward, open </p>";
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
