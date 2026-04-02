// Room: /d/lingxiao/zhongting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","中庭");
	set("long",@LONG 
這裏是凌霄城的中庭，左右都是凌霄弟子的住所。白自在對諸弟子
要求嚴厲。所以凌霄弟子平時除練劍習武外，無事之時往往便在房中研
讀劍經拳譜，不敢稍有懈怠。 
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"zoulang1",
		"east"  : __DIR__"zoulang2",
		"north" : __DIR__"houyuan1",  
		"south" : __DIR__"qianyuan", 
	]));	
	set("objects",([
		__DIR__"npc/bao" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

