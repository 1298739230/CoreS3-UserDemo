#include "Desktop.h"

using namespace Page;

Desktop::Desktop() : timer(nullptr) {
}

Desktop::~Desktop() {
}

void Desktop::onCustomAttrConfig() {
    LV_LOG_USER(__func__);
    // SetCustomCacheEnable(true);
    // SetCustomLoadAnimType(PageManager::LOAD_ANIM_OVER_BOTTOM, 1000,
    // lv_anim_path_bounce);
}

void Desktop::onViewLoad() {
    LV_LOG_USER(__func__);
    View.Create(_root);

    
    for (size_t i = 0; i < 9; i++) {
        AttachEvent(View.ui.imgbtn_list[i], LV_EVENT_CLICKED);
    }

}

void Desktop::onViewDidLoad() {
    LV_LOG_USER(__func__);
}

void Desktop::onViewWillAppear() {
    LV_LOG_USER(__func__);
    Param_t param;
    param.time  = 1000;

    timer = lv_timer_create(onTimerUpdate, param.time, this);
}

void Desktop::onViewDidAppear() {
    LV_LOG_USER(__func__);
}

void Desktop::onViewWillDisappear() {
    LV_LOG_USER(__func__);
}

void Desktop::onViewDidDisappear() {
    LV_LOG_USER(__func__);
    lv_timer_del(timer);
}

void Desktop::onViewUnload() {
    LV_LOG_USER(__func__);
}

void Desktop::onViewDidUnload() {
    LV_LOG_USER(__func__);
}

void Desktop::AttachEvent(lv_obj_t* obj, lv_event_code_t code) {
    lv_obj_set_user_data(obj, this);
    lv_obj_add_event_cb(obj, onEvent, code, this);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}

void Desktop::Update() {

}

void Desktop::onTimerUpdate(lv_timer_t* timer) {
    Desktop* instance = (Desktop*)timer->user_data;

    instance->Update();
}

void Desktop::onEvent(lv_event_t* event) {
    Desktop* instance = (Desktop*)lv_event_get_user_data(event);
    LV_ASSERT_NULL(instance);

    lv_obj_t* obj        = lv_event_get_current_target(event);
    lv_event_code_t code = lv_event_get_code(event);

    if (code == LV_EVENT_CLICKED) {
        if (obj == instance->View.ui.imgbtn_list[2]) {
            USBSerial.println("HomeMenu -> AppMic");
            instance->_Manager->Replace("Pages/AppMic");
            return;
        }
        USBSerial.print("HomeMenu -> ");
        M5.Speaker.playWav((const uint8_t*)ResourcePool::GetWav("select_0_5s"),
                           ~0u, 1, 1);
        if (obj == instance->View.ui.imgbtn_list[0]) {
            USBSerial.println("AppWiFi");
            instance->_Manager->Replace("Pages/AppWiFi");
        } 
    #if defined(M5CORES3)
        else if (obj == instance->View.ui.imgbtn_list[1]) {
            USBSerial.println("AppCamera");
            instance->_Manager->Replace("Pages/AppCamera");
        }else if (obj == instance->View.ui.imgbtn_list[4]) {
            USBSerial.println("AppIMU");
            instance->_Manager->Replace("Pages/AppIMU");
        }  
    #elif defined(M5CORES3SE)

    #endif
        
        else if (obj == instance->View.ui.imgbtn_list[3]) {
            USBSerial.println("AppPower");
            instance->_Manager->Replace("Pages/AppPower");
        } else if (obj == instance->View.ui.imgbtn_list[5]) {
            USBSerial.println("AppSD");
            instance->_Manager->Replace("Pages/AppSD");
        } else if (obj == instance->View.ui.imgbtn_list[6]) {
            USBSerial.println("AppTouch");
            instance->_Manager->Replace("Pages/AppTouch");
        } else if (obj == instance->View.ui.imgbtn_list[7]) {
            USBSerial.println("AppI2C");
            instance->_Manager->Replace("Pages/AppI2C");
        } else if (obj == instance->View.ui.imgbtn_list[8]) {
            USBSerial.println("AppRTC");
            instance->_Manager->Replace("Pages/AppRTC");
        }
    }

}
