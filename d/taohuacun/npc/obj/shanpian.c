
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "爆炒鱔片" NOR, ({"shanpian"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盤香脆的爆炒鱔片。\n");
                set("unit", "盤");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N將鱔魚平放在砧板上，用竹籤沿肚皮劃開二片，去背骨，
去皮，去尾， 用潔淨布揩乾，不要用水洗，以免影響鮮味，
然後切成荷葉片。再開旺火熱豬油鍋，將鱔魚片放下去脆，
倒出，濾去油。在鍋內另加少許豬油燒熱，將大蒜頭拍碎，
倒入鍋內炒香，加清湯、菱粉、鹽、勾好芡，再將鮮片倒
入略炒，澆上麻油，撒上胡椒粉。\n\n"
		);                
        }
}
