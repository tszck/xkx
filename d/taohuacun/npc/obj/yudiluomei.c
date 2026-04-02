#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIM "玉笛誰家聽落梅" NOR, ({"yudiluomei"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗香氣濃鬱的炙牛肉條，每條牛肉都是由四條小肉條拼成。\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 10);
                set("food_supply", 100);
                set("cook_msg", "
$N取大小相等的羊羔坐臀、小豬耳朵、小牛腰子、獐腿肉加免肉，
分別反覆捶打，至軟爛，去其筯膜，取四樣肉條小心翼翼地合拼
成玉笛狀，置於小火上烤。\n\n");                
        }
}
