// Room: /d/taohua/lantian.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
inherit ROOM;
 
void create()
{
	set("short", "藍天");
	set("long",@LONG
四周是藍藍的天，潔白的雲在飄；地上的行人看起來象螞蟻。哇......
好爽啊。你心中有一種感覺：君臨天下一覽人間小！
LONG);   
	set("outdoors", "taohua");
	set("no_clean_up", 0);
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
