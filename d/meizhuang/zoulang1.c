// /d/meizhuang/zoulang1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
這是一條長長的走廊，走廊兩邊是四位莊主中的其他三位平時休息
和練功的地方，這裏的左邊是書室，右邊是畫室，三莊主禿筆翁和四莊
主丹青生在閒來無事的時候，便到那裏面去揮毫，潑墨。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"shushi",
		"east"  : __DIR__"huashi",
		"north" : __DIR__"zoulang2",
		"south" : __DIR__"neiyuan",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
