// Room: /d/lingxiao/houyuan1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","後園");
	set("long",@LONG 
這裏是凌霄派的後園。小橋流水，菏塘低閣。層臺聳翠，上出重霄。
飛閣流丹，下臨無地。在這萬裏雪山之上，象這種溫暖如春的地方，實
不多見，也難怪當年凌霄祖師要建派於此了。菏塘中的一方假山上，一
縷清泉汩汩流出，霧氣藹藹，如夢如幻。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"houyuan2",  
		"south"  : __DIR__"zhongting", 
	]));
	set("objects",([ /* sizeof() == 1 */
		CLASS_D("lingxiao")+"/first" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8860);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

