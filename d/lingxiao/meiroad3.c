// Room: /d/lingxiao/meiroad3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
	set("short","梅道");
	set("long",@LONG
這裏種滿了綠梅。站在這裏，似乎看到了在凌霄城永遠不可能看到
的春天一樣。一陣微風吹來，在綠梅的海洋中蕩起一陣漣漪，同時將那
股浸人心脾的素香，送到每個人的心中。東邊就是凌霄城的觀景勝地戲
梅亭了。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"meiroad1",
		"east"  : __DIR__"ting",
	]));
	set("objects", ([ 
		__DIR__"obj/ban" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
}

void init()
{
	add_action("do_pick","pick");
}
int do_pick(string arg)
{
	object ob, me = this_player();

	if (!arg || arg!="hua" && arg!="flower")
		return notify_fail("你要摘什麼？\n");
	ob=new(__DIR__"obj/mei");
	ob->move(me);
	message_vision("$N從路旁的樹上摘了一朵"+ob->query("name")+"。\n"NOR,me);
	return 1;
}

