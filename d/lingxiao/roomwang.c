// Room: /d/lingxiao/roomwang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
這裏與其説是一間臥室，不如説是一間練功室。地上鋪滿了渾圓的
黃豆，怎麼也站不住。室內立了八根梅花樁，一名身掛披風的男子正在
上面縱躍如飛，看得人眼花繚亂。他正是凌霄城的六代弟子汪萬翼。他
的輕功卓絕，在凌霄城數一數二，甚至與白自在不相上下，誰也不知道
他是怎麼學上來的，也許可以向他問問這件事。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang1", 
	]));
	set("objects", ([  
		__DIR__"npc/wang1" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

