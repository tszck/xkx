// Room: /city/chanzhixf.c

inherit ROOM;

void create()
{
	set("short", "廂房");
	set("long", @LONG
這是一間小廂房。是廟裏的火工和尚等人休息的地方，裏面隨隨便
便地鋪了幾張席子，窗戶上都遮了不透光的紙，廂房裏的光線暗得不得
了，不過，大殿上的誦經聲倒是不時地傳來。
LONG );
	set("exits", ([
		"west"  : __DIR__"chanzhidadian",
	]));
	set("objects", ([
		__DIR__"npc/huogongseng": 1,
	]));
	set("coor/x", -19);
	set("coor/y", -8);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}