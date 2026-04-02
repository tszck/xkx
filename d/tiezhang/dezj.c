// Room: /d/tiezhang/dezj.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
	set("short", HIG"第二指節"NOR);
	set("long", @LONG
這裏已到了中指峯的半山腰了，由於鐵掌山排列得象手指一樣，每
座山峯又分三截，就如手指的指節一般，因此這裏正是位於第二指節的
位置。這裏離峯頂已近，透過淡淡的雲霧，似已可以看到山路的盡頭了。
左前方二十於丈處，黑黝黝的似有一個洞穴(dong)，洞口砌以玉石，修
建得極是齊整。
LONG	);
	set("exits", ([ /* sizeof() == 3 */
		"south"   : __DIR__"sslin5",
		"enter"   : __DIR__"dong1",
		"northup" : __DIR__"shanlu8",
	]));
	set("objects", ([
		__DIR__"npc/mayi" : 2,
	]));
	set("item_desc", ([ 
		"dong" : "一個黑黝黝的山洞。黑暗中偶爾有幾點磷光閃過，好嚇人！！！\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1800);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	if(dir == "enter" && objectp(present("mayi zhanglao", environment(me))))
		return notify_fail("麻衣長老喝道：此乃鐵掌幫禁地，任何人不得入內，否則有死無生！！\n");

	return ::valid_leave(me, dir);
}
