// Room: /d/lingxiao/meiroad1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
	set("short","梅道");
	set("long",@LONG
這是一條充滿了梅花清香的大道。往北就是凌霄城的大殿凌霄殿了。
聞着滿天的梅香，本以爲這裏種滿了梅樹，走近卻纔發現，這裏只有兩
棵合圍粗的白梅，開着漫天的冰凌。其實，是梅還是雪，已分不清了。
看到這種情況，“梅須遜雪三分白，雪卻輸梅一段香”的話，是誰也不
會信了。這梅、這雪，誰白，誰香，分得出來嗎？
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"iceroad3",
		"enter" : __DIR__"dadian",
		"west"  : __DIR__"meiroad2",
		"east"  : __DIR__"meiroad3",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
		__DIR__"obj/ban" : 1,
	]));
	set("coor/x", -31000);
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

