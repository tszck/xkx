// Room: /d/tiezhang/hhyuan3.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"假山"NOR);
	set("long", @LONG
你面前矗立着一座巨大的假山，一道片練也似的銀瀑從假山邊瀉將
下來，注入前面的一座大池塘中，池塘底下想是另有瀉水通道，是以塘
水卻不見滿溢。鐵掌幫為建這個花園，也不知花費了多少人力、物力。
瀑布的後面似乎隱約有個小門。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"hhyuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2050);
	set("coor/y", -1940);
	set("coor/z", 30);
	setup();
}
void init()
{
         add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();

        if (arg !="瀑布") 
        return notify_fail("你要往哪兒跳？？\n");
        {
		write("你縱身向瀑布裏躍去。\n");
		message("vision", me->name() + "身行一閃突然不見了。\n", environment(me), ({me}) );
		me->move(__DIR__"mishi");
		message("vision",me->name()+"走了過來。\n",environment(me),({me}) );
	}
        return 1;
}