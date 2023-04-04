const int BUFFER_SIZE = 50;
char buf[BUFFER_SIZE];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    //int in_data_size = Serial.readBytes(buf, BUFFER_SIZE);
    uint8_t in_data = Serial.read();
    //int in_data = Serial.parseInt();
    //Serial.println(in_data);
    //Serial.print(in_data);
    //Serial.println(buf);

    int pb0 = bitRead(in_data, 0);
    int pb1 = bitRead(in_data, 1);
    int pb2 = bitRead(in_data, 2);
    int power = bitRead(in_data, 3);
    Serial.println();
    Serial.print(pb0);
    Serial.print(pb1);
    Serial.print(pb2);
    Serial.print(power);

  }

}
