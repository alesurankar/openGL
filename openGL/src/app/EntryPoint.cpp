#include <app/App.h>
#include <utils/MyException.h>
#include <iostream>
#include <fstream>

int main()
{
    std::ofstream logFile("error_message.log", std::ios::app);

    try {
        App app;
        return app.Run();
    }
    catch (const MyException& e) {
        std::cerr << e.what() << std::endl; 
        if (logFile.is_open()) {
            logFile << "[MyException] " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
        if (logFile.is_open()) {
            logFile << "[std::exception] " << e.what() << std::endl;
        }
    }
    catch (...) {
        std::cerr << "Fatal unknown error!" << std::endl;
        if (logFile.is_open()) {
            logFile << "[Unknown Exception] Fatal error!" << std::endl;
        }
    }
    std::cerr << "Press Enter to exit..." << std::endl;
    std::cin.get();
    return -1;
}