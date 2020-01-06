#pragma once

class Room {
public:
  Room(int number_, int type_, int capacity_) : number(number_), type(type_), capacity(capacity_) {}
  int getCapacity() {return capacity;}
private:
  int number;
  int type;
  int capacity;
};
