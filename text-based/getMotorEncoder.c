#pragma config(StandardModel, "Clawbot IQ")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float encodedMotor;
float rotationUnit;

float getMotorEncoderThenReturn()
{
	setMultipleMotors(50, leftMotor, rightMotor, noMotor, noMotor);
	waitUntil (getMotorEncoder(leftMotor) >= 360);
	stopAllMotors();
	encodedMotor = getMotorEncoder(leftMotor);

	
	return encodedMotor;
}

void calculateDistanceThenDisplay()
{
	float tempDiv = getMotorEncoderThenReturn()/360;
	rotationUnit = tempDiv;
	displayVariableValues(line1, rotationUnit);
	wait(5, seconds);
	
}

task main()
{
getMotorEncoderThenReturn();
calculateDistanceThenDisplay();
}
