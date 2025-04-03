#include <stdarg.h>
#include <stdio.h>
#include "DesktopView.h"

using namespace Page;



LV_IMG_DECLARE(menu_wifi);

#if defined(M5CORES3)
    LV_IMG_DECLARE(menu_cam);
#elif defined(M5CORES3SE)
    LV_IMG_DECLARE(menu_cam_se);
#endif

LV_IMG_DECLARE(menu_mic);
LV_IMG_DECLARE(menu_power);

#if defined(M5CORES3)
    LV_IMG_DECLARE(menu_imu);
#elif defined(M5CORES3SE)
    LV_IMG_DECLARE(menu_imu_se);
#endif
LV_IMG_DECLARE(menu_sd);
LV_IMG_DECLARE(menu_touch);
LV_IMG_DECLARE(menu_i2c);
LV_IMG_DECLARE(menu_sys);

static const lv_img_dsc_t* menu_img_pressed_list[] = {
    &menu_wifi,
#if defined(M5CORES3)
    &menu_cam,
#elif defined(M5CORES3SE)
    &menu_cam_se,
#endif
    &menu_mic,
    &menu_power,
#if defined(M5CORES3)
    &menu_imu,
#elif defined(M5CORES3SE)
    &menu_imu_se,
#endif
    &menu_sd,
    &menu_touch,
    &menu_i2c,
    &menu_sys,
};


void DesktopView::Create(lv_obj_t* root) {

    //Write codes screen_tileview_1
    ui.screen_tileview_1 = lv_tileview_create(root);
    ui.screen_tileview_1_tile1 = lv_tileview_add_tile(ui.screen_tileview_1, 0, 0, LV_DIR_RIGHT);
    ui.screen_tileview_1_tile2 = lv_tileview_add_tile(ui.screen_tileview_1, 1, 0, LV_DIR_LEFT);
    lv_obj_set_pos(ui.screen_tileview_1, 0, 0);
    lv_obj_set_size(ui.screen_tileview_1, 320, 240);
    lv_obj_set_scrollbar_mode(ui.screen_tileview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_tileview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui.screen_tileview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui.screen_tileview_1, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui.screen_tileview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui.screen_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui.screen_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_tileview_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui.screen_tileview_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui.screen_tileview_1, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui.screen_tileview_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui.screen_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_img_1
    #if defined(M5CORES3)
    ui.img_bg = lv_img_create(ui.screen_tileview_1_tile1);
    lv_obj_add_flag(ui.img_bg , LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui.img_bg , ResourcePool::GetImage("menu_bg"));
    lv_img_set_pivot(ui.img_bg, 50,50);
    lv_img_set_angle(ui.img_bg, 0);
    lv_obj_set_pos(ui.img_bg, 0, 0);
    lv_obj_set_size(ui.img_bg, 320, 240);
 
    //Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui.img_bg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui.img_bg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui.img_bg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui.img_bg, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    #elif defined(M5CORES3SE)
    ui.img_bg_se = lv_img_create(ui.screen_tileview_1_tile1);
    lv_obj_add_flag(ui.img_bg_se , LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui.img_bg_se , ResourcePool::GetImage("menu_bg_se"));
    lv_img_set_pivot(ui.img_bg_se, 50,50);
    lv_img_set_angle(ui.img_bg_se, 0);
    lv_obj_set_pos(ui.img_bg_se, 0, 0);
    lv_obj_set_size(ui.img_bg_se, 320, 240);
 
    //Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui.img_bg_se, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui.img_bg_se, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui.img_bg_se, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui.img_bg_se, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    #endif


    for (size_t i = 0; i < 8; i++)
    {
        ui.imgbtn_list[i] = lv_imgbtn_create(ui.screen_tileview_1_tile1);
        // lv_obj_remove_style_all(ui.imgbtn_list[i]);
        lv_obj_set_size(ui.imgbtn_list[i], 60, 73);
        lv_obj_set_pos(ui.imgbtn_list[i], 10 + 80 * (i % 4), 75 + 80 * (i / 4));


        lv_imgbtn_set_src(ui.imgbtn_list[i], LV_IMGBTN_STATE_PRESSED, NULL, menu_img_pressed_list[i], NULL);
        lv_imgbtn_set_src(ui.imgbtn_list[i], LV_IMGBTN_STATE_RELEASED, NULL, menu_img_pressed_list[i], NULL);

        // lv_obj_set_style_border_color(ui.imgbtn_list[i], lv_color_hex(0xff00ff), 0);
        // lv_obj_set_style_border_side(ui.imgbtn_list[i], LV_BORDER_SIDE_FULL, 0);
        // lv_obj_set_style_border_width(ui.imgbtn_list[i], 1, 0);
        // lv_obj_set_style_radius(ui.imgbtn_list[i], 0, 0);
        // lv_obj_set_style_border_post(ui.imgbtn_list[i], true, 0);
    }  
    
    ui.imgbtn_list[8] = lv_imgbtn_create(ui.screen_tileview_1_tile1);
    lv_obj_set_size(ui.imgbtn_list[8], 60, 73);
    lv_obj_set_pos(ui.imgbtn_list[8], 250, 10);

    lv_imgbtn_set_src(ui.imgbtn_list[8], LV_IMGBTN_STATE_PRESSED, NULL, menu_img_pressed_list[8], NULL);
    lv_imgbtn_set_src(ui.imgbtn_list[8], LV_IMGBTN_STATE_RELEASED, NULL, menu_img_pressed_list[8], NULL);


 
}

void DesktopView::Delete() {
}