# LoRaSYNC
This is repository for our team lora sync. We will be writing all codes here.
This project gas 3 main folders:
a. Physical layer
b. middle layer
c. user layer

Physical Lyer
1. Embedded code for ESP8266 to measure water level using sensor and publish data(In JSON format) to topic "lorasync".
2. Embedded code for ESP8266 to trigger the Siren as soon msg received from subscribed topic.

Middle Layer
1. Nodered code in JSON  format. It usually collects data from MQTT broker, analyse it ,process it and sends to database.
2. SQL quries//Will be writing soon

User layer
1. Visualizational code in form of gtrafan
