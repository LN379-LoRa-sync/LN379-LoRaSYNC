#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
int tri=D0;
int echo=D1;
int T,D;
// Update these with values suitable for your network.
const char* ssid = "Wifi_Name";//Enter the name of hotspot
const char* password = "Password";//Enter the password of your hotspot
const char* mqtt_server = "abc.def.ghi.jkl";//Enter the server address

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[200];
int value = 0;

//Setup of wifi
void setup_wifi() 
{
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  // print the incoming message
  for (int i = 0; i < length; i++)
   {
   	Serial.print((char)payload[i]);
   }
  Serial.println();//Incoming message from subscribed topic is printed here
  payload[length] = '\0';
  String msg = String((char*)payload);
  Serial.println(msg);
  /* put your message-processing code here: */
}

// do not change this method
void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    //if (client.connect(clientId.c_str())) {
    if (client.connect(clientId.c_str(), "mqtttest", 0, false, "lwt message from nodemcu"))
    {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      //  client.subscribe("tankdata/<mishra>");
      client.subscribe("motor/<mishra>");
    } 
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

// for ultra sonic sensor
void ultra()
{


    digitalWrite(tri,LOW);
    delayMicroseconds(2);
    digitalWrite(tri,HIGH);
    delayMicroseconds(5);
    digitalWrite(tri,LOW);
    
    T=pulseIn(echo,HIGH);
    D=(T*0.034)/2;
    Serial.print("Distance:");
    Serial.println(D);

  client.loop();
  String msg = "";
  msg = msg + "{\"id\":\"4567\",\"name\":\"esp82666\",\"water_level\":";//Writing data in JSON  format
  msg = msg + String(D) + "}";
  Serial.println(msg);
  client.publish("lorasync",msg.c_str());// Publishing the data in JSON format to mqtt topic "lorasync"
 
  delay(5000);

}

//Microcontroller(ESP8266 setup)
void setup()
{
  Serial.begin(115200);
  Serial.println();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(tri,OUTPUT);
  pinMode(echo,INPUT);
 }

//Main loop of program
void loop() 
{
  if (!client.connected()) {reconnect();}
  client.loop();
  ultra();
}