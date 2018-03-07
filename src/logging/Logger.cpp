#include "Logger.h"

void Logger::SetClass(string className){
    m_className = className;
}

void Logger::Info(string functionName, string toLog){
    cout << termcolor::bold << termcolor::cyan << "[ INFO  ] " << termcolor::reset;
    cout << termcolor::magenta << "0/0/2000 22:56:12 " << termcolor::reset;
    cout << "[" << termcolor::dark << m_className << termcolor::reset;
    cout << termcolor::cyan << " (" << functionName << ")"  << termcolor::white << "] ";
    cout << toLog << endl;

	Robot::victoryConnect->SendPacket(0, "log_info", functionName + " " + toLog + " " );
}

void Logger::Warning(string functionName, string toLog){
    cout << termcolor::bold << termcolor::yellow << "[WARNING] " << termcolor::reset;
    cout << termcolor::magenta << "0/0/2000 22:56:12 " << termcolor::reset;
    cout << "[" << termcolor::dark << m_className << termcolor::reset;
    cout << termcolor::cyan << " (" << functionName << ")"  << termcolor::white << "] ";
    cout << termcolor::yellow << toLog << termcolor::reset << endl;
	Robot::victoryConnect->SendPacket(0, "log_warning", functionName + " " + toLog + " ");

}

void Logger::Error(string functionName, string toLog){
    cout <<  termcolor::bold << termcolor::red << "[ ERROR ] " << termcolor::reset;
    cout << termcolor::magenta << "0/0/2000 22:56:12 " << termcolor::reset;
    cout << "[" << termcolor::dark << m_className << termcolor::reset;
    cout << termcolor::cyan << " (" << functionName << ")"  << termcolor::white << "] ";
    cout << termcolor::red << toLog << termcolor::reset << endl;

	Robot::victoryConnect->SendPacket(0, "log_error", functionName + " " + toLog + " ");
}

void Logger::Success(string functionName, string toLog){
    cout <<  termcolor::bold << termcolor::green << "[SUCCESS] " << termcolor::reset;
    cout << termcolor::magenta << "0/0/2000 22:56:12 " << termcolor::reset;
    cout << "[" << termcolor::dark << m_className << termcolor::reset;
    cout << termcolor::cyan << " (" << functionName << ")"  << termcolor::white << "] ";
    cout << termcolor::green << toLog << termcolor::reset << endl;
	Robot::victoryConnect->SendPacket(0, "log_success", functionName + " " + toLog + " ");
}