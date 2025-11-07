#include <stdlib.h>
#include <stdio.h>

#include "logger.h"

enum LOG_LEVEL currentLogLevel = INFO;

void log_debugi(char* logMessage, int substitution) {
    char* formattedMessage = malloc(sizeof(logMessage) + sizeof(substitution) + 10);
    sprintf(formattedMessage, logMessage, substitution);
    log_debug(formattedMessage);
}

void log_infoi(char* logMessage, int substitution) {
    char* formattedMessage = malloc(sizeof(logMessage) + sizeof(substitution) + 10);
    sprintf(formattedMessage, logMessage, substitution);
    log_info(formattedMessage);
}

void log_errori(char* logMessage, int substitution) {
    char* formattedMessage = malloc(sizeof(logMessage) + sizeof(substitution) + 30);
    sprintf(formattedMessage, logMessage, substitution);
    log_error(formattedMessage);
}

void log_debugs(char* logMessage, char* substitution) {
    char* formattedMessage = malloc(sizeof(logMessage) + sizeof(substitution) + 10);
    sprintf(formattedMessage, logMessage, substitution);
    log_debug(formattedMessage);
}

void log_infos(char* logMessage, char* substitution) {
    char* formattedMessage = malloc(sizeof(logMessage) + sizeof(substitution) + 10);
    sprintf(formattedMessage, logMessage, substitution);
    log_info(formattedMessage);
}

void log_errors(char* logMessage, char* substitution) {
    char* formattedMessage = malloc(sizeof(logMessage) + sizeof(substitution) + 30);
    sprintf(formattedMessage, logMessage, substitution);
    log_error(formattedMessage);
}

void log_debug(char* logMessage) {
    if (currentLogLevel <= DEBUG){
      printf("[DEBUG]\t%s\n", logMessage);
    }
}

void log_info(char* logMessage){
    if (currentLogLevel <= INFO){
        printf("[INFO]\t%s\n", logMessage);
    }
}

void log_error(char* logMessage){
    if (currentLogLevel <= ERROR){
        printf("\x1b[31m[ERROR]\t%s\x1b[0m\n", logMessage);
    }
}