// Room: /d/tiezhang/shishi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
這是一間在山腹中鑿成的小石屋，中間有一座石桌，桌上擺放着一
盞油燈，散發出暗淡昏黃的光亮。屋內一角的地上，鋪着很多幹草，上
面坐着一個人。長髮垂下，遮去面容，看不出多大年紀，身上穿着一件
又髒又破的黑衣，說不出的詭異神祕。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"eastup" : __DIR__"shijie3",
	]));
	set("objects", ([
		CLASS_D("tiezhang")+"/shangguan" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", -2050);
	set("coor/y", 1870);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
