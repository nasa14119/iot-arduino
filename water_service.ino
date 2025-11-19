#ifndef WATERSERVICE_H
#define WATERSERVICE_H
const int PINS[] = {2, 3, 4, 5}; 
class WaterService{
public: 
  WaterService(){}; 
  static constexpr int size = 4; 
  std::array<bool, size> get_sensors(){
    std::array<bool, size> data = {true, true, true, true}; 
    return data; 
    // bool data[size]; 
    // for(int i = 0; i < size; i++)data[i] = digitalRead(PINS[i]); 
    // return data; 
  }
  bool isEmpty(){
    return false; 
    // bool * data = get_sensors(); 
    // for (int i = 0; i < size; i++) if(data[i]) return false; 
    // return true; 
  }
  
}; 
#endif
