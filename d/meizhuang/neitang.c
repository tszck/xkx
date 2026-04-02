// /d/meizhuang/neitang.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "偏房"); 
	set("long", @LONG
這是一間沒有任何東西的房子，四壁空蕩蕩的，好象是一間剛修好
的，還沒有來得及進行裝飾的房間，正中的牆似乎連石灰漿都沒有塗抹
好，胡亂貼了幾張不知是誰的畫稿。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"senlin1",
	]));

	set("no_clean_up", 0);
	set("item_desc", ([
		"wall": "一壁新牆。\n"
	]) ); 
	set("coor/x", 3490);
	set("coor/y", -1400);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_push", "push");
}
int do_push(string arg)
{
 
	object me=this_player();

	if( !arg || arg=="" ) {write("你想推什麼？\n");return 1;}

	if( arg=="wall" || arg=="牆" )
	{
		write("你使勁推了一下那堵新牆，牆壁居然悄然旋開。\n");
		if((int)me->query_skill("force",1)>=100)
		{
			write("順着牆壁旋開的夾縫，你進到裏面的密室。\n");
			me->move(__DIR__"mishi");
			return 1;
		}
		write("你試着推了一下牆壁，但什麼都沒有發生。\n");

		me->add("jing",-10);
		me->add("qi",-10);
		return 1;

	}
}