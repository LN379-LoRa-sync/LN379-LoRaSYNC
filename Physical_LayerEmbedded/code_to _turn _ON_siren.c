#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid = "Wifi_Name";//Enter the wifi name
const char* password = "Wifi_Password";//enter the wifi password
const char* mqtt_server = "Server Address";//enter the server address

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
  for (int i = 0; i < length; i++) {Serial.print((char)payload[i]);}
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  
  /*if((char)payload[0] == '1') 
  {
    digitalWrite(D6, HIGH);   // Turn the LED on (Note that LOW is the voltage level
   
  }
  else 
  {
    digitalWrite(D6, LOW);  // Turn the LED off by making the voltage HIGH
  }*/
  

  payload[length] = '\0';
  String msg = String((char*)payload);
  Serial.println(msg);
  if(strcmp(((char *)payload), "ON") == 0)
  {digitalWrite(D6, HIGH);}
  else{digitalWrite(D6, LOW); }
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
    //if (client.connect(clientId.c_str())) 
        {
	if (client.connect(clientId.c_str(), "mqtttest", 0, false, "lwt message from nodemcu"))
                {
      	Serial.println("connected");
      	// Once connected, publish an announcement...
     	client.publish("outTopic", "hello world");
      	// ... and resubscribe
      	client.subscribe("siren");
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
}
void setup(
{
  pinMode(D6,OUTPUT);
  Serial.begin(115200);
  Serial.println();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  /* put your set-up code here: */
}

void loop() 
{
  if (!client.connected()) {reconnect();}
  client.loop();
  client.publish("hello", "hi from NodeMCU");
  delay(3000);
}
