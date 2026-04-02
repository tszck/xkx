// Room: /d/tiezhang/wmfeng.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
void close_passage();
string look_bei();

void create()
{
	set("short", GRN"無名峯"NOR);
	set("long", @LONG
跨過路上的荊棘和荒草，你終於登上了無名峯的峯頂。由於這裏地
處五峯之中，四周有其它山峯阻擋，因此風勢很小，常年籠罩在一片雲
霧之中。峯頂長滿了齊腰的荒草，怪石嶙峋，一片荒涼景色。在峯頂的
正中，赫然矗立着一座岩石砌就的墳墓，墳墓的前面立着一塊一人多高
的花崗巖的墓碑(bei)。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"hclu4",
	]));
	set("item_desc",([
		"bei" : (: look_bei :),
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2060);
	set("coor/y", -1860);
	set("coor/z", 80);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
	object me=this_player();

	if ((int)this_player()->query_temp("marks/鬧1")) 
	{
		if ( (int)me->query_str() < 30)
			return notify_fail("你的力量不夠，無法將石碑推開。\n");
		if (arg !="bei") 
			return notify_fail("你要推什麼？？\n");
		write("你紮下馬步，深深的吸了口氣，將墓碑緩緩的向旁推開。\n");
		message("vision", me->name() + "雙膀用力，將墓碑向旁緩緩推開，下面露出一個黑洞洞的入口。\n", environment(me), ({me}) );
		set("exits/enter", __DIR__"shijie1");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
		return 1;
	}
	return notify_fail("你有病呀！沒事推墓碑做什麼？？\n");
}

void close_passage()
{
	object room;

	if( !query("exits/enter") ) return;
	message("vision", "墓碑發出隆隆的聲音，緩緩移回原處。\n", this_object() );
	delete("exits/enter");
}

string look_bei()
{
    return
    "\n"
 "*****************\n"
 "*           鐵  *\n"
 "*           掌  *\n"
 "*           幫  *\n"
 "*       上  第  *\n"
 "*           十  *\n"
 "*       官  三  *\n"
 "*           代  *\n"
 "*       劍  幫  *\n"
 "*           主  *\n"
 "*   不  南      *\n"
 "*   肖          *\n"
 "*   弟          *\n"
 "*   子  之      *\n"
 "*   裘  墓      *\n"
 "*   千          *\n"
 "*   仞          *\n"
 "*   謹          *\n"
 "*   立          *\n"
 "*****************\n";
    "\n";
}