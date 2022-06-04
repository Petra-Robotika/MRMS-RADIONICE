#pragma once
#include "helper.h"

void RobotLine::radionica() {
  static bool lopta;
  if (setup()) {
    lopta = false;
    armOpen();
    go(70, 70);
    delayMs(2500);
    go(70, -70);
    delayMs(700);
  }
  if (lopta == false){
    if (lineAny()){
      if ((line(0) and line(8)) or (line(4) and line(8)) or (line(0) and line(4))){
        catchBall();
        lopta = true;
      }
      else{
        lineFollow();
      }
    }
    else {
      wallFollowLeft();
      wallFollowRight();
    }
  }
  else{
    if (lineAny()){
      if (line(0) and line(8)){
        stop();
        delay(50);
        armDrop();
        delayMs(500);
        lopta = false;
        stop();
        end();
      }
      else{
        lineFollow();
      }
    }
    else {
      wallFollowLeftCarry();
      wallFollowRightCarry();
    }
  }

}


void RobotLine::wallFollowRight() {
  // Praćenje zida s desne strane
  if (frontRight() < 200)
  {
    if (front() < 130) {
      go(-70, 70);        // Skretanje u lijevu stranu
      delayMs(700);
    }
    if (frontRight() < 100) {
      go(30, 70);
    }
    else
      go(70, 30);
  }
  else
    go(60, 60);
}

void RobotLine::wallFollowLeft() {
  // Praćenje zida s lijeve strane
  if (frontLeft() < 200)
  {
    if (front() < 130) {
      go(-70, 70);        // Skretanje u desnu stranu
      delayMs(700);
    }
    if (frontLeft() < 100) {
      go(70, 30);
    }
    else
      go(30, 70);
  }
  else
    go(60, 60);
}

void RobotLine::catchBall() {
  // Rutina za hvatanje lopte
  stop();
  delayMs(50);
  armCatchReady();        // Priprema grippera za hvatanje

  go(70, -70);
  delayMs(700);
  
  go(40, 40);             // Polako prilaženje loptici
  delayMs(2000);
  go(20, 20);
  delayMs(1000);

  armCatch();             // Hvatanje loptice
  stop();
  delayMs(350);
  armCarry();
  delayMs(150);
  go(-50, -50);           // Izlazak iz zone čuvanja loptice vožnjom unazad
  delayMs(2500);
  stop();
  delayMs(50);

  go(70, -70);            // Okretanje u mjestu za 180°
  delayMs(800);
  stop();
  delayMs(50);

  go(70, 70);             // Prelazak raskrižja
  delayMs(500);
}


/*
        OVAJ DIO MORAJU SAMI NAPRAVITI
*/
void RobotLine::wallFollowRightCarry() {
  // Praćenje zida s desne strane nakon hvatanja lopte
  if (frontRight() < 350)
  {
    if (front() < 130) {
      go(-70, 70);        // Skretanje u lijevu stranu
      delayMs(600);
    }
    if (frontRight() < 300) {
      go(30, 70);
    }
    else
      go(70, 30);
  }
}

void RobotLine::wallFollowLeftCarry() {
  // Praćenje zida s lijeve strane nakon hvatanja lopte
  if (frontLeft() < 350)
  {
    if (front() < 130) {
      go(-70, 70);        // Skretanje u lijevu stranu
      delayMs(600);
    }
    if (frontLeft() < 300) {
      go(70, 30);
    }
    else
      go(30, 70);
  }
  else 
    go(30, 70);
}
