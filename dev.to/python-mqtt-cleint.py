import time
import json

from paho.mqtt import client as mqtt_client
import paho.mqtt.client as mqtt_client
import json
import time

class MQTTClient:
    def __init__(self, broker='localhost', port=1883, client_id='python-mqtt-client'):
        self.broker = broker
        self.port = port
        self.client_id = client_id
        self.instructions_topic = "car/instructions"
        self.sensors_topic = "car/sensors"
        self.client = self.connect()

    def connect(self):
        client = mqtt_client.Client(client_id=self.client_id, 
                                    callback_api_version=mqtt_client.CallbackAPIVersion.VERSION2)
        client.on_connect = self.on_connect
        client.connect(self.broker, self.port)
        return client

    def on_connect(self, client, userdata, flags, error_code, properties=None):
        if error_code == 0:
            print("Connected")
        else:
            print(f"Failed to connect {error_code}")

    def publish(self, msg):
        msg_count = 1
        while True:
            time.sleep(1)
            result = self.client.publish(self.instructions_topic, msg)
            status = result[0]
            if status == 0:
                print(f"Sent `{msg}` to topic `{self.instructions_topic}`")
            else:
                print(f"Failed to send message to topic {self.instructions_topic}")
            msg_count += 1

    def run(self):
        self.client.loop_start()
        msg = {
            "direction": "forward",
            "speed": 100
        }
        self.publish(json.dumps(msg))
        self.client.loop_stop()


if __name__ == '__main__':
    mqtt_client = MQTTClient()
    mqtt_client.run()

