#include "WL_IMU.h"

/*Sensors Setup*/
IMU imu;
unsigned long current_time = 0;
unsigned long previous_time = 0;
unsigned long previous_time_ble = 0;
unsigned long Delta_T1 = 1000;
unsigned long Delta_T2 = 20000;
unsigned long t_i, t_pr1, t_pr2;
double t;
double HZ = 1.0 / (Delta_T1 / 1000000.0);
double HZ2 = 1.0 / (Delta_T2 / 1000000.0);
void setup()
{
  delay(3000);
  Serial.begin(115200);
  Serial4.begin(115200);
  delay(100);
  CurrentControlSetup();
}

void loop()
{
  imu.READ();

  t_i = micros();
  t = t_i / 1000000.0;


  if (t_i - t_pr1 > Delta_T1) {
    t_pr1 = t_i;
    Serial.print(imu.LTx);
    Serial.print("  ");
    Serial.print(imu.RTx);
    Serial.print("  ");
    Serial.print(imu.LTAVx);
    Serial.print("  ");
    Serial.print(imu.RTAVx);
    Serial.println("  ");
  }

}



void CurrentControlSetup()
{
  imu.INIT();
  delay(500);
  imu.INIT_MEAN();
  current_time = micros();
  previous_time = current_time;
  previous_time_ble = current_time;
}
