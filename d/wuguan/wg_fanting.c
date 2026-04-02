// wg_fanting.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "飯廳");
	set("long", @LONG
這裏是武館內用餐的地方。屋裏佈置很簡單, 只擺着幾張桌椅幾個
人在一聲不響地喫着。一個廚子在不停的忙碌着，你可以向他要食物和
水。看着可口的飯菜，你忍不住也想叫(order)一份。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_shilu-4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 41);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_order","order");
}

int do_order(string arg)
{
	object me=this_player();
	object food;
	object water;

	if (arg) return notify_fail("這樣東西這裏沒有啊。\n");
	if ((present("bowl",this_player()) || present("rice",this_player())))
		message_vision("廚子衝出來，瞪了$N一眼：“還沒喫完又想要！”\n", me);
	else
	{
		message_vision("廚子連忙從廚房出來，把一碗米飯和一碗水拿了給$N。\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/bowl");
		food->move(me);
		water->move(me);
	}
	return 1;
}

int valid_leave(object me,string dir)
{
	me=this_player();

	if(( dir=="south" ) && (present("bowl",this_player()) ||
		present("rice",this_player())))
		return notify_fail("廚子說道：食物和飲水不能帶出膳堂去。\n");
	return ::valid_leave(me,dir);
}
