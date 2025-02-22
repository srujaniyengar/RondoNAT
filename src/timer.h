#ifndef TIMER_H
#define TIMER_H

extern bool buttonPressed;
extern bool timerRunning;
extern unsigned long startTime;
extern int totalSeconds;
extern int timerMinutes;

void handleButtonPress();
void startTimer();
void checkTimer();
void abortTimer();

#endif  // TIMER_H
