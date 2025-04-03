#ifndef __TEMPLATE_PRESENTER_H
#define __TEMPLATE_PRESENTER_H

#include "DesktopView.h"
#include "DesktopModel.h"

namespace Page {

class Desktop : public PageBase {
   public:
    typedef struct {
        uint16_t time;
        lv_color_t color;
    } Param_t;

   public:
   Desktop();
    virtual ~Desktop();

    virtual void onCustomAttrConfig();
    virtual void onViewLoad();
    virtual void onViewDidLoad();
    virtual void onViewWillAppear();
    virtual void onViewDidAppear();
    virtual void onViewWillDisappear();
    virtual void onViewDidDisappear();
    virtual void onViewUnload();
    virtual void onViewDidUnload();

   private:
    void Update();
    void AttachEvent(lv_obj_t* obj) {
        AttachEvent(obj, LV_EVENT_ALL);
    }
    void AttachEvent(lv_obj_t* obj, lv_event_code_t code);
    static void onTimerUpdate(lv_timer_t* timer);
    static void onEvent(lv_event_t* event);

   private:
   DesktopView View;
   DesktopModel Model;
    lv_timer_t* timer;
};

}  // namespace Page

#endif
