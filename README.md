# LoRaSYNC
This is repository for our team lora sync. We will be writing all codes here.
This project has 3 main folders:
a. Physical layer
b. Middle layer
c. User layer

Physical Lyer
1. Embedded code for ESP8266 to measure water level using sensor and publish data(In JSON format) to topic "lorasync".
2. Embedded code for ESP8266 to trigger the Siren as soon message is received from subscribed topic.

Middle Layer
1. Nodered code in JSON  format. It usually collects data from MQTT broker, analyse it ,process it and sends to database.
2. SQL quries//Will be writing soon

User layer
1. Visualization code in form of grafana.
