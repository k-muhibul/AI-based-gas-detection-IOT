# AI-based-gas-detection-IOT
Artificially intelligent flammable gas detection system. Implemented with arduino and and PHP webserver. 

The system is connected to the web server that has been developed using PHP. The system also uses KNN classifier to detect the severity of the gas concentration in a room. If any hazard is detected then the system notifies user via SMS and this has been done using the teleSign API. It also uses firebase real time database to store severity data for future AI training.

