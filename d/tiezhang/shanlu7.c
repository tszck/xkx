// Room: /d/tiezhang/shanlu7.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

string look_dazi();

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一條崎嶇的山路上，道旁山峯壁立，長草過腰，中間一條羊
腸小路，僅容一人勉強過去。前面有一片茂密的松林。路旁的石壁上刻
着幾個大字(dazi)。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"sslin1",
		"southdown" : __DIR__"shanlu6",
	]));
	set("item_desc",([
		"dazi" : (: look_dazi :),
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1890);
	set("coor/z", 70);
	setup();
}

string look_dazi()
{
        return
        "\n"
"    鐵掌幫重地    \n"    
        "\n"
 "    擅入者----    \n"
RED"              死！    \n"NOR
        "\n";
}