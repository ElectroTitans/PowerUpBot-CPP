#include "WPILib.h"

#include "Robot.h"
#include "Commands/Drive/DriveJoystick.h"
#include "Commands/LiftBinary.h"
#include "Commands/Auto/Autonomous.h"
#include <memory>
#include "ctre\Phoenix.h"

std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Intake> Robot::intake;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<VictoryConnectClient> Robot::victoryConnect;


void Robot::RobotInit() {
	RoboMap::Init();

	std::cout << "ROBO IS DA STARTING" << std::endl;
	

	victoryConnect.reset(new VictoryConnectClient());
	drivetrain.reset(new Drivetrain());
	intake.reset(new Intake());
	
	oi.reset(new OI());

	RoboMap::navX->ZeroYaw();
	printf("Zeroed Yaw in init!\n");
	
	drivejoystick.reset(new DriveJoystick());
	autonomousCommand.reset(new Autonomous());

	//CameraServer::GetInstance()->StartAutomaticCapture();

	SmartDashboard::PutData(RoboMap::navX.get());

	VictoryInit();


}
void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	//Scheduler::GetInstance()->Run();

}

void Robot::AutonomousInit()
{
	std::cout << "ROBO IS DA STARTING DA AUTO" << std::endl;
	autonomousCommand->Start();
	
	
}

void Robot::AutonomousPeriodic()
{
	
	
	Scheduler::GetInstance()->Run();

}

void Robot::TeleopInit()
{

	RoboMap::navX->Reset();
	printf("Info: Reset NavX\n");

	drivejoystick->Start();

}



void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();

	Robot::victoryConnect->SendPacket(0, "navx", "connected :P;" + to_string(RoboMap::navX->GetFusedHeading()));
	//RoboMap::solenoidPlatform1->Set(DoubleSolenoid::kForward);
}

void Robot::TestInit()
{
}

void Robot::TestPeriodic()
{
}

void Robot::VictoryInit() {
	std::cout << "STARTING!" << std::endl;
	Robot::victoryConnect->Connect("pi4056.local");
	
}
void Robot::VictoryPeroidic()
{

	
}



START_ROBOT_CLASS(Robot)