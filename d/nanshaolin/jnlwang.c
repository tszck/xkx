// Room: /d/nanshaolin/jnlwang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "緊那羅王殿");
	set("long", @LONG
大殿正中供奉着緊那羅王的三座塑像。四周的牆壁上繪滿了西方勝
境，四十八願，二十四尊天的壁畫，構圖宏偉，色彩絢麗，線條流暢，
畫工精細。殿中有幾名香客正在頂禮膜拜。
LONG );

	set("exits", ([
		"west" : __DIR__"pingtai",
	]));
	set("objects",([
		WEAPON_DIR+"hammer/muchui" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6210);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



