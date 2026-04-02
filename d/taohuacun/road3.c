// /d/taohuacun/road3.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set("short","田間小路");
	set("long", @LONG
這裏是小路的盡頭，北方不遠處有間農舍，隱約可見嫋嫋的炊煙升
起。南面望去，一條小路從一畦畦菜田中蜿蜒而遠去。
LONG
);
	set("exits", ([
		"south" : __DIR__"road2",
		"north" : __DIR__"kitchen",
		"west"  : __DIR__"taohua6",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}