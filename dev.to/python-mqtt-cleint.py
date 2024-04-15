import time
import json

from paho.mqtt import client as mqtt_client

# Set the broker and topic details
broker = 'localhost'
port = 1883
instructions_topic = "car/instructions"
sensors_topic = "car/sensors"
client_id = "python-mqtt-client"

def connect_mqtt():
    def on_connect(client, userdata, flags, error_code, properties=None):
        if error_code == 0:
            print("Connected")
        else:
            print("Failed to connect %d\n", error_code)

    client = mqtt_client.Client(client_id=client_id, callback_api_version=mqtt_client.CallbackAPIVersion.VERSION2)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client


def publish(client, msg: str):
    msg_count = 1
    while True:
        time.sleep(1)
        result = client.publish(instructions_topic, msg)
        status = result[0]
        if status == 0:
            print(f"Send `{msg}` to topic `{instructions_topic}`")
        else:
            print(f"Failed to send message to topic {instructions_topic}")
        msg_count += 1
        # if msg_count > 5:
        #     break


def run():
    client = connect_mqtt()
    client.loop_start()
    msg = {
        "direction": "forward", 
        "speed": 100
    }
    publish(client, json.dumps(msg))
    client.loop_stop()


if __name__ == '__main__':
    run()
