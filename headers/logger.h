//
// Created by Karl Menzel on 10/25/25.
//

#ifndef LOGGER_H
#define LOGGER_H

enum LOG_LEVEL {
  DEBUG,
  INFO,
  ERROR
};

void log_debugi(char* logMessage, int substitution);
void log_infoi(char* logMessage, int substitution);
void log_errori(char* logMessage, int substitution);

void log_debugs(char* logMessage, char* substitution);
void log_infos(char* logMessage, char* substitution);
void log_errors(char* logMessage, char* substitution);

void log_debug(char* logMessage);
void log_info(char* logMessage);
void log_error(char* logMessage);

#endif //LOGGER_H
