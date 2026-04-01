#ifndef MEGAPHONE_H
#define MEGAPHONE_H

#include <string>

class Megaphone {
  private:
    std::string msg;

  public:
    Megaphone();
    Megaphone(std::string str);
    void showMsg() const;
    ~Megaphone();
};

#endif