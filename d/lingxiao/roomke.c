// Room: /d/lingxiao/roomke.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG
這裏是柯萬仞的房間。柯萬仞喜歡收集武器，房間四壁都掛滿了形
形色色的刀劍，從倭刀到西洋劍，應有盡有。牀邊還掛了一柄奇怪的東
西，聽說是前年從西域來的番人送給他的火槍。據說老爺子想試試這家
夥的威力，結果在牀上躺了一個月。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang2", 
	]));
	set("objects", ([  
		CLASS_D("lingxiao")+"/ke" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8860);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

