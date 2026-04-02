// smallbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("小鐵盒", ({"small box", "box"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        	set("long",
"這隻盒子小得多，只一尺見方。盒中一張箋上寫道：“君
是忠厚仁者，葬我骸骨，當酬以重寶祕術。大鐵盒開啓時
有毒箭射出，愈中書譜地圖均假，上有劇毒，以懲貪慾惡
徒。真者在此小鐵盒內。”\n");
        	set("unit", "只");
        	set("open_count", 1);
        	set("weight", 1000);
        }
}

void init()
{
        add_action("do_open","open");
}

int do_open()
{
return notify_fail("鐵盒已經被別人打開過了。\n");
}
