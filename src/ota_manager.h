#pragma once

class OtaManager {
 public:
  void begin(const char *hostname);
  void handle();
  bool isUpdating() const;

 private:
  bool updating_ = false;
};
