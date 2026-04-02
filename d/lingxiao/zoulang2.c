// Room: /d/lingxiao/zoulang2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","走廊");
	set("long",@LONG 
這是一條安靜的走廊。上下都是凌霄弟子的居所，北邊是柯萬仞的
居室，最近似乎忙着收徒弟。南邊是凌霄城的物資室，由張萬風主管。
東邊是個廚房，飄來一陣陣飯菜的香味。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"cook",
		"west"  : __DIR__"zhongting",
		"north" : __DIR__"roomke",  
		"south" : __DIR__"roomzhang", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

