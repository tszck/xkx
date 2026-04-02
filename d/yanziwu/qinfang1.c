//ROOM: /d/yanziwu/qinfang1.c

inherit ROOM;

void create()
{
	set("short", "沁芳閣");
	set("long",@LONG
這裏是供慕容世家的僕人小憩的地方，三面臨水。微風拂過，送來
縷縷的荷花葉香，沁人心脾，沁芳閣因此而名。一架墨綠色的竹梯通向
樓上的休息室。
LONG );
	set("exits", ([
		"east"  : __DIR__"yimen",
		"up"    : __DIR__"qinfang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}