// Room: /d/kunlun/kuhanlou2.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void init();
int do_duanmo(string arg);

void create()
{
	set("short", "苦寒樓二層");
	set("long", @LONG
每個樓層上都鋪設了結實的木樓板，八角形的牆身上則開了四扇大
窗。四周牆壁貼着崑崙派歷代掌門和高手的畫像，並有專門的文字記載
着他們的事蹟。從這裏往外眺望，只能看到圍繞塔周的密密匝匝的雲杉
林，正是通過這種忍飢耐寒，清心寡慾的辦法以求得對武學孜孜不倦的
追求。
LONG );
	set("exits", ([
		"up"   : __DIR__"kuhanlou3",
		"down" : __DIR__"kuhanlou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -119980);
	set("coor/y", 40130);
	set("coor/z", 100);
	setup();
}

void init()
{
	set("times", random(20));
	set("item_count", 2);

	add_action("do_duanmo", "duanmo");
	add_action("do_duanmo", "see");
}

int do_duanmo(string arg)
{
	object ob, me = this_player();

	if ( (int)me->query("kar") < 20 )
		return notify_fail("你要幹什麼？\n");

	if ( !arg && (arg != "huaxiang") && (arg != "wall") )
		return notify_fail("你想要端摩什麼東西？\n");

	if ( query("item_count") < 1 ||
		me->query_temp("count", 1) <= query("times") )
	{
		me->add_temp("count", 1);
		me->receive_damage("jing", 10);
		me->receive_damage("qi", 10);
		return notify_fail("你仔細端摩崑崙派前輩高人的畫像，想象他們當年縱橫江湖，快意恩仇，不由心中生出許多感慨。\n");
	}

	if ( query("item_count") > 0)
		switch( random(2) )
		{
			case 0:
				add("item_count", -1);
				ob = new("/d/kunlun/obj/weiqi");
				ob->move(me);
				ob->delete_temp("count");
				break;
			case 1:
				add("item_count", -1);
				ob = new("/d/kunlun/obj/guzheng");
				ob->move(me);
				ob->delete_temp("count");
				break;
		}
	return 1;
}

int valid_leave(object me, string dir)
{

	if (dir == "up" ) me->add_temp("count", 1);
	else me->add_temp("count", -1);
	return ::valid_leave(me, dir);
}
