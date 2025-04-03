#ifndef __TEMPLATE_VIEW_H
#define __TEMPLATE_VIEW_H

#include "../Page.h"

namespace Page {

class DesktopView {
   public:
    void Create(lv_obj_t* root);
    void Delete();

   public:
    struct {
    #if defined(M5CORES3)
        lv_obj_t* img_bg;
    #elif defined(M5CORES3SE)
        lv_obj_t* img_bg_se;
    #endif

        lv_obj_t* screen_tileview_1;
        lv_obj_t* screen_tileview_1_tile1;
        lv_obj_t* screen_tileview_1_tile2;

        lv_obj_t* imgbtn_list[9];
        
    } ui;

   private:
};

}  // namespace Page

#endif  // !__VIEW_H
