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
  object ob, me = this_player();
  object ob1 ;
  ob1 = new(__DIR__"smallbox1");
  ob1 -> move(me);
	ob = new("/clone/book/jinshe1");
	if (ob->violate_unique())
	{
		destruct(ob);
		destruct(this_object());
		return notify_fail("鐵盒已經被別人打開過了。\n");
	}
  message_vision(HIR 
"$N伸手打開鐵盒，盒子裏有一本書，上寫《金蛇祕笈》四字，用
鉗子揭開數頁，見寫滿密密小字，又有許多圖畫。有的是地圖，
有的是武術姿勢，更有些兵刃機關的圖樣。\n" NOR, this_player());
  add("open_count", -1);
  ob -> move(me);
 	destruct(this_object());
  return 1;
}
