// tyroad3.c 石階
// by Marz 

inherit ROOM;

void create()
{
	set("short", "石階");
	set("long", @LONG
這是一條寬大堅實的石階路，不時地有進香客和遊人從你的身邊走
過。抬頭西望，雄偉的三清殿頂浮現在香煙裊繞之中，巍峨壯觀；東邊
一條石階通往山下，隱約可見遠處桃花片片，賞心悅目。
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"west" : __DIR__"tyroad2",
		"eastdown" : __DIR__"tyroad4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2020);
	set("coor/y", -910);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
