
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "金錢肉" NOR, ({"jqrou"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盤色香俱佳的金錢肉。\n");
                set("unit", "盤");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
                set("cook_msg", "
$N將豬腿肉片成薄片，每兩片留一邊不斷；再將豬肥膘切成一兩塊
像銀元大小的圓塊子，一起放入用醬油、糖、五香粉 、酒調成的滷
內滾一滾，再放着醃約二十分鐘。然後將 矸 膘一塊塊地夾入沒有片
斷的腿肉片中，並用銀籤將夾好的肉穿成一串。再抹上幹菱粉。最後
開熱豬油鍋，將穿好的肉片放入鍋內炸熟，再一片片地從銀簽上取下
來，整齊地裝在盤中。\n\n"
		);                
        }
}
