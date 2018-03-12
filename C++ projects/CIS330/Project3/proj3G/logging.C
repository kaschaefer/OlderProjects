#include <logging.h>
#include <cstring>
#include <iostream>

DataFlowException::DataFlowException(const char *type, const char *error) {
	if (type != nullptr && error != nullptr) {
		//Remember to add paranthesises//
		strcpy(msg, "Throwing exception: (");
		strcat(msg, type);
		strcat(msg, ")");
		strcat(msg, ": ");
		strcat(msg, error);
		Logger::LogEvent(msg);
	}
	else {
		std::cout << "Something went wrong. Either error type or error message was unitialized" << std::endl;
	}
};

FILE* Logger::logger = nullptr;

void Logger::LogEvent(const char *event){
	if (logger == nullptr){
		logger = fopen("log.txt", "w");
		if (logger == nullptr){
			std::cout << "The Log file failed to open" << std::endl;
			return;
		}
	}
	fprintf(logger, "%s\n", event);
};

void Logger::Finalize(){
	if (logger != nullptr){
		fclose(logger);
	}
};

