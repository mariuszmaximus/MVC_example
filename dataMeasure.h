#pragma once

#include <vector>
#include <string>
#include <fmt/core.h>
#include "CImg.h"


#include <qmetatype.h>      // Q_DECLARE_METATYPE
class MData
{

};

Q_DECLARE_METATYPE(MData)

struct Measure
{
  int id{0};
  std::string time{"2023-01-01 11:11"};
  std::string name{"Kowalski"};
  std::string image{"image.bmp"};
  bool checked{false};
  std::string desc;
};

class DataMeasure
{
private:
  std::vector<Measure> m_data;

  void generateImages(int count)
  {
    auto saveImage=[](int id){

      int w{64};
      int h{64};

      float raw_fg_col = 999;
      float raw_bg_col = 0;
      std::string str=fmt::format("{}",id);
      typedef cimg_library::CImg <uint8_t> im_float_type;

      im_float_type img;
      img.resize(w,h);
      img.rand(0,128);

      img.draw_text(0,0,str.c_str(),&raw_fg_col,&raw_bg_col, 1, 32); 
      img.save_bmp(fmt::format("image{}.bmp", id).c_str() );
    };

    for(int i =0; i< count; ++i)
      saveImage(i);    
  } 

public:
  DataMeasure()
  {
    int count{100};
    for (int i = 0; i < count; ++i)
    {
      m_data.emplace_back();
      m_data.back().name = fmt::format("Name{}", i);
      m_data.back().time = fmt::format("2023-01-{:02} {:02}:{:02}", i % 31, i % 24, i % 60);
      m_data.back().checked = (i % 2);
      m_data.back().image = fmt::format("image{}.bmp", i); 
    }
    generateImages(count);
  }

  int size() { return m_data.size(); };

  Measure &getMeasure(size_t idx)
  {
    return m_data[idx];
  }

  void del(int32_t id)
  {
    m_data.erase(m_data.begin());;
  }
};