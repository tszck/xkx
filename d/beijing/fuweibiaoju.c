// Room: /beijing/fuweibiaoju.c

inherit ROOM;

void create()
{
	set("short", "福威鏢局北京分局");
	set("long", @LONG
朱漆大門上茶杯大小的銅釘閃閃發光，門頂的匾額寫着“福威鏢局
”四個金漆大字，下面橫書“北京分號”四個小字。門內是兩排長凳，
分坐八名勁裝漢子，個個腰板筆挺，顯出一股英悍之氣。
LONG );

	set("exits", ([
		"north" : __DIR__"dongcha1",
	]));
	set("objects", ([
		"/d/fuzhou/npc/yi" : 1,
	]));
	set("coor/x", -190);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
