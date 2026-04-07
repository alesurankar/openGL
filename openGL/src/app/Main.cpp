#include <utils/DebugLog.h>
#include <app/App.h>
#include <utils/MyException.h>
#include <memory>
#include <fstream>

int main()
{
    std::ofstream logFile("error_message.log", std::ios::app);
    LoggerScope logger("debug_log.log");
    try {
        return App{}.Run();
    }
    catch (const MyException& e) {
        if (logFile) {
            logFile << "[MyException] " << e.what() << std::endl;
            logFile.flush();
        }
    }
    catch (const std::exception& e) {
        if (logFile) {
            logFile << "[std::exception] " << e.what() << std::endl;
            logFile.flush();
        }
    }
    catch (...) {
        if (logFile) {
            logFile << "[Unknown Exception] Fatal error!" << std::endl;
            logFile.flush();
        }
    }
    return 0;
}