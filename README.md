# LoRaSYNC
This is repository for our team lora sync. We will be writing all codes here.
This project has 5 main folders:
a. Physical layer//We have two option to get thus data either by installing our sensors or we can use pre installed govt datat using VSAT communication.
b. Middle layer
c. User layer
d.PPT
e.Research 

Physical Lyer
1. Embedded code for ESP8266 to measure water level using sensor(we will using existing radar system) and publish data(In JSON format) to topic "lorasync".
2. Embedded code for ESP8266 to trigger the Siren as soon message is received from subscribed topic.
3. Tipping rain gauge meter connecting with microcontroller to get rain data and enhance our model performance and it directly to nodered in Json format.
4. Flow meter to measure the flow rate of water and making it automated using Lora module or mqtt protocol. It can help us to know by what time we will get the released water in cascading of dam.
5. We will be asking All whether station to get their data from database directly in nodered
6. We will be also collectiong data of water in upstream and downstream using database of govt.

Middle Layer
1. Nodered code in JSON  format. It usually collects data from MQTT broker, analyse it ,process it and sends to database.It also directly get connected to databases to get the data and loralodule to send data directly to nodered,
2. SQL quries for ceation of databases and tables. Feeding data to these tables.
3. Nodered screenshot.

User layer
1. Grafana dashboard screenshot.
2. Visualization code in form of grafana.
3. Alert via call,SMS,telegram,twitter,whatsapp, emails.
4. Siren using lora techlonology.


