//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "古廟");
	set("long", @LONG
這古廟地處荒僻，年久失修，廟內也無廟祝和尚。神案上滿是灰塵
積垢，卻有枝粗大的蠟燭(lazhu)放在案上。
LONG );
	set("item_desc", ([
		"lazhu": "一枝粗大的蠟燭，燭淚似乎頗爲新鮮，好象剛有人點過。\n"
	]) );
	set("exits", ([
		"east" : __DIR__"shangang2",
	]));
	set("objects", ([
		__DIR__"obj/foxiang" : 1,
	]));
	set("coor/x", -1500);
	set("coor/y", -2058);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_dian", "dian");
	add_action("do_dian", "fire");
	add_action("do_open", "qiao");
	add_action("do_open", "open");
}

int do_dian(string arg)
{
 
	object me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="lazhu" )
	{
		if (! objectp(present("tangshi jianpu", me)))
			return notify_fail("你想點蠟燭幹嘛！\n");
	message("vision", me->name()+"把蠟燭點了起來，突然發現佛像後面有個暗門耶！！\n", environment(me));
		me->set_temp("marks/lazhu", 1);
		return 1;
	}
	else 
		return notify_fail("你想要點什麼？\n");
}
int do_open(string arg)
{
	object foxiang, obj, me = this_player();

	if (!objectp(foxiang = present("dafo xiang", this_object())))
		return notify_fail("奇怪，佛像不見了！\n");
	if (foxiang->query("opened"))
		return notify_fail("佛像暗門早給人家打開了！\n");
	if (me->query_temp("marks/lazhu") )
	{
		message("vision", me->name() + "奮力去撬暗門。撬得幾下，那暗門漸漸鬆了。"+me->name()+"伸手指將暗門輕輕起了出來，舉燭一照，只見佛像肚裏珠光寶氣，靄靄浮動，不知這個大肚子之中，藏了有多少珍珠寶貝。\n", environment(me) );
		me->delete_temp("marks/lazhu");
		obj = new("/d/city/obj/goldring");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/necklace");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang); 
		foxiang -> set("opened", 1); 
		return 1;
	}
        else {
		write("黑呼呼的你想幹什麼？！\n");
		return 1;
        }
}