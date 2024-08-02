#include <Arduino.h>
#include <Drone.h>

// declaring the main helper
Drone drone;

void setup()
{
  // drone setup
  Serial.begin(9600);
  drone.Initialize_Drone();
  if (drone.Calibrated)
  {
    drone.Calibrate_Drone();
  }
}

void loop()
{
  drone.GetMPU6050Data();
  // Serial.print("Accel X: ");
  // Serial.println(drone.getDroneAccelX());
  // Serial.print("Accel Y: ");
  // Serial.println(drone.getDroneAccelY());
  // Serial.print("Accel Z: ");
  // Serial.println(drone.getDroneAccelZ());
  // Serial.print("Gyro X: ");
  // Serial.println(drone.getDroneGyroX());
  // Serial.print("Gyro Y: ");
  // Serial.println(drone.getDroneGyroY());
  // Serial.print("Gyro Z: ");
  // Serial.println(drone.getDroneGyroZ());

  // //debug mode
  // for (auto channel : drone.Receiver_Values)
  // {
  //   Serial.println(channel);
  // }
  Serial.print("Ambient Temperature: ");
  Serial.println(drone.getAmbientTemperature());
  Serial.print("Altitude: ");
  Serial.println(drone.getDroneAltitude());
  delay(1000);
}
