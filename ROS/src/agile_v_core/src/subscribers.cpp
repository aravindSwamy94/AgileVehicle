/*
 * Host-side communication interface between host and Single Wheel Driving Units.
 * This code is released under GPL-3.0 License.
 *
 * Author: Haoguang Yang
 * Mar 20, 2017
 *
 */
 
#include "subscribers.h"
#include "GUI.h"

ElectricStat ElectricMon[4];
bool IsInit[2][4]={false};

void readFromWheelsDrv00(const std_msgs::UInt16MultiArray& wheelData)
{
    if (IsInit[0][0] && IsInit[1][0]){
        Enc[0][0].update(Enc[0][0].getRes()-wheelData.data[0]);
        Enc[1][0].update_value(wheelData.data[1]);
    }
    else if (IsZeroCorrect[0])
    {
        encodersInit(0,0,wheelData.data[0]);
        encodersInit(1,0,wheelData.data[1]);
    }
    DrawWheel0(wheelData);
    return;
}

void readFromWheelsDrv01(const std_msgs::UInt16MultiArray& wheelData)
{
    if (IsInit[0][1] && IsInit[1][1]){
        Enc[0][1].update(Enc[0][1].getRes()-wheelData.data[0]);
        Enc[1][1].update_value(wheelData.data[1]);
    }
    else if (IsZeroCorrect[1])
    {
        encodersInit(0,1,wheelData.data[0]);
        encodersInit(1,1,wheelData.data[1]);
    }
    DrawWheel1(wheelData);
    return;
}

void readFromWheelsDrv02(const std_msgs::UInt16MultiArray& wheelData)
{
    if (IsInit[0][2] && IsInit[1][2]){
        Enc[0][2].update(Enc[0][2].getRes()-wheelData.data[0]);
        Enc[1][2].update_value(wheelData.data[1]);
    }
    else if (IsZeroCorrect[2])
    {
        encodersInit(0,2,wheelData.data[0]);
        encodersInit(1,2,wheelData.data[1]);
    }
    DrawWheel2(wheelData);
    return;
}

void readFromWheelsDrv03(const std_msgs::UInt16MultiArray& wheelData)
{
    if (IsInit[0][3] && IsInit[1][3]){
        Enc[0][3].update(Enc[0][3].getRes()-wheelData.data[0]);
        Enc[1][3].update_value(wheelData.data[1]);
    }
    else if (IsZeroCorrect[3])
    {
        encodersInit(0,3,wheelData.data[0]);
        encodersInit(1,3,wheelData.data[1]);
    }
    DrawWheel3(wheelData);
    return;
}

void encodersInit(int i, int j, uint16_t zero)
{
    Enc[i][j].setZero(zero);
    IsInit[i][j] = {true};
    return;
}

void readFromWheelsPwr00(const std_msgs::Float32MultiArray& powerData)
{
    ElectricMon[0]._volt = powerData.data[0];
	ElectricMon[0]._ampS = powerData.data[1];
	ElectricMon[0]._ampD = powerData.data[2];
	return;
}

void readFromWheelsPwr01(const std_msgs::Float32MultiArray& powerData)
{
    ElectricMon[1]._volt = powerData.data[0];
	ElectricMon[1]._ampS = powerData.data[1];
	ElectricMon[1]._ampD = powerData.data[2];
	return;
}

void readFromWheelsPwr02(const std_msgs::Float32MultiArray& powerData)
{
    ElectricMon[2]._volt = powerData.data[0];
	ElectricMon[2]._ampS = powerData.data[1];
	ElectricMon[2]._ampD = powerData.data[2];
	return;
}

void readFromWheelsPwr03(const std_msgs::Float32MultiArray& powerData)
{
    ElectricMon[3]._volt = powerData.data[0];
	ElectricMon[3]._ampS = powerData.data[1];
	ElectricMon[3]._ampD = powerData.data[2];
	return;
}

