#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <BlynkSimpleEsp8266.h>

ESP8266 Server WebServer (80);
String webpage = "<H1> Belajar <H1> <p> <a href=\"on\"> <button> di </button> </a> & nbsp & nbsp; <a href=\"off\"> <button > mati </button> </a> </p> & nbsp & nbsp; ";
char auth [] = "masukan kode token anda";
char ssid [] = "nama hospot";
char pass [] = "sandi hospot";
batal penyiapan () {
  // letakkan kode penyiapan Anda di sini, untuk dijalankan sekali:
 Serial.begin (9600);
 Serial.println ();
 pinMode (D5, OUTPUT);
 WiFi.begin ("nama hospot", "sandi hospot");
 Blynk.begin (auth, ssid, pass);

 Serial.print ("Terhubung");
 sementara (WiFi.status ()! = WL_CONNECTED)
 {
  penundaan (500);
  Serial.print (".");
 }
  Serial.println ();
  Serial.print ("Terhubung, alamat IP:");
  Serial.println (WiFi.localIP ());

    server.on ("/ off", [] () {
    server.send (200, "text / html", halaman web);
    digitalWrite (D5, TINGGI);
});
    server.on ("/ on", [] () {
    server.send (200, "text / html", halaman web);
    digitalWrite (D5, LOW);
});
server.begin ();
}

void loop () {
  Blynk.run ();
  server.handleClient ();
}
